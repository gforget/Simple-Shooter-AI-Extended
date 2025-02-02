﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Multiplayer/MP_ItemPack.h"
#include "MP_AmmoPack.generated.h"

UCLASS()
class SIMPLESHOOTER_API AMP_AmmoPack : public AMP_ItemPack
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly)
	int AmmoAmount = 20;

private:
	virtual bool PackValidation(ABaseShooterCharacter* TargetShooterCharacter) override;
	virtual void GivePackTo(ABaseShooterCharacter* TargetShooterCharacter) override;
};
