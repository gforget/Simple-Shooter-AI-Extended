// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_UpdateSelfHealth.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UBTService_UpdateSelfHealth : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_UpdateSelfHealth();
	
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
