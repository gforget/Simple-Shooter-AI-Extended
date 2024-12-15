// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/AmmoPack.h"
#include "Actors/ShooterCharacter.h"
#include "GameMode/SinglePlayer/SP_ShooterGameMode.h"

// Called when the game starts or when spawned
void AAmmoPack::BeginPlay()
{
	Super::BeginPlay();
	ASP_ShooterGameMode* GameModeBase = GetWorld()->GetAuthGameMode<ASP_ShooterGameMode>();
	if (GameModeBase != nullptr)
	{
		GameModeBase->AddAmmoPack(this);
	}
}

bool AAmmoPack::PackValidation(AShooterCharacter* TargetShooterCharacter)
{
	return TargetShooterCharacter->GetAmmoReservePercent() < 1.0f;
}

void AAmmoPack::GivePackTo(AShooterCharacter* TargetShooterCharacter)
{
	Super::GivePackTo(TargetShooterCharacter);
	TargetShooterCharacter->AddAmmoReserve(AmmoAmount);
}
