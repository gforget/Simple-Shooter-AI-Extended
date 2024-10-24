// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemPack.h"
#include "GameFramework/Actor.h"
#include "HealthPack.generated.h"

class AShooterCharacter;

UCLASS()
class SIMPLESHOOTER_API AHealthPack : public AItemPack
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditDefaultsOnly)
	float HealAmount = 10.0f;

private:
	
	virtual bool PackValidation(AShooterCharacter* TargetShooterCharacter) override;
	virtual void GivePackTo(AShooterCharacter* TargetShooterCharacter) override;
};
