// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "GameFramework/SpectatorPawn.h"
#include "ABaseShooterSpectatorPawn.generated.h"

UCLASS()
class SIMPLESHOOTER_API AABaseShooterSpectatorPawn : public ASpectatorPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABaseShooterSpectatorPawn();
	
	ETeam GetTeam();
	void SetTeam(ETeam TeamValue);
	
private:
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ETeam> Team = ETeam::NoTeam;
};
