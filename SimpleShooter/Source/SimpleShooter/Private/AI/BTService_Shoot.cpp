// Fill out your copyright notice in the Description page of Project Settings.
#include "AI/BTService_Shoot.h"

#include "AIController.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

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
	
	AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr)
	{
		return;
	}

	AActor* EnemyTarget = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("EnemyInSight"));
	if (EnemyTarget != nullptr)
	{
		if (!bJustSawEnemy)
		{
			CurrentAimPosition = EnemyTarget->GetActorLocation();
			bJustSawEnemy = true;
		}
		
		TimerBeforeShooting += DeltaSeconds;
		if (TimerBeforeShooting > TimeBeforeStartingShooting)
		{
			OwnerComp.GetAIOwner()->SetFocalPoint(CurrentAimPosition);
			Character->PullTrigger(AimOffset);
		}
		else
		{
			Character->ReleaseTrigger();
		}
		
		CurrentAimPosition = UKismetMathLibrary::VInterpTo_Constant(
			CurrentAimPosition,
			EnemyTarget->GetActorLocation(),
			DeltaSeconds,
			AimAdjustmentSpeed
			);
	}
	else
	{
		bJustSawEnemy = false;
		TimerBeforeShooting = 0.0f;
		Character->ReleaseTrigger();
	}
}
