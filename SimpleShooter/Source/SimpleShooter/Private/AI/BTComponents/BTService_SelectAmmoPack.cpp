// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTService_SelectAmmoPack.h"

#include "AIController.h"
#include "Actors/AmmoPack.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameMode/SinglePlayer/ShooterGameMode.h"
#include "Utility/NavMeshUtility.h"

UBTService_SelectAmmoPack::UBTService_SelectAmmoPack()
{
	NodeName = TEXT("Select Ammo Pack");
}

void UBTService_SelectAmmoPack::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if (CurrentWorldPtr == nullptr) CurrentWorldPtr = GetWorld();
	OwnerCompPtr = &OwnerComp;

	if (OwnerCompPtr != nullptr && CurrentWorldPtr != nullptr)
	{
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("SelectedAmmoPack"), GetClosestAmmoPack());
	}
}

AAmmoPack* UBTService_SelectAmmoPack::GetClosestAmmoPack()
{
	AAmmoPack* SelectedAmmoPack = nullptr;
	AShooterGameMode* GameMode = GetWorld()->GetAuthGameMode<AShooterGameMode>();
	if (GameMode == nullptr)
	{
		return SelectedAmmoPack;
	}

	TArray<AAmmoPack*> ConsideredAmmoPacks = GameMode->GetAllAmmoPacks();
	const FVector CharLocation = OwnerCompPtr->GetAIOwner()->GetPawn()->GetActorLocation(); 

	float HighestDistance = 999999999999.99f;
	
	for (int i=0; i<ConsideredAmmoPacks.Num(); i++)
	{
		if (!ConsideredAmmoPacks[i]->IsRecharging())
		{
			const AShooterCharacter* AICharacter = Cast<AShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());
			const float CurrentDistance = AICharacter->NavMeshUtility->GetPathLength(CharLocation, ConsideredAmmoPacks[i]->GetActorLocation(), CurrentWorldPtr);
			if (CurrentDistance < HighestDistance)
			{
				SelectedAmmoPack = ConsideredAmmoPacks[i];
				HighestDistance = CurrentDistance;
			}
		}
	}

	return SelectedAmmoPack;
}