// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_CreateEngagementLocation.h"

#include "AIController.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_CreateEngagementLocation::UBTService_CreateEngagementLocation()
{
	NodeName = TEXT("Create Engagement Location");
}

void UBTService_CreateEngagementLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBehaviorTreeComponent* OwnerCompPtr = &OwnerComp;
	const AShooterCharacter* EnemyInSight = Cast<AShooterCharacter>(OwnerCompPtr->GetBlackboardComponent()->GetValueAsObject(FName("EnemyInSight")));
	
	if (EnemyInSight != nullptr)
	{
		const FVector DeltaBotToEnemy = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation() - EnemyInSight->GetActorLocation();

		FVector2D DeltaBotToEnemy2D = FVector2D(DeltaBotToEnemy.X, DeltaBotToEnemy.Y);
		DeltaBotToEnemy2D.Normalize();

		FVector DeltaBotToEnemyXY = FVector(DeltaBotToEnemy2D.X, DeltaBotToEnemy2D.Y, 0.0f);
		//DeltaBotToEnemyXY = DeltaBotToEnemyXY.RotateAngleAxis(FMath::RandRange(0.0f, 45.0f), FVector::UpVector);
		DeltaBotToEnemyXY = DeltaBotToEnemyXY.RotateAngleAxis(45.0f, FVector::UpVector);
		
		//FVector EngagementPosition = EnemyInSight->GetActorLocation() + DeltaBotToEnemyXY*FMath::RandRange(400.0f, 600.0f);
		FVector EngagementPosition = EnemyInSight->GetActorLocation() + DeltaBotToEnemyXY*600.0f;
		FHitResult Hit;
		
		if (GetWorld()->LineTraceSingleByChannel(Hit, EngagementPosition, EngagementPosition + FVector::UpVector*-200.0f, ECollisionChannel::ECC_GameTraceChannel1))
		{
			EngagementPosition = Hit.Location;
			DrawDebugSphere(GetWorld(), EngagementPosition, 5.0f, 12, FColor::Red, false, 0.1f, 0, 1.0);
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsVector(FName("EngagementLocation"), Hit.Location);
		}
	}
	else
	{
		OwnerCompPtr->GetBlackboardComponent()->ClearValue(FName("EngagementLocation"));
	}
}
