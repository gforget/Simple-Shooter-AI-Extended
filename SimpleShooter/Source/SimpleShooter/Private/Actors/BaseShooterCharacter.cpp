// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseShooterCharacter.h"

#include "Net/UnrealNetwork.h"

// Sets default values
ABaseShooterCharacter::ABaseShooterCharacter()
{
	
}

ETeam ABaseShooterCharacter::GetTeam() const
{
	return Team;
}

float ABaseShooterCharacter::GetHealthPercent() const
{
	return Health/MaxHealth;
}

void ABaseShooterCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABaseShooterCharacter, Health);
}



