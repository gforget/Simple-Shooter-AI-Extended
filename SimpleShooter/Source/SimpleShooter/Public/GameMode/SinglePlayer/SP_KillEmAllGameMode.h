﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/ShooterGameMode.h"
#include "SP_KillEmAllGameMode.generated.h"

/**
 * 
 */
class AShooterPlayerController;
UCLASS()
class SIMPLESHOOTER_API ASP_KillEmAllGameMode : public AShooterGameMode
{
	GENERATED_BODY()

public:
	
	void OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter) override;

	void AddShooterCharacterCount(AShooterCharacter* ShooterCharacterToRegister);
	
	UPROPERTY(BlueprintReadOnly)
	TMap<TEnumAsByte<ETeam>, int> TeamCount;

	UPROPERTY(BlueprintReadOnly)
	int FFACount = 0;
	
	UPROPERTY(BlueprintReadOnly)
	TEnumAsByte<ETeam> TeamWhoWon = ETeam::NoTeam;

	UPROPERTY()
	TArray<AShooterPlayerController*> AllPlayerControllers;
	
protected:
	void BeginPlay();
	
private:
	void EndGame(ETeam TeamWin = ETeam::NoTeam);

	UPROPERTY()
	bool LostFFA = false;
	
};