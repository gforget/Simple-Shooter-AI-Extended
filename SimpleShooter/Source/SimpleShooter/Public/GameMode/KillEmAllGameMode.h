// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AKillEmAllGameMode : public ASimpleShooterGameModeBase
{
	GENERATED_BODY()

public:
	
	void OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter) override;

	void AddShooterCharacterCount(AShooterCharacter* ShooterCharacterToRegister);
	
protected:
	void BeginPlay();
	
private:
	void EndGame(bool bIsPlayerWinner);

	UPROPERTY()
	bool LostFFA = false;
	
	UPROPERTY()
	int FFACount = 0;

	UPROPERTY()
	TMap<TEnumAsByte<ETeam>, int> TeamCount;

	UPROPERTY()
	TEnumAsByte<ETeam> TeamOfPlayer;
};
