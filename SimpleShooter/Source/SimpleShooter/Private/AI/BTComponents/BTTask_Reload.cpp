﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTTask_Reload.h"

#include "AIController.h"
#include "Actors/ShooterCharacter.h"

UBTTask_Reload::UBTTask_Reload()
{
	NodeName = TEXT("Reload");
}

EBTNodeResult::Type UBTTask_Reload::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	Character->Reload();
	return EBTNodeResult::Succeeded;
}
