﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stimuli.h"
#include "VisualStimuli.generated.h"
class USphereComponent;
UCLASS()
class SIMPLESHOOTER_API AVisualStimuli : public AStimuli
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVisualStimuli();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
