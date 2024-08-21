// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_UMMaster.h"

#include "AIController.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "Actors/AmmoPack.h"
#include "Actors/Gun.h"
#include "Actors/HealthPack.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Controllers/ShooterAIController.h"
#include "GameMode/SimpleShooterGameModeBase.h"
#include "Kismet/GameplayStatics.h"

UBTService_UMMaster::UBTService_UMMaster()
{
	NodeName = TEXT("UM Master");
}

void UBTService_UMMaster::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if (CurrentWorldPtr == nullptr) CurrentWorldPtr = GetWorld();
	OwnerCompPtr = &OwnerComp;

	if (OwnerCompPtr != nullptr && CurrentWorldPtr != nullptr)
	{
		//initiate blackboard value
		if (!bInitiated)
		{
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), 9999999.9f); // Service - StimulusUpdate
			bInitiated = true;	
		}
		
		APawn* EnemyActor = GetEnemyActor();// Service - StimulusUpdate
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("EnemyInSight"), EnemyActor);// Service - StimulusUpdate
		if (EnemyActor != nullptr)
		{
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsVector(FName("LastKnownEnemyLocation"), EnemyActor->GetActorLocation());// Service - StimulusUpdate
		}

		OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("SelectedFleePoint"), GetClosestValidFleePoint()); // Service - SelectFleePoint
		if (EnemyActor != nullptr)
		{
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), 0.0f); // Service - StimulusUpdate
		}
		else
		{
			float TimeRegistered = OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("TimeSeenAnEnemy")); // Service - StimulusUpdate
			TimeRegistered += DeltaSeconds;
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), TimeRegistered); // Service - StimulusUpdate
		}

		if (DefaultEnumState == EAIStateEnum::None)
		{
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsEnum(FName("State"), ChooseState());
		}
		else
		{
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsEnum(FName("State"), DefaultEnumState);
		}
	}
}

APawn* UBTService_UMMaster::GetEnemyActor()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (OwnerCompPtr->GetAIOwner()->LineOfSightTo(PlayerPawn))
	{
		FVector EyesLocation;
		FRotator EyesRotation;
		OwnerCompPtr->GetAIOwner()->GetActorEyesViewPoint(EyesLocation, EyesRotation);

		const FVector EyesForward = EyesRotation.Vector();
		FVector EyesToPlayer = PlayerPawn->GetActorLocation() - EyesLocation;
		EyesToPlayer.Normalize();

		//vision cone
		// factor of 0 to 1, 0 = 180 degree vision, 1 = 0 degree vision, 0.5 = 90 (45 split from the middle)
		if (FVector::DotProduct(EyesForward, EyesToPlayer) > 0.0f) 
		{
			return PlayerPawn;
		}
		else
		{
			return nullptr;
		}
	}
	
	return nullptr;
}

AWaypoint* UBTService_UMMaster::GetClosestValidFleePoint()
{
	AWaypoint* SelectedFleePoint = nullptr;
	const bool bLastKnownEnemyLocationIsSet = OwnerCompPtr->GetBlackboardComponent()->IsVectorValueSet(FName("LastKnownEnemyLocation"));

	if (!bLastKnownEnemyLocationIsSet)
	{
		return SelectedFleePoint;
	}

	const FVector CharLocation = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation();
	const FVector2D CharLocation2D = FVector2D(CharLocation.X, CharLocation.Y);
	
	const FVector LastKnownEnemyLocation = OwnerCompPtr->GetBlackboardComponent()->GetValueAsVector(FName("LastKnownEnemyLocation"));
	const FVector2D LastKnownEnemyLocation2D = FVector2D(LastKnownEnemyLocation.X, LastKnownEnemyLocation.Y);
	
	ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
	TArray<AWaypoint*> ConsideredWaypoints = GameMode->GetAllWayPoints();

	float HighestDistance = 0.0f;
	for (int i=0; i<ConsideredWaypoints.Num(); i++)
	{
		UNavigationPath* TPath = GetPath(CharLocation, ConsideredWaypoints[i]->GetActorLocation());
		if (TPath != nullptr)
		{
			const FVector FirstPointLocation = TPath->PathPoints[1];
			FVector2D FirstPointLocation2D = FVector2D(FirstPointLocation.X, FirstPointLocation.Y);
			
			FVector2D CharToFirstPoint = FirstPointLocation2D - CharLocation2D;
			CharToFirstPoint.Normalize();

			FVector2D CharToEnemy = LastKnownEnemyLocation2D - CharLocation2D;
			CharToEnemy.Normalize();
			
			//Is the first point on the opposite side of the last known position of the enemy
			const float DotProduct = CharToFirstPoint.Dot(CharToEnemy);
			if (DotProduct < 0.0f)
			{
				const float CurrentPathDistanceFromEnemyPosition = GetPathLength(LastKnownEnemyLocation, ConsideredWaypoints[i]->GetActorLocation());
				if ( CurrentPathDistanceFromEnemyPosition > HighestDistance)
				{
					SelectedFleePoint = ConsideredWaypoints[i];
					HighestDistance = CurrentPathDistanceFromEnemyPosition;
				}
			}
		}
	}
	
	return SelectedFleePoint;
}

