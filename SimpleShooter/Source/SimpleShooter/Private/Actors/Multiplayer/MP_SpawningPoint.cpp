﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Multiplayer/MP_SpawningPoint.h"
#include "Components/BillboardComponent.h"

// Sets default values
AMP_SpawningPoint::AMP_SpawningPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	// Create a billboard component
	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMP_SpawningPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMP_SpawningPoint::PostActorCreated()
{
	Super::PostActorCreated();
	ChangeBillboardTexture();
}

void AMP_SpawningPoint::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	ChangeBillboardTexture();
}

void AMP_SpawningPoint::ChangeBillboardTexture()
{
	// Load a custom texture to use as the icon (must be in the project content)
	if (BlueTeamIconTexture != nullptr && RedTeamIconTexture != nullptr)
	{
		if(Team == ETeam::BlueTeam)
		{
			Billboard->SetSprite(BlueTeamIconTexture);
		}
		else if (Team == ETeam::RedTeam)
		{
			Billboard->SetSprite(RedTeamIconTexture);
		}
		else if (Team == ETeam::NoTeam)
		{
			Billboard->SetSprite(NoTeamIconTexture);
		}
	}
}