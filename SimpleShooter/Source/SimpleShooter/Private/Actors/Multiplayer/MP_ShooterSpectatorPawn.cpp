// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/Multiplayer//MP_ShooterSpectatorPawn.h"

// Sets default values
AMP_ShooterSpectatorPawn::AMP_ShooterSpectatorPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bNetLoadOnClient = false;
}

// Called when the game starts or when spawned
void AMP_ShooterSpectatorPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMP_ShooterSpectatorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ETeam AMP_ShooterSpectatorPawn::GetTeam()
{
	return Team;
}

void AMP_ShooterSpectatorPawn::SetTeam(ETeam TeamValue)
{
	Team = TeamValue;
}

