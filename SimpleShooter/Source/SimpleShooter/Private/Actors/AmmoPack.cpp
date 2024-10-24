﻿// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/AmmoPack.h"
#include "Actors/ShooterCharacter.h"
#include "GameMode/SimpleShooterGameModeBase.h"

// Called when the game starts or when spawned
void AAmmoPack::BeginPlay()
{
	Super::BeginPlay();
	ASimpleShooterGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
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
