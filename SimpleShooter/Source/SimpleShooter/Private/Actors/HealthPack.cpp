// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/HealthPack.h"
#include "Actors/ShooterCharacter.h"
#include "GameMode/SimpleShooterGameModeBase.h"

// Called when the game starts or when spawned
void AHealthPack::BeginPlay()
{
	Super::BeginPlay();

	ASimpleShooterGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
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
