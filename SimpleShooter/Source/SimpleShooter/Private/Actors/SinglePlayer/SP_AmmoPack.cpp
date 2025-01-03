﻿// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/SinglePlayer/SP_AmmoPack.h"
#include "Actors/SinglePlayer/SP_ShooterCharacter.h"
#include "GameMode/SinglePlayer/SP_ShooterGameMode.h"

// Called when the game starts or when spawned
void ASP_AmmoPack::BeginPlay()
{
	Super::BeginPlay();
	ASP_ShooterGameMode* GameModeBase = GetWorld()->GetAuthGameMode<ASP_ShooterGameMode>();
	if (GameModeBase != nullptr)
	{
		GameModeBase->AddAmmoPack(this);
	}
}

bool ASP_AmmoPack::PackValidation(ASP_ShooterCharacter* TargetShooterCharacter)
{
	return TargetShooterCharacter->GetAmmoReservePercent() < 1.0f;
}

void ASP_AmmoPack::GivePackTo(ASP_ShooterCharacter* TargetShooterCharacter)
{
	Super::GivePackTo(TargetShooterCharacter);
	TargetShooterCharacter->AddAmmoReserve(AmmoAmount);
}
