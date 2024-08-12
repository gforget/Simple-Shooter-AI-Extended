// Fill out your copyright notice in the Description page of Project Settings.


#include "..\..\Public\AI\BTService_UpdateAmmoInGunPercent.h"

#include "AIController.h"
#include "Actors/Gun.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_UpdateAmmoInGunPercent::UBTService_UpdateAmmoInGunPercent()
{
	NodeName = TEXT("Update Ammo In Gun Percent");
}

void UBTService_UpdateAmmoInGunPercent::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	const AShooterCharacter* AICharacter = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (AICharacter == nullptr)
	{
		return;
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(GetSelectedBlackboardKey(), AICharacter->GetGunReference()->GetAmmoPercent());
}
