﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTService_UpdateGunInfo.h"

#include "AIController.h"
#include "Actors/SinglePlayer/SP_Gun.h"
#include "Actors/SinglePlayer/SP_ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_UpdateGunInfo::UBTService_UpdateGunInfo()
{
	NodeName = TEXT("Update Gun Info");
}

void UBTService_UpdateGunInfo::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	OwnerCompPtr = &OwnerComp;
	if (OwnerCompPtr != nullptr)
	{
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("AmmoInReservePercent"), GetAmmoReservePercent());
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("AmmoInGunPercent"), GetAmmoInGunPercent());
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("AmmoInTotalPercent"), GetAmmoInTotalPercent());
	}
}

float UBTService_UpdateGunInfo::GetAmmoReservePercent()
{
	const ASP_ShooterCharacter* AICharacter = Cast<ASP_ShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());
	if (AICharacter == nullptr)
	{
		return 0.0f;
	}

	return AICharacter->GetAmmoReservePercent();
}

float UBTService_UpdateGunInfo::GetAmmoInGunPercent()
{
	const ASP_ShooterCharacter* AICharacter = Cast<ASP_ShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());
	if (AICharacter == nullptr)
	{
		return 0.0f;
	}
	
	return AICharacter->GetGunReference()->GetAmmoPercent();
}

float UBTService_UpdateGunInfo::GetAmmoInTotalPercent()
{
	const ASP_ShooterCharacter* AICharacter = Cast<ASP_ShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());
	if (AICharacter == nullptr)
	{
		return 0.0f;
	}
	
	return AICharacter->GetAmmoTotalPercent();
}
