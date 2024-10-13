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

	AActor* EnemyTarget = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName("EnemyInSight")));
	
	if (EnemyTarget != nullptr)
	{
		if (!OwnerComp.GetBlackboardComponent()->GetValueAsBool(FName("JustSawEnemy")))
		{
			CurrentAimPosition = EnemyTarget->GetActorLocation();
			OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName("JustSawEnemy"), true);
		}

		OwnerComp.GetBlackboardComponent()->SetValueAsFloat(
			FName("TimerBeforeShooting"),
			OwnerComp.GetBlackboardComponent()->GetValueAsFloat(FName("TimerBeforeShooting")) + DeltaSeconds);

		if (OwnerComp.GetBlackboardComponent()->GetValueAsFloat(FName("TimerBeforeShooting")) > TimeBeforeStartingShooting)
		{
			OwnerComp.GetAIOwner()->SetFocalPoint(CurrentAimPosition);
			//OwnerComp.GetAIOwner()->SetFocalPoint(EnemyTarget->GetActorLocation());
			Character->PullTrigger();
		}
		else
		{
			Character->ReleaseTrigger();
		}

		DrawDebugSphere(GetWorld(), CurrentAimPosition, 5.0f, 12, FColor::Cyan, false, 0.01f, 0, 1.0);

		const FVector AimBodyOffset = FVector(0.0f,0.0f,50.0f);
		const FVector OffsetPosition = FMath::VRand()*AimOffset;
		CurrentAimPosition = UKismetMathLibrary::VInterpTo_Constant(
			CurrentAimPosition,
			EnemyTarget->GetActorLocation() + AimBodyOffset + OffsetPosition, //EnemyTarget->GetActorLocation() + OffsetPosition
			DeltaSeconds,
			AimAdjustmentSpeed
			);
		
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName("JustSawEnemy"), false);
		OwnerComp.GetBlackboardComponent()->SetValueAsFloat(FName("TimerBeforeShooting"), 0.0f);
		
		if (OwnerComp.GetBlackboardComponent()->IsVectorValueSet(FName("LastKnownEnemyLocation")))
		{
			OwnerComp.GetAIOwner()->SetFocalPoint(OwnerComp.GetBlackboardComponent()->GetValueAsVector(FName("LastKnownEnemyLocation")));
		}
		else
		{
			OwnerComp.GetAIOwner()->SetFocus(nullptr);
		}
		
		Character->ReleaseTrigger();
	}
}
