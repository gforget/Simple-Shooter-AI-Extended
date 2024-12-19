// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Multiplayer/MP_Waypoint.h"

#include "GameMode/Multiplayer/ShooterGameMode/MP_ShooterGameMode.h"


// Sets default values
AMP_Waypoint::AMP_Waypoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMP_Waypoint::BeginPlay()
{
	Super::BeginPlay();
	AMP_ShooterGameMode* GameModeBase = GetWorld()->GetAuthGameMode<AMP_ShooterGameMode>();
	if (GameModeBase != nullptr)
	{
		GameModeBase->AddWayPoint(this);
	}
}

// Called every frame
void AMP_Waypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

