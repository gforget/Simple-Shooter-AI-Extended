﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/Multiplayer/ShooterGameState.h"
#include "MP_FFADeathMatchGameState.generated.h"

/**
 * 
 */
class UGameModeHUD;
UCLASS()
class SIMPLESHOOTER_API AMP_FFADeathMatchGameState : public AShooterGameState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category="Wdiget Classes")
	TSubclassOf<UUserWidget> PlayerWinScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="Wdiget Classes")
	TSubclassOf<UUserWidget> PlayerLoseScreenClass;
	
	void AddShooterCharacterCount(AMP_ShooterCharacter* ShooterCharacterToRegister) override;
	void OnShooterCharacterDeath(AMP_ShooterCharacter* DeadShooterCharacter) override;
	
	UPROPERTY(BlueprintReadOnly)
	int ShooterCount;

private:
	void EndGame();
};