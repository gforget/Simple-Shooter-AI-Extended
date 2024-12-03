// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/MP_ShooterPlayerController.h"

#include "Actors/MP_ShooterCharacter.h"
#include "Actors/ShooterSpectatorPawn.h"
#include "Blueprint/UserWidget.h"
#include "UI/PlayerHUD.h"

AMP_ShooterPlayerController::AMP_ShooterPlayerController()
{
	bShouldPerformFullTickWhenPaused = true;
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	bReplicates = true;
}

void AMP_ShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	InstantiateHUD(GetPawn());
}

void AMP_ShooterPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	InstantiateHUD(GetPawn());
}

void AMP_ShooterPlayerController::InstantiateHUD(APawn* InPawn)
{
	if (IsLocalController())
	{
		if (HUD == nullptr)
		{
			HUD = Cast<UPlayerHUD>(CreateWidget(this, HUDScreenClass));
			if (HUD != nullptr)
			{
				HUD->AddToViewport();
			}
		}
		
		if (HUD != nullptr)
		{
			if (AMP_ShooterCharacter* ShooterCharacter = Cast<AMP_ShooterCharacter>(InPawn))
			{
				HUD->OnPlayerModeEvent();
			}
		
			if (AShooterSpectatorPawn* ShooterSpectator = Cast<AShooterSpectatorPawn>(InPawn))
			{
				HUD->OnSpectatorModeEvent();
			}
		}
	}
}


