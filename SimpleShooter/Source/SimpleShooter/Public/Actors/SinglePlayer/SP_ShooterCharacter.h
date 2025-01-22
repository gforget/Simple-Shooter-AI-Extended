﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseShooterCharacter.h"
#include "SP_ShooterCharacter.generated.h"

UCLASS()
class SIMPLESHOOTER_API ASP_ShooterCharacter : public ABaseShooterCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASP_ShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	virtual void PullTrigger() override;
	virtual void ReleaseTrigger() override;
	virtual void Reload() override;
	
	void SelfDamage();
	
private:

	UPROPERTY()
	float ForwardAxisValue;
	
	void ActivateDebugSpectatorMode();
	
};