// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SP_ShooterGameMode.h"
#include "SP_TeamDeathMatchGameMode.generated.h"

/**
 * 
 */
class UGameModeHUD;
UCLASS()
class SIMPLESHOOTER_API ASP_TeamDeathMatchGameMode : public ASP_ShooterGameMode
{
	GENERATED_BODY()
	
public:
	ASP_TeamDeathMatchGameMode();
	
	void OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter) override;
	void AddShooterCharacterCount(AShooterCharacter* ShooterCharacterToRegister) override;

	UPROPERTY(BlueprintReadOnly)
	TMap<TEnumAsByte<ETeam>, int> TeamCount;
	
protected:
	void BeginPlay();
	
private:
	void EndGame(ETeam TeamWin);

	ETeam PlayerTeam = ETeam::BlueTeam;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameModeHUD> GameModeHUDClass;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WinScreenClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> LoseScreenClass;
};
