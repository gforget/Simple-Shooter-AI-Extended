// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTTask_ChooseHealthPack.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameMode/SinglePlayer/SP_ShooterGameMode.h"

UBTTask_ChooseHealthPack::UBTTask_ChooseHealthPack()
{
	NodeName = TEXT("Choose HealthPack");
}

EBTNodeResult::Type UBTTask_ChooseHealthPack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	TArray<ABaseHealthPack*> ConsideredHealthPacks = GameMode->GetAllHealthPacks();
	FVector CharLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(); 

	ConsideredHealthPacks.Sort([CharLocation](const ABaseHealthPack& A, const ABaseHealthPack& B) {
		return FVector::DistSquared(A.GetActorLocation(), CharLocation) < FVector::DistSquared(B.GetActorLocation(), CharLocation);
	});

	ABaseHealthPack* SelectedHealthPack = nullptr;
	for (int i=0; i<ConsideredHealthPacks.Num(); i++)
	{
		if (!ConsideredHealthPacks[i]->IsRecharging())
		{
			SelectedHealthPack = ConsideredHealthPacks[i];
			break;
		}
	}
	
	if (SelectedHealthPack == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), SelectedHealthPack);
	
	return EBTNodeResult::Succeeded;
}
