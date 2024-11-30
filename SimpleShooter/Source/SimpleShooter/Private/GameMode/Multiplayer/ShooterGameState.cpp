// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/ShooterGameState.h"

#include "GameMode/Multiplayer/ShooterPlayerState.h"

TArray<AShooterPlayerState*> AShooterGameState::ReplaceTeamInPlayerState(
	TArray<AShooterPlayerState*> AllPlayerStates,
	int IndexPlayerState,
	TEnumAsByte<ETeam> NewTeam)
{
	TArray<AShooterPlayerState*> NewPlayerStates = AllPlayerStates;
	NewPlayerStates[IndexPlayerState]->Team = NewTeam;
	
	return NewPlayerStates;
}

TArray<TEnumAsByte<ETeam>> AShooterGameState::ReplaceTeamInBotsList(
	TArray<TEnumAsByte<ETeam>> BotsList,
	int IndexBot,
	TEnumAsByte<ETeam> NewTeam)
{
	TArray<TEnumAsByte<ETeam>> NewBotsList = BotsList;
	NewBotsList[IndexBot] = NewTeam;
	
	return NewBotsList;
}
