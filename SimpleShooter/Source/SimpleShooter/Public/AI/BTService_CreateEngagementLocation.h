// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_CreateEngagementLocation.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UBTService_CreateEngagementLocation : public UBTService
{
	GENERATED_BODY()
	
public:
	UBTService_CreateEngagementLocation();
	
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circle Grid Properties")
	int NbArcs = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circle Grid Properties")
	int NbPointsPerArcs = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circle Grid Properties")
	float MaxRadius = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circle Grid Properties")
	float ArcDegrees = 180.0f;
};
