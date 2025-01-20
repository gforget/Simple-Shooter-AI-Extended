// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Multiplayer/MP_HealthPack.h"

#include "Actors/Multiplayer/MP_ShooterCharacter.h"

// Called when the game starts or when spawned
void AMP_HealthPack::BeginPlay()
{
	Super::BeginPlay();
}

bool AMP_HealthPack::PackValidation(ABaseShooterCharacter* TargetShooterCharacter)
{
	return TargetShooterCharacter->GetHealthPercent() < 1.0f;
}

void AMP_HealthPack::GivePackTo(ABaseShooterCharacter* TargetShooterCharacter)
{
	Super::GivePackTo(TargetShooterCharacter);
	TargetShooterCharacter->Heal(HealAmount);
}