// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/SinglePlayer/SP_ItemPack.h"
#include "GameFramework/Actor.h"
#include "SP_AmmoPack.generated.h"

class ASP_ShooterCharacter;
UCLASS()
class SIMPLESHOOTER_API ASP_AmmoPack : public ASP_ItemPack
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditDefaultsOnly)
	int AmmoAmount = 20;
	
private:

	virtual bool PackValidation(ASP_ShooterCharacter* TargetShooterCharacter) override;
	virtual void GivePackTo(ASP_ShooterCharacter* TargetShooterCharacter) override;
	
};
