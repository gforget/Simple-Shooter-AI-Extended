﻿// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/Multiplayer/MP_AmmoPack.h"
#include "Actors/Multiplayer/MP_ShooterCharacter.h"

// Called when the game starts or when spawned
void AMP_AmmoPack::BeginPlay()
{
	Super::BeginPlay();
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