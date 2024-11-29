// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTService_SelectFleeWaypoint.h"

#include "AIController.h"
#include "NavigationPath.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "..\..\..\Public\GameMode\ShooterGameMode.h"
#include "Utility/NavMeshUtility.h"

UBTService_SelectFleeWaypoint::UBTService_SelectFleeWaypoint()
{
	NodeName = TEXT("Select Flee Waypoint");
}

void UBTService_SelectFleeWaypoint::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	if (CurrentWorldPtr == nullptr) CurrentWorldPtr = GetWorld();
	OwnerCompPtr = &OwnerComp;
	
	if (OwnerCompPtr != nullptr && CurrentWorldPtr != nullptr)
	{
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("SelectedFleePoint"), GetClosestValidFleePoint());
	}
}

AWaypoint* UBTService_SelectFleeWaypoint::GetClosestValidFleePoint()
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
	
	AShooterGameMode* GameMode = GetWorld()->GetAuthGameMode<AShooterGameMode>();
	TArray<AWaypoint*> ConsideredWaypoints = GameMode->GetAllWayPoints();

	float HighestDistance = 0.0f;
	int NbValidFleePoint = 0;
	
	for (int i=0; i<ConsideredWaypoints.Num(); i++)
	{
		const AShooterCharacter* AICharacter = Cast<AShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());

		if (AICharacter != nullptr)
		{
			UNavigationPath* TPath = AICharacter->NavMeshUtility->GetPath(CharLocation, ConsideredWaypoints[i]->GetActorLocation(), CurrentWorldPtr);
			if (TPath != nullptr)
			{
				if (TPath->PathPoints.Num() > 0)
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
						NbValidFleePoint++;
						const float CurrentPathDistanceFromEnemyPosition = AICharacter->NavMeshUtility->GetPathLength(LastKnownEnemyLocation, ConsideredWaypoints[i]->GetActorLocation(), CurrentWorldPtr);
						if (CurrentPathDistanceFromEnemyPosition > HighestDistance)
						{
							SelectedFleePoint = ConsideredWaypoints[i];
							HighestDistance = CurrentPathDistanceFromEnemyPosition;
						}
					}
				}
			}
		}
	}
	
	return NbValidFleePoint > 1 ? SelectedFleePoint : nullptr;
}
