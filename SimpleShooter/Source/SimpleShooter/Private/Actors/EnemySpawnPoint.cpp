// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/EnemySpawnPoint.h"

#include "Components/BillboardComponent.h"


// Sets default values
AEnemySpawnPoint::AEnemySpawnPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	// Create a billboard component
	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemySpawnPoint::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemySpawnPoint::PostActorCreated()
{
	Super::PostActorCreated();
	ChangeBillboardTexture();
}

void AEnemySpawnPoint::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	ChangeBillboardTexture();
}

void AEnemySpawnPoint::ChangeBillboardTexture()
{
	// Load a custom texture to use as the icon (must be in the project content)
	if (BlueTeamIconTexture != nullptr && RedTeamIconTexture != nullptr)
	{
		if(Team == ETeam::BlueTeam)
		{
			Billboard->SetSprite(BlueTeamIconTexture);
		}
		else
		{
			Billboard->SetSprite(RedTeamIconTexture);
		}
	}
}

