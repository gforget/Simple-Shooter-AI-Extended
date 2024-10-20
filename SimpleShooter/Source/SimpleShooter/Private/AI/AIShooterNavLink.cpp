// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AIShooterNavLink.h"

#include "Actors/ShooterCharacter.h"
#include "GameFramework/PawnMovementComponent.h"


// Sets default values
AAIShooterNavLink::AAIShooterNavLink()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLinks.Empty();
	bSmartLinkIsRelevant = true;
}

// Called when the game starts or when spawned
void AAIShooterNavLink::BeginPlay()
{
	Super::BeginPlay();
	OnSmartLinkReached.AddDynamic(this, &AAIShooterNavLink::OnNavLinkReach);
}

// Called every frame
void AAIShooterNavLink::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAIShooterNavLink::OnNavLinkReach(AActor* MovingActor, const FVector& DestinationPoint)
{
	UE_LOG(LogTemp, Warning, TEXT("Test"));
	if (AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(MovingActor))
	{
		FVector DeltaToDestination = DestinationPoint - ShooterCharacter->GetActorLocation();
		DeltaToDestination.Z = 0.0f;
		DeltaToDestination.Normalize();
		
		//ShooterCharacter->GetMovementComponent()->StopActiveMovement();
		//ShooterCharacter->AddMovementInput(DeltaToDestination);
		ShooterCharacter->Jump();
	}
}

