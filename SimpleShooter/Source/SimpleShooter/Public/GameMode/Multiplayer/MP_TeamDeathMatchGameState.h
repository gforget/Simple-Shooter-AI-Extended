// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "ShooterGameState.h"
#include "MP_TeamDeathMatchGameState.generated.h"

/**
 * 
 */
class UGameModeHUD;
UCLASS()
class SIMPLESHOOTER_API AMP_TeamDeathMatchGameState : public AShooterGameState
{
	GENERATED_BODY()

public:
	void AddShooterCharacterCount(AMP_ShooterCharacter* ShooterCharacterToRegister) override;
	
	UPROPERTY(BlueprintReadOnly)
	TMap<TEnumAsByte<ETeam>, int> TeamCount;
};
