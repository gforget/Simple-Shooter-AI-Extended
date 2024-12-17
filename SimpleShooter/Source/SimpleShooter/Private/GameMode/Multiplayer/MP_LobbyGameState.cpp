// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/MP_LobbyGameState.h"
#include "GameMode/MainGameInstance.h"
#include "GameMode/Multiplayer/ShooterPlayerState.h"

TArray<AShooterPlayerState*> AMP_LobbyGameState::ReplaceTeamInPlayerState(TArray<AShooterPlayerState*> AllPlayerStates,
	int IndexPlayerState, TEnumAsByte<ETeam> NewTeam)
{
	TArray<AShooterPlayerState*> NewPlayerStates = AllPlayerStates;
	NewPlayerStates[IndexPlayerState]->Team = NewTeam;
	
	return NewPlayerStates;
}

TArray<FBotData> AMP_LobbyGameState::ReplaceTeamInBotDatasArray(TArray<FBotData> BotDatasArray, int IndexBot,
	TEnumAsByte<ETeam> NewTeam)
{
	TArray<FBotData> NewBotsArray = BotDatasArray;
	NewBotsArray[IndexBot].Team = NewTeam;
	
	return NewBotsArray;
}
