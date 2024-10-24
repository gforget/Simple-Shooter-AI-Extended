// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/KillEmAllGameMode.h"

#include "Actors/ShooterCharacter.h"
#include "Actors/ShooterSpectatorPawn.h"
#include "Controllers/ShooterPlayerController.h"
#include "Kismet/GameplayStatics.h"

void AKillEmAllGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Gather all player controller in the scene
	TArray<AActor*> AllPlayerControllersRef;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterPlayerController::StaticClass(),AllPlayerControllersRef);

	for (int i=0; i<AllPlayerControllersRef.Num(); i++)
	{
		AllPlayerControllers.Add(Cast<AShooterPlayerController>(AllPlayerControllersRef[i]));
	}
}

void AKillEmAllGameMode::OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter)
{
	Super::OnShooterCharacterDeath(DeadShooterCharacter);
	
	if (AllianceMode == EAllianceMode::FFA)
	{
		const APlayerController* PlayerController = Cast<APlayerController>(DeadShooterCharacter->GetController());
		if (PlayerController != nullptr)
		{
			LostFFA = true;
		}
		
		FFACount--;
		if (FFACount == 1)
		{
			EndGame();
		}
	}
	else
	{
		TeamCount[DeadShooterCharacter->GetTeam()]--;
		if (TeamCount[DeadShooterCharacter->GetTeam()] == 0)
		{
			const ETeam WinningTeam = DeadShooterCharacter->GetTeam() == ETeam::RedTeam ? ETeam::BlueTeam : ETeam::RedTeam; 
			EndGame(WinningTeam);
		}
	}
}

void AKillEmAllGameMode::AddShooterCharacterCount(AShooterCharacter* ShooterCharacterToRegister)
{
	if (AllianceMode == EAllianceMode::FFA)
	{
		FFACount++;
	}
	else
	{
		if (!TeamCount.Contains(ShooterCharacterToRegister->GetTeam()))
		{
			TeamCount.Add(ShooterCharacterToRegister->GetTeam(), 0);
		}
		
		TeamCount[ShooterCharacterToRegister->GetTeam()]++;
	}
}

void AKillEmAllGameMode::EndGame(ETeam TeamWin)
{
	TeamWhoWon = TeamWin;
	
	for (int i=0; i<AllPlayerControllers.Num(); i++)
	{
		if (AllianceMode == EAllianceMode::FFA)
		{
			if (AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(AllPlayerControllers[i]->GetPawn()))
			{
				AllPlayerControllers[i]->GameHasEnded(ShooterCharacter, true);
			}

			if (AShooterSpectatorPawn* ShooterSpectator = Cast<AShooterSpectatorPawn>(AllPlayerControllers[i]->GetPawn()))
			{
				AllPlayerControllers[i]->GameHasEnded(ShooterSpectator, false);
			}
		}
		else
		{
			if (AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(AllPlayerControllers[i]->GetPawn()))
			{
				AllPlayerControllers[i]->GameHasEnded(ShooterCharacter, ShooterCharacter->GetTeam() == TeamWin);
			}

			if (AShooterSpectatorPawn* ShooterSpectator = Cast<AShooterSpectatorPawn>(AllPlayerControllers[i]->GetPawn()))
			{
				AllPlayerControllers[i]->GameHasEnded(ShooterSpectator, ShooterSpectator->GetTeam() == TeamWin);
			}
		}
	}
}
