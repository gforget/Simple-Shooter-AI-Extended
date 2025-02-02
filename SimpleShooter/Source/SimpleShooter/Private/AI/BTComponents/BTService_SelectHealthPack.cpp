﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTService_SelectHealthPack.h"

#include "AIController.h"
#include "Actors/SinglePlayer/SP_ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameMode/SinglePlayer/SP_ShooterGameMode.h"
#include "Utility/NavMeshUtility.h"

UBTService_SelectHealthPack::UBTService_SelectHealthPack()
{
	NodeName = TEXT("Select Health Pack");
}

void UBTService_SelectHealthPack::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if (CurrentWorldPtr == nullptr) CurrentWorldPtr = GetWorld();
	OwnerCompPtr = &OwnerComp;

	if (OwnerCompPtr != nullptr && CurrentWorldPtr != nullptr)
	{
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("SelectedHealthPack"), GetClosestHealthPack());
	}
}

ASP_HealthPack* UBTService_SelectHealthPack::GetClosestHealthPack()
{
	ASP_HealthPack* SelectedHealthPack = nullptr;
	ASP_ShooterGameMode* GameMode = GetWorld()->GetAuthGameMode<ASP_ShooterGameMode>();
	if (GameMode == nullptr)
	{
		return SelectedHealthPack;
	}

	TArray<ASP_HealthPack*> ConsideredHealthPacks = GameMode->GetAllHealthPacks();
	const FVector CharLocation = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation(); 

	float HighestDistance = 999999999999.99f;
	
	for (int i=0; i<ConsideredHealthPacks.Num(); i++)
	{
		if (!ConsideredHealthPacks[i]->IsRecharging())
		{
			const ASP_ShooterCharacter* AICharacter = Cast<ASP_ShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());
			const float CurrentDistance = AICharacter->NavMeshUtility->GetPathLength(CharLocation, ConsideredHealthPacks[i]->GetActorLocation(), CurrentWorldPtr);
			
			if (CurrentDistance < HighestDistance)
			{
				SelectedHealthPack = ConsideredHealthPacks[i];
				HighestDistance = CurrentDistance;
			}
		}
	}

	return SelectedHealthPack;
}