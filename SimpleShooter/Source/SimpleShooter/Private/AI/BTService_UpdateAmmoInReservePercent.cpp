// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_UpdateAmmoInReservePercent.h"

#include "AIController.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_UpdateAmmoInReservePercent::UBTService_UpdateAmmoInReservePercent()
{
	NodeName = TEXT("Update Ammo In Reserve Percent");
}

void UBTService_UpdateAmmoInReservePercent::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
	float DeltaSeconds)
{
	const AShooterCharacter* AICharacter = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (AICharacter == nullptr)
	{
		return;
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(GetSelectedBlackboardKey(), AICharacter->GetAmmoReservePercent());
}
