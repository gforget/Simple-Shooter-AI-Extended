// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
class AShooterPlayerController;
UCLASS()
class SIMPLESHOOTER_API AKillEmAllGameMode : public ASimpleShooterGameModeBase
{
	GENERATED_BODY()

public:
	
	void OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter) override;

	void AddShooterCharacterCount(AShooterCharacter* ShooterCharacterToRegister);
	
	UPROPERTY(BlueprintReadOnly)
	TMap<TEnumAsByte<ETeam>, int> TeamCount;
	
protected:
	void BeginPlay();
	
private:
	void EndGame(ETeam TeamWin = ETeam::NoTeam);

	UPROPERTY()
	bool LostFFA = false;
	
	UPROPERTY()
	int FFACount = 0;

	UPROPERTY()
	TArray<AShooterPlayerController*> AllPlayerControllers;
};
