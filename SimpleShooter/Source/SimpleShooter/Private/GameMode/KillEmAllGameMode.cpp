// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/KillEmAllGameMode.h"

#include "EngineUtils.h"
#include "Actors/ShooterCharacter.h"
#include "Kismet/GameplayStatics.h"

void AKillEmAllGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	if (APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		const AShooterCharacter* PlayerCharacter = Cast<AShooterCharacter>(PlayerPawn);
		if (PlayerCharacter != nullptr)
		{
			TeamOfPlayer = PlayerCharacter->GetTeam();		
		}
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
			EndGame(!LostFFA);
		}
	}
	else
	{
		TeamCount[DeadShooterCharacter->GetTeam()]--;
		if (TeamCount[DeadShooterCharacter->GetTeam()] == 0)
		{
			EndGame(TeamOfPlayer != DeadShooterCharacter->GetTeam());
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

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		const bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
