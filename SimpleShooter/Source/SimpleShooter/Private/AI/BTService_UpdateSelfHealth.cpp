// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_UpdateSelfHealth.h"

#include "AIController.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_UpdateSelfHealth::UBTService_UpdateSelfHealth()
{
	NodeName = TEXT("Update Self Health Percent Value");
}

void UBTService_UpdateSelfHealth::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	const AShooterCharacter* AICharacter = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (AICharacter == nullptr)
	{
		return;
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(GetSelectedBlackboardKey(), AICharacter->GetHealthPercent());	
}
