// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/ShooterPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UI/OHHealthBar.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	HUD = CreateWidget(this, HUDScreenClass);
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}

void AShooterPlayerController::AddOHHealthBar(AShooterCharacter* AssignedCharacter)
{
	UOHHealthBar* OHHealthBar = Cast<UOHHealthBar>(CreateWidget(this, OHHealthBarClass));
	OHHealthBar->AddToViewport();
	OHHealthBar->InitializeAssignedCharacterAndPlayerController(AssignedCharacter, this);
}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	HUD->RemoveFromParent();
	
	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}
	
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}


