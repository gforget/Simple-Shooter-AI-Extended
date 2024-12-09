// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/ShooterGameMode.h"
#include "MP_KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AMP_KillEmAllGameMode : public AShooterGameMode
{
	GENERATED_BODY()
	
public:
	AMP_KillEmAllGameMode();

protected:
	virtual void BeginPlay() override;
};
