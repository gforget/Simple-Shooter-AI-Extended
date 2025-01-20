// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseShooterCharacter.h"

#include "Net/UnrealNetwork.h"

// Sets default values
ABaseShooterCharacter::ABaseShooterCharacter()
{
	
}

float ABaseShooterCharacter::GetAmmoReservePercent() const
{
	return static_cast<float>(AmmoReserve)/static_cast<float>(MaxAmmoReserve);
}

int ABaseShooterCharacter::AddAmmoReserve(int AmmoAmount)
{
	if (AmmoReserve+AmmoAmount <= MaxAmmoReserve)
	{
		AmmoReserve += AmmoAmount;
		return AmmoAmount;
	}
	else
	{
		AmmoReserve = MaxAmmoReserve;
		return (AmmoReserve+AmmoAmount) - MaxAmmoReserve;
	}
}

ETeam ABaseShooterCharacter::GetTeam() const
{
	return Team;
}

float ABaseShooterCharacter::GetHealthPercent() const
{
	return Health/MaxHealth;
}

float ABaseShooterCharacter::Heal(float HealAmount)
{
	if (Health+HealAmount <= MaxHealth)
	{
		Health += HealAmount;
		OnHealEvent.Broadcast();
		return HealAmount;
	}
	else
	{
		Health = MaxHealth;
		OnHealEvent.Broadcast();
		return (Health+HealAmount) - MaxHealth;
	}	
}

void ABaseShooterCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABaseShooterCharacter, Health);
}



