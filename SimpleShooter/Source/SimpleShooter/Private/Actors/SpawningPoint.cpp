// Fill out your copyright notice in the Description page of Project Settings.


#include "..\..\Public\Actors\SpawningPoint.h"

#include "Components/BillboardComponent.h"


// Sets default values
ASpawningPoint::ASpawningPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	// Create a billboard component
	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpawningPoint::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawningPoint::PostActorCreated()
{
	Super::PostActorCreated();
	ChangeBillboardTexture();
}

void ASpawningPoint::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	ChangeBillboardTexture();
}

void ASpawningPoint::ChangeBillboardTexture()
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

