// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MP_ShooterGameMode.h"
#include "MP_TeamDeathMatchGameMode.generated.h"

/**
 * 
 */
class UGameModeHUD;
class AMP_ShooterPlayerController;
UCLASS()
class SIMPLESHOOTER_API AMP_TeamDeathMatchGameMode : public AMP_ShooterGameMode
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void OnPostLogin(AController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;

private:
	bool SpawningPointsHaveBeenFilled = false;
	void FillSpawningPoints();;
};
