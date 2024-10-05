// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/KillEmAllGameMode.h"

#include "EngineUtils.h"
#include "Actors/ShooterCharacter.h"
#include "Controllers/ShooterAIController.h"

void AKillEmAllGameMode::OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter)
{
	Super::OnShooterCharacterDeath(DeadShooterCharacter);

	//Make sure the win event work with the TeamManager
	const APlayerController* PlayerController = Cast<APlayerController>(DeadShooterCharacter->GetController());
	if (PlayerController != nullptr)
	{
		EndGame(false);
	}

	for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Controller->IsDead())
		{
			return;
		}
	}
	
	EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		const bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
