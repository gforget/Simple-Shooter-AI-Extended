// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "GameFramework/SpectatorPawn.h"
#include "MP_ShooterSpectatorPawn.generated.h"

class AMP_ShooterCharacter;

UCLASS()
class SIMPLESHOOTER_API AMP_ShooterSpectatorPawn : public ASpectatorPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMP_ShooterSpectatorPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	ETeam GetTeam();

	void SetTeam(ETeam TeamValue);
	
private:
	
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ETeam> Team = ETeam::NoTeam;
};
