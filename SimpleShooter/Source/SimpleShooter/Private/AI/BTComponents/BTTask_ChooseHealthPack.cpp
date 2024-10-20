// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTComponents/BTTask_ChooseHealthPack.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameMode/SimpleShooterGameModeBase.h"

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
	
	ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
	if (GameMode == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	TArray<AHealthPack*> ConsideredHealthPacks = GameMode->GetAllHealthPacks();
	FVector CharLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(); 

	ConsideredHealthPacks.Sort([CharLocation](const AHealthPack& A, const AHealthPack& B) {
		return FVector::DistSquared(A.GetActorLocation(), CharLocation) < FVector::DistSquared(B.GetActorLocation(), CharLocation);
	});

	AHealthPack* SelectedHealthPack = nullptr;
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
