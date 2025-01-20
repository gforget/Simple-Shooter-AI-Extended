// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "GameFramework/Character.h"
#include "BaseShooterCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMP_HealEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeadEvent, ABaseShooterCharacter*, DeadShooterCharacter);

UCLASS(Abstract)
class SIMPLESHOOTER_API ABaseShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	// Sets default values for this character's properties
	ABaseShooterCharacter();

	UFUNCTION(BlueprintCallable)
	float GetAmmoReservePercent() const;

	int AddAmmoReserve(int AmmoAmount);
	
	UPROPERTY(EditDefaultsOnly, Category="Position Reference")
	FVector HealthBarAnchor = FVector(0.0f, 0.0f, 88.0f);

	UPROPERTY()
	FMP_HealEvent OnHealEvent;
	
	UPROPERTY()
	FDeadEvent OnDeadEvent;

	UFUNCTION(BlueprintPure)
	ETeam GetTeam() const;
	
	UFUNCTION(BlueprintCallable)
	float GetHealthPercent() const;

	float Heal(float HealAmount);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Alliances")
	TEnumAsByte<ETeam> Team = ETeam::NoTeam;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	float MaxHealth = 100.0f;

	UPROPERTY(Replicated, VisibleAnywhere, Category="Combat")
	float Health = 10.0f;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	int MaxAmmoReserve = 100;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	int AmmoReserve = 20;
};
