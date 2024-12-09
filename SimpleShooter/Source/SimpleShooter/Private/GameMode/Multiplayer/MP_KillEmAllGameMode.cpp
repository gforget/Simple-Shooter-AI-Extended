// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/MP_KillEmAllGameMode.h"

#include "GameMode/MainGameInstance.h"

AMP_KillEmAllGameMode::AMP_KillEmAllGameMode()
{
	bUseSeamlessTravel = true;
}

void AMP_KillEmAllGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (UMainGameInstance* GameInstance = Cast<UMainGameInstance>(GetGameInstance()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Team Alliance = %d"), GameInstance->AllianceMode.GetIntValue());

		for (const TPair<FString, FPlayerStateData>& Pair : GameInstance->PlayerStateDataStructs)
		{
			const FString& PlayerId = Pair.Key;
			const FPlayerStateData& PlayerData = Pair.Value;

			UE_LOG(LogTemp, Warning, TEXT("PlayerId: %s, Team: %d"), *PlayerId, PlayerData.Team.GetIntValue());
		}

		for (int i=0; i<GameInstance->BotDataStructs.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("Bot Index: %d, Team: %d"), i, GameInstance->BotDataStructs[i].Team.GetIntValue());
		}
		
		UE_LOG(LogTemp, Warning, TEXT("------------------"));
	}
}
