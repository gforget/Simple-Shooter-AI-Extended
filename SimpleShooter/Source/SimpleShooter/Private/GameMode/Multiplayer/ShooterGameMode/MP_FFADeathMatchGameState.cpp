﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/ShooterGameMode/MP_FFADeathMatchGameState.h"

#include "Actors/Multiplayer/MP_ShooterCharacter.h"
#include "Controllers/Multiplayer/MP_ShooterPlayerController.h"
#include "GameMode/Multiplayer/ShooterGameMode/MP_ShooterGameMode.h"

void AMP_FFADeathMatchGameState::AddShooterCharacterCount(AMP_ShooterCharacter* ShooterCharacterToRegister)
{
	Super::AddShooterCharacterCount(ShooterCharacterToRegister);
	ShooterCount++;
}

void AMP_FFADeathMatchGameState::OnShooterCharacterDeath(AMP_ShooterCharacter* DeadShooterCharacter)
{
	Super::OnShooterCharacterDeath(DeadShooterCharacter);
	ShooterCount--;
	if (ShooterCount <= 1)
	{
		EndGame();
	}
}

void AMP_FFADeathMatchGameState::EndGame()
{
	if (AMP_ShooterPlayerController* LocalShooterController = Cast<AMP_ShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		//For now, controller unpossesed the character when it dies
		//TODO: Detect if the controller is in spectator mode later
		
		AMP_ShooterCharacter* LocalShooterCharacter = Cast<AMP_ShooterCharacter>(LocalShooterController->GetPawn());
		if (LocalShooterCharacter != nullptr)
		{
			LocalShooterController->GameOver(PlayerWinScreenClass);
		}
		else
		{
			LocalShooterController->GameOver(PlayerLoseScreenClass);
		}
	}
	
	if (HasAuthority())
	{
		if (AMP_ShooterGameMode* ShooterGameMode = Cast<AMP_ShooterGameMode>(GetWorld()->GetAuthGameMode()))
		{
			ShooterGameMode->CallLeaveSession();
		}
	}
}