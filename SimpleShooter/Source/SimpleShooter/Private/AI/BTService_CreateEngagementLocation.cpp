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
		FVector StartPoint = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation();

		FHitResult Hit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(OwnerCompPtr->GetAIOwner()->GetPawn());
		Params.AddIgnoredActor(EnemyInSight);
		
		if (!GetWorld()->LineTraceSingleByChannel(Hit, StartPoint, StartPoint + FVector::UpVector*99999.9f, ECollisionChannel::ECC_GameTraceChannel1, Params))
		{
			return;
		}
		
		const FVector BotForward = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorForwardVector();
		FVector2D BotForward2D = FVector2D(BotForward.X, BotForward.Y);
		BotForward2D.Normalize();
		FVector BotForwardXY = FVector(BotForward2D.X, BotForward2D.Y, 0.0f);
		
		StartPoint.Z = Hit.Location.Z - 50.0f;
		FVector EndPoint = StartPoint + BotForwardXY*200.0f; 

		// Draw the debug line
		DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Green,false,0.25f,0,1.0f);
		//
		
		const float ArcIncrement = ArcDegrees/NbArcs;
		const float RadiusIncrement = MaxRadius/NbPointsPerArcs;
		float CurrentArcDegree = -(ArcDegrees/2.0f);

		BotForwardXY = BotForwardXY.RotateAngleAxis(CurrentArcDegree, FVector::UpVector);
		
		for (int i=0; i<NbArcs; i++)
		{
			float CurrentRadius = RadiusIncrement;
			for (int j=0; j<NbPointsPerArcs-1; j++)
			{
				FVector EngagementPosition = StartPoint + BotForwardXY*CurrentRadius;
				FHitResult Hit2;
		
				if (GetWorld()->LineTraceSingleByChannel(Hit2, EngagementPosition, EngagementPosition + FVector::UpVector*-99999.9f, ECollisionChannel::ECC_GameTraceChannel1, Params))
				{
					EngagementPosition = Hit2.Location;
					DrawDebugSphere(GetWorld(), EngagementPosition, 5.0f, 12, FColor::Red, false, 0.25f, 0, 1.0);
					//OwnerCompPtr->GetBlackboardComponent()->SetValueAsVector(FName("EngagementLocation"), Hit.Location);
				}
				
				CurrentRadius += RadiusIncrement;
			}
			
			BotForwardXY = BotForwardXY.RotateAngleAxis(ArcIncrement, FVector::UpVector);
		}
	}
}
