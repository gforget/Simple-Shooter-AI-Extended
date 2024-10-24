// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemPack.h"
#include "GameFramework/Actor.h"
#include "AmmoPack.generated.h"

class AShooterCharacter;
UCLASS()
class SIMPLESHOOTER_API AAmmoPack : public AItemPack
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditDefaultsOnly)
	int AmmoAmount = 20;
	
private:

	virtual bool PackValidation(AShooterCharacter* TargetShooterCharacter) override;
	virtual void GivePackTo(AShooterCharacter* TargetShooterCharacter) override;
	
};
