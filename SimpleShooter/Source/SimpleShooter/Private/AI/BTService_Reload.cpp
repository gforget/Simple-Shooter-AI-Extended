// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_Reload.h"

#include "AIController.h"
#include "Actors/ShooterCharacter.h"

UBTService_Reload::UBTService_Reload()
{
	NodeName = TEXT("Reload");
}

void UBTService_Reload::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}
	
	AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr)
	{
		return;
	}
	
	Character->Reload();
}
