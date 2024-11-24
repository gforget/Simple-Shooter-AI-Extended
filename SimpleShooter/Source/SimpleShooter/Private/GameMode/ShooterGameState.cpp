// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShooterGameState.h"

#include "GameMode/ShooterPlayerState.h"

TArray<AShooterPlayerState*> AShooterGameState::ReplaceTeamInPlayerState(
	TArray<AShooterPlayerState*> AllPlayerStates,
	int IndexPlayerState,
	TEnumAsByte<ETeam> NewTeam)
{
	TArray<AShooterPlayerState*> NewPlayerStates = AllPlayerStates;
	NewPlayerStates[IndexPlayerState]->Team = NewTeam;
	
	return NewPlayerStates;
}
