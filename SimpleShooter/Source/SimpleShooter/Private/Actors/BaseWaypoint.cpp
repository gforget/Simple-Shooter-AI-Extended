﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseWaypoint.h"


// Sets default values
ABaseWaypoint::ABaseWaypoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ABaseWaypoint::BeginPlay()
{
	Super::BeginPlay();
}
