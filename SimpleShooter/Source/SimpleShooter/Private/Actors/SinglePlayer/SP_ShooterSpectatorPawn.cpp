// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/SinglePlayer/SP_ShooterSpectatorPawn.h"

#include "Actors/SinglePlayer/SP_ShooterCharacter.h"
#include "Controllers/SinglePlayer/SP_ShooterPlayerController.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASP_ShooterSpectatorPawn::ASP_ShooterSpectatorPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
}

// Called when the game starts or when spawned
void ASP_ShooterSpectatorPawn::BeginPlay()
{
	Super::BeginPlay();
	if (MovementComponent)
	{
		MovementComponent->PrimaryComponentTick.bTickEvenWhenPaused = true;
	}
}

// Called every frame
void ASP_ShooterSpectatorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASP_ShooterSpectatorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("ToggleDebugSpectatorMode"), IE_Pressed, this, &ASP_ShooterSpectatorPawn::ReturnToPlayerMode);
}

void ASP_ShooterSpectatorPawn::ReturnToPlayerMode()
{
	
	if (UGameplayStatics::IsGamePaused(GetWorld()))
	{
		UGameplayStatics::SetGamePaused(GetWorld(), false);
	
		GEngine->Exec(GetWorld(), TEXT("r.MotionBlurQuality 0.5"));
		ASP_ShooterPlayerController* ShooterPlayerController = Cast<ASP_ShooterPlayerController>(GetController());
		if (ShooterPlayerController != nullptr)
		{
			if (PlayerShooterCharacter)
			{
				UnPossessed();
				ShooterPlayerController->Possess(PlayerShooterCharacter);
				ShooterPlayerController->SetTickableWhenPaused(false);
				Destroy();
			}
			else
			{
				ShooterPlayerController->SetTickableWhenPaused(false);
			}
		}
	}
	else
	{
		ASP_ShooterPlayerController* ShooterPlayerController = Cast<ASP_ShooterPlayerController>(GetController());
		if (ShooterPlayerController != nullptr)
		{
			UGameplayStatics::SetGamePaused(GetWorld(), true);
			GEngine->Exec(GetWorld(), TEXT("r.MotionBlurQuality 0"));
			ShooterPlayerController->SetTickableWhenPaused(true);
			SetTickableWhenPaused(true);
		}
	}
}

void ASP_ShooterSpectatorPawn::SetPlayerShooterCharacter(ASP_ShooterCharacter* PlayerShooterCharacterRef)
{
	PlayerShooterCharacter = PlayerShooterCharacterRef;
}

ETeam ASP_ShooterSpectatorPawn::GetTeam()
{
	return Team;
}

void ASP_ShooterSpectatorPawn::SetTeam(ETeam TeamValue)
{
	Team = TeamValue;
}

