// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "GameFramework/PlayerState.h"
#include "ShooterPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AShooterPlayerState();
	
	UPROPERTY(BlueprintReadWrite, Replicated)
	TEnumAsByte<ETeam> Team = ETeam::BlueTeam;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
