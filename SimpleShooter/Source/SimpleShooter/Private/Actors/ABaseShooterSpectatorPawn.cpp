// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ABaseShooterSpectatorPawn.h"


// Sets default values
AABaseShooterSpectatorPawn::AABaseShooterSpectatorPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

ETeam AABaseShooterSpectatorPawn::GetTeam()
{
	return Team;
}

void AABaseShooterSpectatorPawn::SetTeam(ETeam TeamValue)
{
	Team = TeamValue;
}
