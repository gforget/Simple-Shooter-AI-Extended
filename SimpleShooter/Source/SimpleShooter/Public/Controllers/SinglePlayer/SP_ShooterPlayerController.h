// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SP_ShooterPlayerController.generated.h"

/**
 * 
 */
class ASP_ShooterCharacter;
class UPlayerHUD;
class UGameModeHUD;

UCLASS()
class SIMPLESHOOTER_API ASP_ShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASP_ShooterPlayerController();
	
	void GameOver(TSubclassOf<UUserWidget> EndScreenClass);
	void AddOHHealthBar(ASP_ShooterCharacter* AssignedCharacter);

	void InstantiateGameModeHUD(TSubclassOf<UGameModeHUD> GameModeHUDClass);
	
protected:
	
	virtual void BeginPlay() override;
	
	virtual void OnPossess(APawn* InPawn) override;
	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPlayerHUD> HUDScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> OHHealthBarClass;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WinScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> BlueTeamWinScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> RedTeamWinScreenClass;
	
	FTimerHandle RestartTimer;
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5.0f;

	UPROPERTY()
	UPlayerHUD* PlayerHUD;
	
	UPROPERTY()
	UGameModeHUD* GameModeHUD;
};
