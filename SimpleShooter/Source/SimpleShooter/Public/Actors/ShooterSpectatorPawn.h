// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "GameFramework/SpectatorPawn.h"
#include "ShooterSpectatorPawn.generated.h"

class AShooterCharacter;

UCLASS()
class SIMPLESHOOTER_API AShooterSpectatorPawn : public ASpectatorPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShooterSpectatorPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ReturnToPlayerMode();

	void SetPlayerShooterCharacter(AShooterCharacter* PlayerShooterCharacterRef);

	ETeam GetTeam();

	void SetTeam(ETeam TeamValue);
	
private:
	
	UPROPERTY()
	AShooterCharacter* PlayerShooterCharacter;
	
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ETeam> Team = ETeam::NoTeam;
};
