﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MP_Waypoint.generated.h"

UCLASS()
class SIMPLESHOOTER_API AMP_Waypoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMP_Waypoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};