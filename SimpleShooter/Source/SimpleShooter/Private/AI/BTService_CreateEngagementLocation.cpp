// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_CreateEngagementLocation.h"
#include "AIController.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Utility/NavMeshUtility.h"

UBTService_CreateEngagementLocation::UBTService_CreateEngagementLocation()
{
	NodeName = TEXT("Create Engagement Location");
}

void UBTService_CreateEngagementLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	UBehaviorTreeComponent* OwnerCompPtr = &OwnerComp;
	const AShooterCharacter* EnemyInSight = Cast<AShooterCharacter>(OwnerCompPtr->GetBlackboardComponent()->GetValueAsObject(FName("EnemyInSight")));
	const AShooterCharacter* AICharacter = Cast<AShooterCharacter>(Cast<AShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn()));
	
	if (EnemyInSight != nullptr)
	{
		AllValidPositions.Empty();
		FVector StartPoint = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation();
		
		const FVector BotForward = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorForwardVector();
		FVector2D BotForward2D = FVector2D(BotForward.X, BotForward.Y);
		BotForward2D.Normalize();
		FVector BotForwardXY = FVector(BotForward2D.X, BotForward2D.Y, 0.0f);
		FVector BotRightXY = BotForwardXY.RotateAngleAxis(90.0f, FVector::UpVector);
		
		// Draw the debug line
		if (bDebug) DrawDebugLine(GetWorld(), StartPoint, StartPoint + BotForwardXY*200.0f, FColor::Green,false,0.25f,0,1.0f);
		if (bDebug) DrawDebugLine(GetWorld(), StartPoint, StartPoint + BotRightXY*200.0f, FColor::Green,false,0.25f,0,1.0f);

		FHitResult Hit;
		FHitResult Hit2;
		FHitResult Hit3;
		
		//TODO: will have to find another way to ignore shooter character later
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(OwnerCompPtr->GetAIOwner()->GetPawn());
		Params.AddIgnoredActor(EnemyInSight);
		
		for (int i=0; i<nbVerticalPoints; i++)
		{
			FVector PointPosition = StartPoint + BotForwardXY*(distanceBetweenPoints*i) - BotRightXY*(distanceBetweenPoints*(nbHorizontalPoints/2));
			for (int j=0; j<nbHorizontalPoints; j++)
			{

				if (GetWorld()->LineTraceSingleByChannel(Hit, PointPosition, PointPosition + FVector::UpVector*99999.9f, ECollisionChannel::ECC_GameTraceChannel1, Params))
				{
					FVector CeilPosition = Hit.Location;
					CeilPosition.Z -= 50.0f;
				
					if (bDebug)DrawDebugLine(GetWorld(), CeilPosition, CeilPosition + FVector::UpVector*-99999.9f, FColor::Blue,false,0.25f,0,1.0f);
					
					if (GetWorld()->LineTraceSingleByChannel(Hit2, CeilPosition, CeilPosition + FVector::UpVector*-99999.9f, ECollisionChannel::ECC_GameTraceChannel1, Params))
					{
						FVector GroundLocation = Hit2.Location;
						GroundLocation.Z += 25.0f;
						
						if (!GetWorld()->LineTraceSingleByChannel(Hit3, GroundLocation, StartPoint, ECollisionChannel::ECC_GameTraceChannel1, Params))
						{
							if (AICharacter->NavMeshUtility->IsPointOnNavmesh(GroundLocation, GetWorld()))
							{
								if (bDebug)DrawDebugSphere(GetWorld(), GroundLocation, 5.0f, 12, FColor::Green, false, 0.25f, 0, 1.0);
								AllValidPositions.Add(GroundLocation);
							}
							else
							{
								if (bDebug)DrawDebugSphere(GetWorld(), GroundLocation, 5.0f, 12, FColor::Blue, false, 0.25f, 0, 1.0);
							}
						}
						else
						{
							if (bDebug)DrawDebugSphere(GetWorld(), Hit2.Location, 5.0f, 12, FColor::Red, false, 0.25f, 0, 1.0);
						}
						
					}
				}
				
				PointPosition += BotRightXY*distanceBetweenPoints;
			}
		}

		//Evaluate which point is the most suitable to go to
		for (int i=0; i<AllValidPositions.Num(); i++)
		{
			
		}
	}
}
