// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_ChooseWaypoint.h"
#include "Actors/Waypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameMode/SimpleShooterGameModeBase.h"

UBTTask_ChooseWaypoint::UBTTask_ChooseWaypoint()
{
	NodeName = TEXT("Choose Waypoint");
}

EBTNodeResult::Type UBTTask_ChooseWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
	if (GameMode == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	TArray<AWaypoint*> ConsideredWaypoints = GameMode->GetAllWayPoints();
	if (ConsideredWaypoints.Num() == 0)
	{
		return EBTNodeResult::Failed;
	}
	
	AWaypoint* LastSelectedPoint = Cast<AWaypoint>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey()));
	if (LastSelectedPoint != nullptr)
	{
		ConsideredWaypoints.Remove(LastSelectedPoint);
	}
	
	AWaypoint* Waypoint = GameMode->GetAllWayPoints()[FMath::RandRange(0, ConsideredWaypoints.Num()-1)];
	if (Waypoint == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), Waypoint);
	
	return EBTNodeResult::Succeeded;
}
