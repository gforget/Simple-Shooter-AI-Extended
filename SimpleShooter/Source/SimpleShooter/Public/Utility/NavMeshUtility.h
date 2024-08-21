// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NavMeshUtility.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UNavMeshUtility : public UObject
{
	GENERATED_BODY()

public :
	float GetPathLength(const FVector& Start, const FVector& End, UWorld* WorldContext) const;
};
