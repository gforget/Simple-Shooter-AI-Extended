// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Waypoint.h"
#include "GameMode/SimpleShooterGameModeBase.h"

// Sets default values
AWaypoint::AWaypoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AWaypoint::BeginPlay()
{
	Super::BeginPlay();
	ASimpleShooterGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
	if (GameModeBase != nullptr)
	{
		GameModeBase->AddWayPoint(this);
	}
}

// Called every frame
void AWaypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

