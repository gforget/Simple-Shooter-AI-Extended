// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTTask_ChooseAmmoPack.h"

#include "AIController.h"
#include "Actors/BaseAmmoPack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameMode/SinglePlayer/SP_ShooterGameMode.h"

UBTTask_ChooseAmmoPack::UBTTask_ChooseAmmoPack()
{
	NodeName = TEXT("Choose AmmoPack");
}

EBTNodeResult::Type UBTTask_ChooseAmmoPack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	//TODO : select between SP and MP shootergame mode, since both don't inherot from the same game mode
	ASP_ShooterGameMode* GameMode = GetWorld()->GetAuthGameMode<ASP_ShooterGameMode>();
	if (GameMode == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	TArray<ABaseAmmoPack*> ConsideredAmmoPacks = GameMode->GetAllAmmoPacks();
	FVector CharLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(); 

	ConsideredAmmoPacks.Sort([CharLocation](const ABaseAmmoPack& A, const ABaseAmmoPack& B) {
		return FVector::DistSquared(A.GetActorLocation(), CharLocation) < FVector::DistSquared(B.GetActorLocation(), CharLocation);
	});

	ABaseAmmoPack* SelectedAmmoPack = nullptr;
	for (int i=0; i<ConsideredAmmoPacks.Num(); i++)
	{
		if (!ConsideredAmmoPacks[i]->IsRecharging())
		{
			SelectedAmmoPack = ConsideredAmmoPacks[i];
			break;
		}
	}
	
	if (SelectedAmmoPack == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), SelectedAmmoPack);
	
	return EBTNodeResult::Succeeded;
}
