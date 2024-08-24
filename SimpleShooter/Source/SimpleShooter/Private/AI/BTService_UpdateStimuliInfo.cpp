// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_UpdateStimuliInfo.h"

#include "AIController.h"
#include "Actors/ShooterCharacter.h"
#include "Actors/Stimuli/VisualStimuli.h"
#include "Actors/Stimuli/VisualStimuli/VisualStimuli_ShooterCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

UBTService_UpdateStimuliInfo::UBTService_UpdateStimuliInfo()
{
	NodeName = TEXT("Update Stimuli Info");
}

void UBTService_UpdateStimuliInfo::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	OwnerCompPtr = &OwnerComp;
	
	if (OwnerCompPtr != nullptr)
	{
		TArray<AActor*> overlappedActors;
		const TArray<AActor*> ActorsToIgnore;

		const TSubclassOf<AActor> filter = AVisualStimuli::StaticClass();
		
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectsQuery;
		ObjectsQuery.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));
		
		const bool bHasHit = UKismetSystemLibrary::SphereOverlapActors(
			GetWorld(),
			OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation(),
			VisionRange,
			ObjectsQuery,
			filter,
			ActorsToIgnore,
			overlappedActors);
		
		if (bHasHit)
		{
			for (int i=0; i<overlappedActors.Num(); i++)
			{
				if (AVisualStimuli_ShooterCharacter* VS_Shooter = Cast<AVisualStimuli_ShooterCharacter> (overlappedActors[i]))
				{
					//check if the stimuli is not from the AI pawn itself
					if (VS_Shooter->GetShooterCharacterRef()->GetUniqueID() != OwnerCompPtr->GetAIOwner()->GetPawn()->GetUniqueID())
					{
						//UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor: %s"), *overlappedActors[i]->GetName());
					}
				}
			}
		}
	}
	
	DrawDebugSphere(GetWorld(), OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation(), VisionRange, 12, FColor::Red, false, 0.0f, 0, 1.0);
	
}
