﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MP_ShooterCharacter.generated.h"

UCLASS()
class SIMPLESHOOTER_API AMP_ShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMP_ShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float RotationRate = 100.0f;
	
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
