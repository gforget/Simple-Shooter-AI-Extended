// Fill out your copyright notice in the Description page of Project Settings.


#include "..\..\Public\Actors\RoomTriggerBox.h"

#include "Controllers/ShooterAIController.h"


// Sets default values
ARoomTriggerBox::ARoomTriggerBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARoomTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ARoomTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ARoomTriggerBox::OnOverlapEnd);
}

// Called every frame
void ARoomTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GetOverlappingActors()
}

void ARoomTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("test1"));
	
	if (APawn* OtherPawn = Cast<APawn>(OtherActor))
	{
		if (AShooterAIController* AIController = Cast<AShooterAIController>(OtherPawn->GetController()))
		{
			AIController->CurrentRoomTriggerBox = this;
		}
	}
}

void ARoomTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("test2"));
}

