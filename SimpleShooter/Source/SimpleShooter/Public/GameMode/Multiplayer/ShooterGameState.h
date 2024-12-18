// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "ShooterGameState.generated.h"

class UGameModeHUD;
class AMP_ShooterCharacter;
class AShooterPlayerState;
/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category="Wdiget Classes")
	TSubclassOf<UGameModeHUD> GameModeHUDClass;
	
	UFUNCTION()
	virtual void OnShooterCharacterDeath(AMP_ShooterCharacter* DeadShooterCharacter);
	
	virtual void AddShooterCharacterCount(AMP_ShooterCharacter* ShooterCharacterToRegister);

	void RegisterEvent (AMP_ShooterCharacter* ShooterCharacterRef);
	
};