TEnumAsByte<EAIStateEnum> UBTService_UMMaster::ChooseState()
{
	const int STATE_ARRAY_SIZE = 5;
	float StateScoreArray[STATE_ARRAY_SIZE];

	//Flee
	StateScoreArray[EAIStateEnum::Flee] = ScoreAggregation(3,
		1.0f *
		FleeC_HealthPercent() *
		FleeC_HaveAValidFleePoint() *
		FleeC_TimeSeenEnemy()
		);

	//LookForHealthPack 
	StateScoreArray[EAIStateEnum::LookForHealthPack] = ScoreAggregation(2,
		1.0f *
		LookForHealthPackC_HealthPercent() *
		LookForHealthPackC_HealthPackDistance()
		);
	
	//LookForAmmo
	StateScoreArray[EAIStateEnum::LookForAmmo] = ScoreAggregation(2,
		1.0f *
		LookForAmmoPackC_AmmoReservePercent() *
		LookForAmmoPackC_AmmoPackDistance()
		);

	//EngagePlayer
	StateScoreArray[EAIStateEnum::EngageEnemy] = ScoreAggregation(4,
		1.0f *
		EngageEnemyC_IsLastKnownEnemyLocationIsSet() *
		EngageEnemyC_TimeSeenEnemy() *
		//EngageEnemyC_AimingPercent() *
		EngageEnemyC_AmmoInGunPercent() *
		EngageEnemyC_HealthPercent()
		);

	//Explore
	StateScoreArray[EAIStateEnum::Explore] = ScoreAggregation(2,
		1.0f *
		ExploreC_EnemyInSight() *
		ExploreC_TimeSeenEnemy()
		);
	
	int HighestScoreIndex = 0;
	float CurrentHighestScore = StateScoreArray[HighestScoreIndex];

	for (int i=1; i<STATE_ARRAY_SIZE; i++)
	{
		if (StateScoreArray[i] > CurrentHighestScore)
		{
			CurrentHighestScore = StateScoreArray[i];
			HighestScoreIndex = i;
		}
	}

	//Debug
	if (bDebugActive)
	{
		for (int i=0; i<STATE_ARRAY_SIZE;i++)
		{
			const FString StateString = UEnum::GetValueAsString(static_cast<EAIStateEnum>(i));
			const FString StateScore = FString::Printf(TEXT("%f"), StateScoreArray[i]);
		
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Orange,*FString::Printf(TEXT("%s : %s"), *StateString, *StateScore));
			UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT("%s : %s"), *StateString, *StateScore));
		}
	
		const FString WiningStateString = UEnum::GetValueAsString(static_cast<EAIStateEnum>(HighestScoreIndex));
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Orange, *FString::Printf(TEXT("wining state is : %s"), *WiningStateString));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT("wining state is : %s"), *WiningStateString));
	
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Orange, TEXT("-------------------"));
		UE_LOG(LogTemp, Warning, TEXT("%s"), TEXT("-------------------"));
	}

	//delete[] &StateScoreArray; // no need to delete it, it is on the stack
	
	//return state
	return static_cast<EAIStateEnum>(HighestScoreIndex);
}

float UBTService_UMMaster::ScoreAggregation(int NbConsiderations, float OriginalScore)
{
	const float modFactor = 1 - (1 / NbConsiderations);
	const float makeupValue = (1 - OriginalScore) * modFactor;
	const float FinalScore = OriginalScore + (makeupValue * OriginalScore);
	
	return FinalScore;
}

float UBTService_UMMaster::FleeC_HealthPercent()
{
	return FlC_HealthPercentCurve.GetRichCurveConst()->Eval(OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("SelfHealthPercent")));
}

float UBTService_UMMaster::FleeC_HaveAValidFleePoint()
{
	return OwnerCompPtr->GetBlackboardComponent()->GetValueAsObject(FName("SelectedFleePoint")) != nullptr ? FlC_HaveAValidFleePointBool.X:FlC_HaveAValidFleePointBool.Y;
}

float UBTService_UMMaster::FleeC_TimeSeenEnemy()
{
	const float TimeSeenAnEnemy = OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("TimeSeenAnEnemy"));
	return FlC_TimeSeenEnemyCurve.GetRichCurveConst()->Eval(FMath::Min(TimeSeenAnEnemy, EEC_MaxTimeSeenAnEnemy)/EEC_MaxTimeSeenAnEnemy);
}

float UBTService_UMMaster::LookForHealthPackC_HealthPercent()
{
	return LFHPC_HealthPercentCurve.GetRichCurveConst()->Eval(OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("SelfHealthPercent")));
}

