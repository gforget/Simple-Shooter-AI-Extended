// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/EnemySpawnPoint.h"

#include "Components/BillboardComponent.h"


// Sets default values
AEnemySpawnPoint::AEnemySpawnPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create a billboard component
	UBillboardComponent* Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(RootComponent);

	// Load a custom texture to use as the icon (must be in the project content)
	static ConstructorHelpers::FObjectFinder<UTexture2D> IconTexture(TEXT("/Game/Texture/SpawnNPCIcon"));
    
	if (IconTexture.Succeeded())
	{
		Billboard->SetSprite(IconTexture.Object);
	}
}



// Called when the game starts or when spawned
void AEnemySpawnPoint::BeginPlay()
{
	Super::BeginPlay();
}

