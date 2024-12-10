// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/Multiplayer/MP_ShooterGameMode.h"
#include "MP_KillEmAllGameMode.generated.h"

/**
 * 
 */
class AMP_ShooterPlayerController;

UCLASS()
class SIMPLESHOOTER_API AMP_KillEmAllGameMode : public AMP_ShooterGameMode
{
	GENERATED_BODY()
	
public:
	AMP_KillEmAllGameMode();
	
	UPROPERTY()
	TArray<AMP_ShooterPlayerController*> AllPlayerControllers;

protected:
	virtual void BeginPlay() override;
};
