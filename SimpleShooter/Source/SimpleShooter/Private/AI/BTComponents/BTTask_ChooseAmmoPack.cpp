// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTTask_ChooseAmmoPack.h"

#include "AIController.h"
#include "Actors/SinglePlayer/SP_AmmoPack.h"
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
	
	ASP_ShooterGameMode* GameMode = GetWorld()->GetAuthGameMode<ASP_ShooterGameMode>();
	if (GameMode == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	TArray<ASP_AmmoPack*> ConsideredAmmoPacks = GameMode->GetAllAmmoPacks();
	FVector CharLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(); 

	ConsideredAmmoPacks.Sort([CharLocation](const ASP_AmmoPack& A, const ASP_AmmoPack& B) {
		return FVector::DistSquared(A.GetActorLocation(), CharLocation) < FVector::DistSquared(B.GetActorLocation(), CharLocation);
	});

	ASP_AmmoPack* SelectedAmmoPack = nullptr;
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