float UBTService_UMMaster::LookForHealthPackC_HealthPackDistance()
{
	if (OwnerCompPtr->GetAIOwner() == nullptr)
	{
		return 0.0f;
	}

	const AHealthPack* SelectedHealthPack = Cast<AHealthPack>(OwnerCompPtr->GetBlackboardComponent()->GetValueAsObject(FName("SelectedHealthPack")));
	if (SelectedHealthPack == nullptr)
	{
		return 0.0f;
	}
	
	const FVector CharLocation = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation();
	const float CalculatedDistance = FMath::Min(GetPathLength(SelectedHealthPack->GetActorLocation(),CharLocation), MaxDistanceHealthPack);
	
	return LFHPC_HealthPercentCurve.GetRichCurveConst()->Eval(CalculatedDistance/MaxDistanceHealthPack);
}

float UBTService_UMMaster::LookForAmmoPackC_AmmoReservePercent()
{
	return LFAPC_AmmoReservePercentCurve.GetRichCurveConst()->Eval(OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("AmmoInReservePercent")));
}

 float UBTService_UMMaster::LookForAmmoPackC_AmmoPackDistance()
{
	if (OwnerCompPtr->GetAIOwner() == nullptr)
	{
		return 0.0f;
	}

	const AAmmoPack* SelectedAmmoPack = Cast<AAmmoPack>(OwnerCompPtr->GetBlackboardComponent()->GetValueAsObject(FName("SelectedAmmoPack")));
	
	if (SelectedAmmoPack == nullptr)
	{
		return 0.0f;
	}
	
	const FVector CharLocation = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation(); 
	const float CalculatedDistance = FMath::Min(GetPathLength(SelectedAmmoPack->GetActorLocation(),CharLocation), MaxDistanceAmmoPack);

	return LFAPC_AmmoPackDistanceCurve.GetRichCurveConst()->Eval(CalculatedDistance/MaxDistanceAmmoPack);
}

float UBTService_UMMaster::EngageEnemyC_IsLastKnownEnemyLocationIsSet()
{
	const bool bIsSet = OwnerCompPtr->GetBlackboardComponent()->IsVectorValueSet(FName("LastKnownEnemyLocation"));
	return bIsSet ? EEC_IsLastKnownEnemyLocationIsSetBool.X : EEC_IsLastKnownEnemyLocationIsSetBool.Y;
}

float UBTService_UMMaster::EngageEnemyC_TimeSeenEnemy()
{
	const float TimeSeenAnEnemy = OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("TimeSeenAnEnemy"));
	return EEC_TimeSeenEnemyCurve.GetRichCurve()->Eval(FMath::Min(TimeSeenAnEnemy, EEC_MaxTimeSeenAnEnemy)/EEC_MaxTimeSeenAnEnemy);
}

//  float UBTService_UMMaster::EngageEnemyC_AimingPercent()
// {
// 	return EEC_AimingPercentCurve.GetRichCurve()->Eval(1.0f);
// }

float UBTService_UMMaster::EngageEnemyC_AmmoInGunPercent()
{
	return EEC_AmmoInGunPercentCurve.GetRichCurveConst()->Eval(OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("AmmoInGunPercent")));
}

float UBTService_UMMaster::EngageEnemyC_HealthPercent()
{
	return EEC_HealthPercentCurve.GetRichCurveConst()->Eval(OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("SelfHealthPercent")));
}

float UBTService_UMMaster::ExploreC_EnemyInSight()
{
	const AActor* EnemyInSight = Cast<AActor>(OwnerCompPtr->GetBlackboardComponent()->GetValueAsObject(FName("EnemyInSight")));
	return EnemyInSight != nullptr ? ExC_EnemyInSightBool.X : ExC_EnemyInSightBool.Y;
}

 float UBTService_UMMaster::ExploreC_TimeSeenEnemy()
{
	const float TimeSeenAnEnemy = OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("TimeSeenAnEnemy"));
	return ExC_TimeSeenEnemyCurve.GetRichCurve()->Eval(FMath::Min(TimeSeenAnEnemy, ExC_MaxTimeSeenAnEnemy)/ExC_MaxTimeSeenAnEnemy);
}

float UBTService_UMMaster::GetPathLength(const FVector& Start, const FVector& End) const
{
	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(CurrentWorldPtr);
	if (!NavSys) return -1.0f;

	const ANavigationData* NavData = NavSys->GetDefaultNavDataInstance(FNavigationSystem::DontCreate);
	if (!NavData) return -1.0f;

	FNavLocation StartLocation, EndLocation;
	if (NavSys->ProjectPointToNavigation(Start, StartLocation, FVector(500, 500, 500), NavData)
		&& NavSys->ProjectPointToNavigation(End, EndLocation, FVector(500, 500, 500), NavData))
	{
		float PathLength;
		if (NavSys->GetPathLength(StartLocation.Location, EndLocation.Location, PathLength, NavData))
		{
			return PathLength;
		}
	}

	return -1.0f;
}

UNavigationPath* UBTService_UMMaster::GetPath(const FVector& Start, const FVector& End) const
{
	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (!NavSys) return nullptr;

	const ANavigationData* NavData = NavSys->GetDefaultNavDataInstance(FNavigationSystem::DontCreate);
	if (!NavData) return nullptr;
	
	return NavSys->FindPathToLocationSynchronously(GetWorld(), Start, End);
}
