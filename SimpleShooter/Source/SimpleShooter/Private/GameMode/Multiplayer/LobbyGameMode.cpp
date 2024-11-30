// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/LobbyGameMode.h"

ALobbyGameMode::ALobbyGameMode()
{
	bUseSeamlessTravel = true;
}

void ALobbyGameMode::StartMultiplayerGame(FString LevelName)
{
	if (HasAuthority())
	{
		FString LevelPath = "/Game/Test/";
		LevelPath.Append(LevelName);
		LevelPath.Append("?listen");
		
		GetWorld()->ServerTravel(LevelPath);
	}
}
