// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/MP_AmmoPack.h"
#include "Actors/MP_ShooterCharacter.h"

// Called when the game starts or when spawned
void AMP_AmmoPack::BeginPlay()
{
	Super::BeginPlay();
	// AShooterGameMode* GameModeBase = GetWorld()->GetAuthGameMode<AShooterGameMode>();
	// if (GameModeBase != nullptr)
	// {
	// 	GameModeBase->AddAmmoPack(this);
	// }
}

bool AMP_AmmoPack::PackValidation(AMP_ShooterCharacter* TargetShooterCharacter)
{
	return TargetShooterCharacter->GetAmmoReservePercent() < 1.0f;
}

void AMP_AmmoPack::GivePackTo(AMP_ShooterCharacter* TargetShooterCharacter)
{
	Super::GivePackTo(TargetShooterCharacter);
	TargetShooterCharacter->AddAmmoReserve(AmmoAmount);
}
