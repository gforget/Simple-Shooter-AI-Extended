// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FleePoint.h"

#include "GameMode/SimpleShooterGameModeBase.h"


// Sets default values
AFleePoint::AFleePoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AFleePoint::BeginPlay()
{
	Super::BeginPlay();
	ASimpleShooterGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
	if (GameModeBase != nullptr)
	{
		GameModeBase->AddFleePoint(this);
	}
}

// Called every frame
void AFleePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

