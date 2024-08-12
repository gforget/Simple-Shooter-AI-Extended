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
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), 9999999.9f);
			bInitiated = true;	
		}

		OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("SelfHealthPercent"), GetHealthPercent());
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("SelectedHealthPack"), GetClosestHealthPack());
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("AmmoInReservePercent"), GetAmmoReservePercent());
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("SelectedAmmoPack"), GetClosestAmmoPack());
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("AmmoInGunPercent"), GetAmmoInGunPercent());

		APawn* EnemyActor = GetEnemyActor();
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("EnemyInSight"), EnemyActor);
		if (EnemyActor != nullptr)
		{
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsVector(FName("LastKnownEnemyLocation"), EnemyActor->GetActorLocation());
		}

		OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("SelectedFleePoint"), GetClosestValidFleePoint());
		if (EnemyActor != nullptr)
		{
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), 0.0f);
		}
		else
		{
			float TimeRegistered = OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("TimeSeenAnEnemy"));
			TimeRegistered += DeltaSeconds;
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), TimeRegistered);
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

float UBTService_UMMaster::GetHealthPercent()
{
	const AShooterCharacter* AICharacter = Cast<AShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());
	if (AICharacter == nullptr)
	{
		return 0.0f;
	}
	
	return AICharacter->GetHealthPercent();
}

AHealthPack*  UBTService_UMMaster::GetClosestHealthPack()
{
	AHealthPack* SelectedHealthPack = nullptr;
	ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
	if (GameMode == nullptr)
	{
		return SelectedHealthPack;
	}

	TArray<AHealthPack*> ConsideredHealthPacks = GameMode->GetAllHealthPacks();
	const FVector CharLocation = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation(); 

	float HighestDistance = 999999999999.99f;
	
	for (int i=0; i<ConsideredHealthPacks.Num(); i++)
	{
		if (!ConsideredHealthPacks[i]->IsRecharging())
		{
			const float CurrentDistance = GetPathLength(CharLocation, ConsideredHealthPacks[i]->GetActorLocation());
			if (CurrentDistance < HighestDistance)
			{
				SelectedHealthPack = ConsideredHealthPacks[i];
				HighestDistance = CurrentDistance;
			}
		}
	}

	return SelectedHealthPack;
}

float UBTService_UMMaster::GetAmmoReservePercent()
{
	const AShooterCharacter* AICharacter = Cast<AShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());
	if (AICharacter == nullptr)
	{
		return 0.0f;
	}

	return AICharacter->GetAmmoReservePercent();
}

float UBTService_UMMaster::GetAmmoInGunPercent()
{
	const AShooterCharacter* AICharacter = Cast<AShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());
	if (AICharacter == nullptr)
	{
		return 0.0f;
	}
	return AICharacter->GetGunReference()->GetAmmoPercent();
}

AAmmoPack* UBTService_UMMaster::GetClosestAmmoPack()
{
	AAmmoPack* SelectedAmmoPack = nullptr;
	ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
	if (GameMode == nullptr)
	{
		return SelectedAmmoPack;
	}

	TArray<AAmmoPack*> ConsideredAmmoPacks = GameMode->GetAllAmmoPacks();
	const FVector CharLocation = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation(); 

	float HighestDistance = 999999999999.99f;
	
	for (int i=0; i<ConsideredAmmoPacks.Num(); i++)
	{
		if (!ConsideredAmmoPacks[i]->IsRecharging())
		{
			const float CurrentDistance = GetPathLength(CharLocation, ConsideredAmmoPacks[i]->GetActorLocation());
			if (CurrentDistance < HighestDistance)
			{
				SelectedAmmoPack = ConsideredAmmoPacks[i];
				HighestDistance = CurrentDistance;
			}
		}
	}

	return SelectedAmmoPack;
}

APawn* UBTService_UMMaster::GetEnemyActor()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (OwnerCompPtr->GetAIOwner()->LineOfSightTo(PlayerPawn))
	{
		return PlayerPawn;
	}
	else
	{
		return nullptr;
	}
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
			
			// UE_LOG(LogTemp, Warning, TEXT("CharLocation2D : %f, %f"), CharLocation2D.X, CharLocation2D.Y);
			// UE_LOG(LogTemp, Warning, TEXT("FirstPointLocation2D : %f, %f"), FirstPointLocation2D.X, FirstPointLocation2D.Y);
			// UE_LOG(LogTemp, Warning, TEXT("LastKnownEnemyLocation2D : %f, %f"), LastKnownEnemyLocation2D.X, LastKnownEnemyLocation2D.Y);
			// UE_LOG(LogTemp, Warning, TEXT("CharToFirstPoint : %f, %f"), CharToFirstPoint.X, CharToFirstPoint.Y);
			// UE_LOG(LogTemp, Warning, TEXT("CharToEnemy : %f, %f"), CharToEnemy.X, CharToEnemy.Y);
			//
			// UE_LOG(LogTemp, Warning, TEXT("DotProduct CharToFirstPoint.CharToEnemy : %f"), DotProduct);
			// UE_LOG(LogTemp, Warning, TEXT("----------------"));
		}
	}
	
	// if (SelectedFleePoint != nullptr)
	// {
	// 	const FString WiningStateString = SelectedFleePoint->GetActorLabel();
	// 	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Orange, *FString::Printf(TEXT("Fleeing node is : %s"), *WiningStateString));
	// 	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT("Fleeing node : %s"), *WiningStateString));
	// }
	
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
