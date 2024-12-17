// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/MP_TeamDeathMatchGameState.h"
#include "Actors/MP_ShooterCharacter.h"

void AMP_TeamDeathMatchGameState::AddShooterCharacterCount(AMP_ShooterCharacter* ShooterCharacterToRegister)
{
	if (!TeamCount.Contains(ShooterCharacterToRegister->GetTeam()))
	{
		TeamCount.Add(ShooterCharacterToRegister->GetTeam(), 0);
	}
		
	TeamCount[ShooterCharacterToRegister->GetTeam()]++;
}
