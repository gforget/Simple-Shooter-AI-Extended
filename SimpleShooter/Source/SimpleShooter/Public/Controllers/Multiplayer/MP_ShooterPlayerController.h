// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MP_ShooterPlayerController.generated.h"

/**
 * 
 */

class UGameModeHUD;
class UPlayerHUD;
class AMP_ShooterCharacter;

UCLASS()
class SIMPLESHOOTER_API AMP_ShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMP_ShooterPlayerController();
	
	void GameOver(TSubclassOf<UUserWidget> EndScreenClass);
	void AddOHHealthBar(AMP_ShooterCharacter* AssignedCharacter);
	
	void InstantiateGameModeHUD(TSubclassOf<UGameModeHUD> GameModeHUDClass);
protected:
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
	
private:

	void InstantiateHUD(APawn* InPawn);
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPlayerHUD> HUDScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> OHHealthBarClass;

	UPROPERTY()
	UPlayerHUD* PlayerHUD;
	
	UPROPERTY()
	UGameModeHUD* GameModeHUD;


};
