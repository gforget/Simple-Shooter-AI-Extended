// Fill out your copyright notice in the Description page of Project Settings.


#include "Utility/NavMeshUtility.h"

#include "NavigationSystem.h"

float UNavMeshUtility::GetPathLength(const FVector& Start, const FVector& End, UWorld* WorldContext) const
{
	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(WorldContext);
	if (!NavSys) return -1.0f;

	const ANavigationData* NavData = NavSys->GetDefaultNavDataInstance(FNavigationSystem::DontCreate);
	if (!NavData) return -1.0f;

	FNavLocation StartLocation, EndLocation;
	if (NavSys->ProjectPointToNavigation(Start, StartLocation, FVector(500, 500, 500), NavData)
		&& NavSys->ProjectPointToNavigation(End, EndLocation, FVector(500, 500, 500), NavData))
	{
		float PathLength;
		if (NavSys->GetPathLength(StartLocation.Location, EndLocation.Location, PathLength, NavData))
		{
			return PathLength;
		}
	}

	return -1.0f;
}
