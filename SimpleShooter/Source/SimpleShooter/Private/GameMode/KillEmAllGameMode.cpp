// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/KillEmAllGameMode.h"

#include "Actors/ShooterCharacter.h"
#include "Actors/ShooterSpectatorPawn.h"
#include "..\..\Public\Actors\SpawningPoint.h"
#include "Controllers/ShooterPlayerController.h"
#include "GameMode/MainGameInstance.h"
#include "Kismet/GameplayStatics.h"

void AKillEmAllGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Gather all player controller in the scene
	// TArray<AActor*> AllPlayerControllersRef;
	// UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterPlayerController::StaticClass(),AllPlayerControllersRef);
	//
	// for (int i=0; i<AllPlayerControllersRef.Num(); i++)
	// {
	// 	AllPlayerControllers.Add(Cast<AShooterPlayerController>(AllPlayerControllersRef[i]));
	// }
	
	UWorld* WorldPtr = GetWorld();
	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(WorldPtr,AActor::StaticClass(),AllActors);

	if (WorldPtr && AllActors.Num() > 0 && SpawnEnemy)
	{
		for (int i=0; i<AllActors.Num(); i++)
		{
			if (ASpawningPoint* SpawningPoint = Cast<ASpawningPoint>(AllActors[i]))
			{
				AllSpawnPoints.Add(SpawningPoint);
				if (SpawningPoint->Team == ETeam::RedTeam)
				{
					AllRedSpawnPoints.Add(SpawningPoint);
				}
				else
				{
					AllBlueSpawnPoints.Add(SpawningPoint);
				}
			}
		}
	}
	
	if (const UMainGameInstance* MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		const EAllianceMode CurrentAllianceMode = MainGameInstance->AllianceMode;
		
		FactionManagerComponent->AllianceMode = CurrentAllianceMode;
		if (CurrentAllianceMode == EAllianceMode::FFA)
		{
			// Spawn a blue player + number of red bots where there are spawn point
			for (int i=0; i<(1+MainGameInstance->NbRedBots); i++)
			{
				const int SpawnIndex = FMath::RandRange(0, AllSpawnPoints.Num()-1);
				const ASpawningPoint* CurrentSpawningPoint = AllSpawnPoints[SpawnIndex];
				
				if (i==0) // put the spawned player at a spawn position
				{
					if (const AShooterPlayerController* ShooterPlayerController = Cast<AShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
					{
						AActor* PlayerCharacter = ShooterPlayerController->GetPawn();
						PlayerCharacter->SetActorLocation(CurrentSpawningPoint->GetActorLocation());
						PlayerCharacter->SetActorRotation(CurrentSpawningPoint->GetActorRotation());
					}
				}
				else
				{
					AShooterCharacter* ShooterCharacter = WorldPtr->SpawnActor<AShooterCharacter>(
						CurrentSpawningPoint->RedTeamShooterCharacterClass,
						CurrentSpawningPoint->GetActorLocation(),
						CurrentSpawningPoint->GetActorRotation()
					);
				}
				
				AllSpawnPoints.RemoveAt(SpawnIndex);
			}
		}
		else
		{
			// Spawn a blue player + number of respective team bots where there are spawn point
		}
	}
	
}

void AKillEmAllGameMode::OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter)
{
	Super::OnShooterCharacterDeath(DeadShooterCharacter);
	
	if (FactionManagerComponent->AllianceMode == EAllianceMode::FFA)
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
	if (FactionManagerComponent->AllianceMode == EAllianceMode::FFA)
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
		if (FactionManagerComponent->AllianceMode == EAllianceMode::FFA)
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
