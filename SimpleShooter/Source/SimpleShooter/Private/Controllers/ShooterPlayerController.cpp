// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/ShooterPlayerController.h"

#include "Actors/ShooterCharacter.h"
#include "Actors/ShooterSpectatorPawn.h"
#include "Blueprint/UserWidget.h"
#include "UI/GameModeHUD.h"
#include "UI/OHHealthBar.h"
#include "UI/PlayerHUD.h"

AShooterPlayerController::AShooterPlayerController()
{
	bShouldPerformFullTickWhenPaused = true;
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AShooterPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (PlayerHUD == nullptr)
	{
		PlayerHUD = Cast<UPlayerHUD>(CreateWidget(this, HUDScreenClass));
		PlayerHUD->AddToViewport();
	}
		
	if (AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(InPawn))
	{
		PlayerHUD->OnPlayerModeEvent();
	}

	if (AShooterSpectatorPawn* ShooterSpectator = Cast<AShooterSpectatorPawn>(InPawn))
	{
		PlayerHUD->OnSpectatorModeEvent();
	}
}

void AShooterPlayerController::GameOver(TSubclassOf<UUserWidget> EndScreenClass)
{
	GameHasEnded(GetPawn());
	
	PlayerHUD->RemoveFromParent();
	GameModeHUD->RemoveFromParent();
	
	UUserWidget* EndScreenWidget = CreateWidget(this, EndScreenClass);
	if (EndScreenWidget != nullptr)
	{
		EndScreenWidget->AddToViewport();
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterPlayerController::AddOHHealthBar(AShooterCharacter* AssignedCharacter)
{
	UOHHealthBar* OHHealthBar = Cast<UOHHealthBar>(CreateWidget(this, OHHealthBarClass));
	OHHealthBar->AddToViewport();
	OHHealthBar->InitializeAssignedCharacterAndPlayerController(AssignedCharacter);
}

void AShooterPlayerController::InstantiateGameModeHUD(TSubclassOf<UGameModeHUD> GameModeHUDClass)
{
	GameModeHUD = Cast<UGameModeHUD>(CreateWidget(this, GameModeHUDClass));
	GameModeHUD->AddToViewport();
}