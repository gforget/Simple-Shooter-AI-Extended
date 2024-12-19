﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/Multiplayer/ShooterGameMode/MP_ShooterGameState.h"
#include "ActorComponents/TeamManager.h"
#include "MP_LobbyGameState.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AMP_LobbyGameState : public AMP_ShooterGameState
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Main Functions")
	TArray<AMP_ShooterPlayerState*> ReplaceTeamInPlayerState(TArray<AMP_ShooterPlayerState*> AllPlayerStates, int IndexPlayerState, TEnumAsByte<ETeam> NewTeam);

	UFUNCTION(BlueprintCallable, Category="Main Functions")
	TArray<FBotData> ReplaceTeamInBotDatasArray(TArray<FBotData> BotDatasArray, int IndexBot, TEnumAsByte<ETeam> NewTeam);
};
