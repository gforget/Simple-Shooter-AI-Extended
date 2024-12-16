// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/SinglePlayer/SP_FFADeathMatchGameMode.h"

#include "Actors/ShooterCharacter.h"
#include "Actors/ShooterSpectatorPawn.h"
#include "Actors/SpawningPoint.h"
#include "Controllers/ShooterPlayerController.h"
#include "GameMode/MainGameInstance.h"
#include "Kismet/GameplayStatics.h"

ASP_FFADeathMatchGameMode::ASP_FFADeathMatchGameMode()
{
	FactionManagerComponent->AllianceMode = EAllianceMode::FFA;
}

void ASP_FFADeathMatchGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	//Gather all spawn point
	UWorld* WorldPtr = GetWorld();
	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(WorldPtr,AActor::StaticClass(),AllActors);

	if (WorldPtr && AllActors.Num() > 0)
	{
		for (int i=0; i<AllActors.Num(); i++)
		{
			if (ASpawningPoint* SpawningPoint = Cast<ASpawningPoint>(AllActors[i]))
			{
				AllSpawnPoints.Add(SpawningPoint);
			}
		}
	}
	
	if (const UMainGameInstance* MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		// Spawn a blue player + number of red bots where there are spawn point
		for (int i=0; i<(1+MainGameInstance->NbRedBots); i++)
		{
			const int SpawnIndex = FMath::RandRange(0, AllSpawnPoints.Num()-1);
			const ASpawningPoint* CurrentSpawningPoint = AllSpawnPoints[SpawnIndex];
			
			if (i==0) // put the spawned player at a spawn position
			{
				AShooterCharacter* ShooterCharacter = WorldPtr->SpawnActor<AShooterCharacter>(
					CurrentSpawningPoint->BlueTeamShooterCharacterClass,
					CurrentSpawningPoint->GetActorLocation(),
					CurrentSpawningPoint->GetActorRotation()
				);
				
				if (AShooterPlayerController* PlayerController = Cast<AShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
				{
					PlayerController->Possess(ShooterCharacter);
					PlayerController->InstantiateGameModeHUD(GameModeHUDClass);
				}
			}
			else
			{
				AShooterCharacter* ShooterCharacter = WorldPtr->SpawnActor<AShooterCharacter>(
					CurrentSpawningPoint->RedTeamShooterCharacterClass,
					CurrentSpawningPoint->GetActorLocation(),
					CurrentSpawningPoint->GetActorRotation()
				);
				
				if (AShooterPlayerController* PlayerController = Cast<AShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
				{
					PlayerController->AddOHHealthBar(ShooterCharacter);
				}
			}
				
			AllSpawnPoints.RemoveAt(SpawnIndex);
		}
	}
}

void ASP_FFADeathMatchGameMode::OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter)
{
	Super::OnShooterCharacterDeath(DeadShooterCharacter);

	NbShooterAlive--;
	if (NbShooterAlive == 1)
	{
		EndGame();
	}
}

void ASP_FFADeathMatchGameMode::AddShooterCharacterCount(AShooterCharacter* ShooterCharacterToRegister)
{
	Super::AddShooterCharacterCount(ShooterCharacterToRegister);
	NbShooterAlive++;
}

void ASP_FFADeathMatchGameMode::EndGame()
{
	if (AShooterPlayerController* PlayerController = Cast<AShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		if (AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(PlayerController->GetPawn()))
		{
			PlayerController->GameOver(WinScreenClass);
		}

		if (AShooterSpectatorPawn* ShooterSpectator = Cast<AShooterSpectatorPawn>(PlayerController->GetPawn()))
		{
			PlayerController->GameOver(LoseScreenClass);
		}
	}
}
