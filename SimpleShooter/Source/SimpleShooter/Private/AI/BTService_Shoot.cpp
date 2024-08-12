// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_Shoot.h"

#include "AIController.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_Shoot::UBTService_Shoot()
{
	NodeName = TEXT("Shoot");
}

void UBTService_Shoot::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	AActor* EnemyTarget = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("EnemyInSight"));
	OwnerComp.GetAIOwner()->SetFocus(EnemyTarget);

	if (EnemyTarget != nullptr)
	{
		AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
		if (Character == nullptr)
		{
			return;
		}
	
		Character->PullTrigger(AimOffset);
	}
}
