// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/ShooterSpectatorPawn.h"

#include "Actors/ShooterCharacter.h"
#include "Controllers/ShooterPlayerController.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AShooterSpectatorPawn::AShooterSpectatorPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
}

// Called when the game starts or when spawned
void AShooterSpectatorPawn::BeginPlay()
{
	Super::BeginPlay();
	if (MovementComponent)
	{
		MovementComponent->PrimaryComponentTick.bTickEvenWhenPaused = true;
	}
}

// Called every frame
void AShooterSpectatorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AShooterSpectatorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("ToggleDebugSpectatorMode"), IE_Pressed, this, &AShooterSpectatorPawn::ReturnToPlayerMode);
}

void AShooterSpectatorPawn::ReturnToPlayerMode()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	GEngine->Exec(GetWorld(), TEXT("r.MotionBlurQuality 0.5"));
	AShooterPlayerController* ShooterPlayerController = Cast<AShooterPlayerController>(GetController());
	if (ShooterPlayerController != nullptr)
	{
		UnPossessed();
		ShooterPlayerController->Possess(PlayerShooterCharacter);
		ShooterPlayerController->SetTickableWhenPaused(false);
		Destroy();
	}
}

void AShooterSpectatorPawn::SetPlayerShooterCharacter(AShooterCharacter* PlayerShooterCharacterRef)
{
	PlayerShooterCharacter = PlayerShooterCharacterRef;
}

