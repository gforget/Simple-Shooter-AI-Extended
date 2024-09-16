// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NavMeshUtility.generated.h"

/**
 * 
 */
class UNavigationPath;
UCLASS()
class SIMPLESHOOTER_API UNavMeshUtility : public UObject
{
	GENERATED_BODY()

public :
	float GetPathLength(const FVector& Start, const FVector& End, UWorld* WorldContext) const;
	UNavigationPath* GetPath(const FVector& Start, const FVector& End, UWorld* WorldContext) const;
	bool IsPointOnNavmesh(const FVector& Position, UWorld* WorldContext) const;
};
