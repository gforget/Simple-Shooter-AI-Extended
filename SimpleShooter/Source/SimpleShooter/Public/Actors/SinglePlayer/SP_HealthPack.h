// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/SinglePlayer/SP_ItemPack.h"
#include "GameFramework/Actor.h"
#include "SP_HealthPack.generated.h"

class ASP_ShooterCharacter;

UCLASS()
class SIMPLESHOOTER_API ASP_HealthPack : public ASP_ItemPack
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditDefaultsOnly)
	float HealAmount = 10.0f;

private:
	
	virtual bool PackValidation(ABaseShooterCharacter* TargetShooterCharacter) override;
	virtual void GivePackTo(ABaseShooterCharacter* TargetShooterCharacter) override;
};
