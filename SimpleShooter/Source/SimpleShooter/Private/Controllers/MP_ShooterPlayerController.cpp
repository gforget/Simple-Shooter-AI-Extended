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
	//bAlwaysRelevant = true;
}

void AMP_ShooterPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	UE_LOG(LogTemp, Warning, TEXT("OnPossess called on %s. IsLocalController: %s"),
	   HasAuthority() ? TEXT("Server") : TEXT("Client"),
	   IsLocalController() ? TEXT("true") : TEXT("false"));
	
	if (IsLocalController())
	{
		// if (HUD == nullptr)
		// {
		// 	HUD = Cast<UPlayerHUD>(CreateWidget(this, HUDScreenClass));
		// 	if (HUD != nullptr)
		// 	{
		// 		HUD->AddToViewport();
		// 	}
		// }
		//
		// if (HUD != nullptr)
		// {
		// 	if (AMP_ShooterCharacter* ShooterCharacter = Cast<AMP_ShooterCharacter>(InPawn))
		// 	{
		// 		HUD->OnPlayerModeEvent();
		// 	}
		//
		// 	if (AShooterSpectatorPawn* ShooterSpectator = Cast<AShooterSpectatorPawn>(InPawn))
		// 	{
		// 		HUD->OnSpectatorModeEvent();
		// 	}
		// }
	}
}

void AMP_ShooterPlayerController::OnRep_Pawn()
{
	Super::OnRep_Pawn();
	
	if (IsLocalController() && GetPawn())
	{
		UE_LOG(LogTemp, Log, TEXT("OnRep_Pawn triggered on Client for Pawn: %s"), *GetPawn()->GetName());
		//OnPossess(GetPawn()); // Manually trigger OnPossess
	}
}