﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "SP_ShooterAIController.generated.h"

class UHurtStimuli;

UCLASS()
class SIMPLESHOOTER_API ASP_ShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
	
	// Sets default values for this actor's properties
	ASP_ShooterAIController();
	
protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY()
	FRotator SmoothControlRotation;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float SmoothFocusInterpSpeed = 30.0f;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool IsDead() const;
	virtual void UpdateControlRotation(float DeltaTime, bool bUpdatePawn) override;

	float GetFieldOfView();
	float GetSightRange();
	float GetHearingRange();

	UPROPERTY()
	bool bStimuliServiceInitiated = false;

	UHurtStimuli* GetHurtStimuli();
	
	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* AIBehavior;
	
private:
	
	UPROPERTY(EditAnywhere, Category = "Custom Stimulus System")
	bool bDebug = false;

	UPROPERTY(EditAnywhere, Category = "Custom Stimulus System")
	float FieldOfView = 180.0f;
	
	UPROPERTY(EditAnywhere, Category = "Custom Stimulus System")
	float SightRange = 2000.0f;

	UPROPERTY(EditAnywhere, Category = "Custom Stimulus System")
	float HearingRange = 2500.0f;
	
	UPROPERTY()
	float CurrentYawOffset = 0.0f;

	UPROPERTY()
	UHurtStimuli* HurtStimuli;
};
