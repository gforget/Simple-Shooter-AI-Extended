// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/Multiplayer/MP_ShooterPlayerController.h"

#include "Actors/Multiplayer/MP_ShooterCharacter.h"
#include "Actors/ShooterSpectatorPawn.h"
#include "Blueprint/UserWidget.h"
#include "GameMode/Multiplayer/ShooterGameState.h"
#include "UI/GameModeHUD.h"
#include "UI/Multiplayer/MP_OHHealthBar.h"
#include "UI/PlayerHUD.h"

AMP_ShooterPlayerController::AMP_ShooterPlayerController()
{
	bShouldPerformFullTickWhenPaused = true;
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	bReplicates = true;
}

void AMP_ShooterPlayerController::GameOver(TSubclassOf<UUserWidget> EndScreenClass)
{
	GameHasEnded(GetPawn());
	
	PlayerHUD->RemoveFromParent();
	GameModeHUD->RemoveFromParent();
	
	UUserWidget* EndScreenWidget = CreateWidget(this, EndScreenClass);
	if (EndScreenWidget != nullptr)
	{
		EndScreenWidget->AddToViewport();
	}
}

void AMP_ShooterPlayerController::AddOHHealthBar(AMP_ShooterCharacter* AssignedCharacter)
{
	UMP_OHHealthBar* OHHealthBar = Cast<UMP_OHHealthBar>(CreateWidget(this, OHHealthBarClass));
	OHHealthBar->AddToViewport();
	OHHealthBar->InitializeAssignedCharacterAndPlayerController(AssignedCharacter);
}

void AMP_ShooterPlayerController::InstantiateGameModeHUD(TSubclassOf<UGameModeHUD> GameModeHUDClass)
{
	GameModeHUD = Cast<UGameModeHUD>(CreateWidget(this, GameModeHUDClass));
	GameModeHUD->AddToViewport();
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
		AMP_ShooterCharacter* ShooterCharacter = Cast<AMP_ShooterCharacter>(InPawn);
		AShooterSpectatorPawn* ShooterSpectator = Cast<AShooterSpectatorPawn>(InPawn);

		if (ShooterCharacter != nullptr || ShooterSpectator != nullptr)
		{
			if (PlayerHUD == nullptr)
			{
				PlayerHUD = Cast<UPlayerHUD>(CreateWidget(this, HUDScreenClass));
				if (PlayerHUD != nullptr)
				{
					PlayerHUD->AddToViewport();
				}
			}
		
			if (PlayerHUD != nullptr)
			{
				if (ShooterCharacter != nullptr)
				{
					PlayerHUD->OnPlayerModeEvent();
				}
				else if (ShooterSpectator != nullptr)
				{
					PlayerHUD->OnSpectatorModeEvent();
				}
			}

			if (GameModeHUD == nullptr)
			{
				if (AShooterGameState* ShooterGameState = Cast<AShooterGameState>(GetWorld()->GetGameState()))
				{
					if (ShooterGameState->GameModeHUDClass != nullptr)
					{
						GameModeHUD = Cast<UGameModeHUD>(CreateWidget(this, ShooterGameState->GameModeHUDClass));
						if (GameModeHUD != nullptr)
						{
							GameModeHUD->AddToViewport();
						}
					}
				}
			}
		}
	}
}


