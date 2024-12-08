// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MP_HealthPack.h"

#include "Actors/MP_ShooterCharacter.h"

// Called when the game starts or when spawned
void AMP_HealthPack::BeginPlay()
{
	Super::BeginPlay();
	// AShooterGameMode* GameModeBase = GetWorld()->GetAuthGameMode<AShooterGameMode>();
	// if (GameModeBase != nullptr)
	// {
	// 	GameModeBase->AddHealthPack(this);
	// }
}

bool AMP_HealthPack::PackValidation(AMP_ShooterCharacter* TargetShooterCharacter)
{
	return TargetShooterCharacter->GetHealthPercent() < 1.0f;
}

void AMP_HealthPack::GivePackTo(AMP_ShooterCharacter* TargetShooterCharacter)
{
	Super::GivePackTo(TargetShooterCharacter);
	TargetShooterCharacter->Heal(HealAmount);
}