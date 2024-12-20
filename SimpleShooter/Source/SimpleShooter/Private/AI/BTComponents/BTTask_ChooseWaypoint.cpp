﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTTask_ChooseWaypoint.h"
#include "Actors/SinglePlayer/SP_Waypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameMode/SinglePlayer/SP_ShooterGameMode.h"

UBTTask_ChooseWaypoint::UBTTask_ChooseWaypoint()
{
	NodeName = TEXT("Choose Waypoint");
}

EBTNodeResult::Type UBTTask_ChooseWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	ASP_ShooterGameMode* GameMode = GetWorld()->GetAuthGameMode<ASP_ShooterGameMode>();
	if (GameMode == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	TArray<ASP_Waypoint*> ConsideredWaypoints = GameMode->GetAllWayPoints();
	if (ConsideredWaypoints.Num() == 0)
	{
		return EBTNodeResult::Failed;
	}
	
	ASP_Waypoint* LastSelectedPoint = Cast<ASP_Waypoint>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey()));
	if (LastSelectedPoint != nullptr)
	{
		ConsideredWaypoints.Remove(LastSelectedPoint);
	}
	
	ASP_Waypoint* Waypoint = GameMode->GetAllWayPoints()[FMath::RandRange(0, ConsideredWaypoints.Num()-1)];
	if (Waypoint == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), Waypoint);
	
	return EBTNodeResult::Succeeded;
}
