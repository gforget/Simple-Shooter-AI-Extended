// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
class AShooterCharacter;
class UPlayerHUD;

UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AShooterPlayerController();
	
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;
	void AddOHHealthBar(AShooterCharacter* AssignedCharacter);
	
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
	UPlayerHUD* HUD;
};
