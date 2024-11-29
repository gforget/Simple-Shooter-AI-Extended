// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/HealthPack.h"
#include "Actors/ShooterCharacter.h"
#include "GameMode/ShooterGameMode.h"

// Called when the game starts or when spawned
void AHealthPack::BeginPlay()
{
	Super::BeginPlay();

	AShooterGameMode* GameModeBase = GetWorld()->GetAuthGameMode<AShooterGameMode>();
	if (GameModeBase != nullptr)
	{
		GameModeBase->AddHealthPack(this);
	}
}

bool AHealthPack::PackValidation(AShooterCharacter* TargetShooterCharacter)
{
	return TargetShooterCharacter->GetHealthPercent() < 1.0f;
}

void AHealthPack::GivePackTo(AShooterCharacter* TargetShooterCharacter)
{
	Super::GivePackTo(TargetShooterCharacter);
	TargetShooterCharacter->Heal(HealAmount);
}
