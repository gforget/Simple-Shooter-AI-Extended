// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "GameFramework/GameState.h"
#include "ShooterGameState.generated.h"

class AShooterPlayerState;
/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="Main Functions")
	TArray<AShooterPlayerState*> ReplaceTeamInPlayerState(TArray<AShooterPlayerState*> AllPlayerStates, int IndexPlayerState, TEnumAsByte<ETeam> NewTeam);

	UFUNCTION(BlueprintCallable, Category="Main Functions")
	TArray<TEnumAsByte<ETeam>> ReplaceTeamInBotsList(TArray<TEnumAsByte<ETeam>> BotsList, int IndexBot, TEnumAsByte<ETeam> NewTeam);
};
