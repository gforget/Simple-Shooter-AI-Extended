// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/ShooterGameState.h"

#include "Actors/Multiplayer/MP_ShooterCharacter.h"

void AShooterGameState::OnShooterCharacterDeath(AMP_ShooterCharacter* DeadShooterCharacter)
{
}

void AShooterGameState::AddShooterCharacterCount(AMP_ShooterCharacter* ShooterCharacterToRegister)
{
}

void AShooterGameState::RegisterEvent(AMP_ShooterCharacter* ShooterCharacterRef)
{
	ShooterCharacterRef->OnDeadEvent.AddDynamic(this, &AShooterGameState::OnShooterCharacterDeath);
}
