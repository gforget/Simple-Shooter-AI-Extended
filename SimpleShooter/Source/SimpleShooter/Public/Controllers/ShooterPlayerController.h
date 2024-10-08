// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
class AShooterCharacter;

UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AShooterPlayerController();
	
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;
	void AddOHHealthBar(AShooterCharacter* AssignedCharacter);

	virtual void SetIgnoreLookInput(bool bNewLookInput) override;
	virtual void SetIgnoreMoveInput(bool bNewMoveInput) override;
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> HUDScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> OHHealthBarClass;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WinScreenClass;
	
	FTimerHandle RestartTimer;
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5.0f;

	UPROPERTY()
	UUserWidget* HUD;
};
