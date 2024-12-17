// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/SinglePlayer/SP_TeamDeathMatchGameMode.h"

#include "Actors/ShooterCharacter.h"
#include "Actors/SpawningPoint.h"
#include "Controllers/ShooterPlayerController.h"
#include "GameMode/MainGameInstance.h"
#include "Kismet/GameplayStatics.h"

ASP_TeamDeathMatchGameMode::ASP_TeamDeathMatchGameMode()
{
	FactionManagerComponent->AllianceMode = EAllianceMode::Team;
}

void ASP_TeamDeathMatchGameMode::OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter)
{
	Super::OnShooterCharacterDeath(DeadShooterCharacter);
	
	TeamCount[DeadShooterCharacter->GetTeam()]--;
	if (TeamCount[DeadShooterCharacter->GetTeam()] == 0)
	{
		const ETeam WinningTeam = DeadShooterCharacter->GetTeam() == ETeam::RedTeam ? ETeam::BlueTeam : ETeam::RedTeam; 
		EndGame(WinningTeam);
	}
}

void ASP_TeamDeathMatchGameMode::AddShooterCharacterCount(AShooterCharacter* ShooterCharacterToRegister)
{
	Super::AddShooterCharacterCount(ShooterCharacterToRegister);
	
	if (!TeamCount.Contains(ShooterCharacterToRegister->GetTeam()))
	{
		TeamCount.Add(ShooterCharacterToRegister->GetTeam(), 0);
	}
		
	TeamCount[ShooterCharacterToRegister->GetTeam()]++;
}

void ASP_TeamDeathMatchGameMode::BeginPlay()
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
		// Spawn a blue player + number of blue bots where there are spawn point
		for (int i=0; i<(1+MainGameInstance->NbBlueBots); i++)
		{
			const int SpawnIndex = FMath::RandRange(0, AllBlueSpawnPoints.Num()-1);
			const ASpawningPoint* CurrentSpawningPoint = AllBlueSpawnPoints[SpawnIndex];
			
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
					CurrentSpawningPoint->BlueTeamShooterCharacterClass,
					CurrentSpawningPoint->GetActorLocation(),
					CurrentSpawningPoint->GetActorRotation()
				);
				
				if (AShooterPlayerController* PlayerController = Cast<AShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
				{
					PlayerController->AddOHHealthBar(ShooterCharacter);
				}
			}
				
			AllBlueSpawnPoints.RemoveAt(SpawnIndex);
		}

		//Spawn Enemy Team
		for (int i=0; i<MainGameInstance->NbRedBots; i++)
		{
			const int SpawnIndex = FMath::RandRange(0, AllRedSpawnPoints.Num()-1);
			const ASpawningPoint* CurrentSpawningPoint = AllRedSpawnPoints[SpawnIndex];

			AShooterCharacter* ShooterCharacter = WorldPtr->SpawnActor<AShooterCharacter>(
				CurrentSpawningPoint->RedTeamShooterCharacterClass,
				CurrentSpawningPoint->GetActorLocation(),
				CurrentSpawningPoint->GetActorRotation()
			);
				
			if (AShooterPlayerController* PlayerController = Cast<AShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
			{
				PlayerController->AddOHHealthBar(ShooterCharacter);
			}
			
			AllRedSpawnPoints.RemoveAt(SpawnIndex);
		}
	}
}

void ASP_TeamDeathMatchGameMode::EndGame(ETeam TeamWin)
{
	if (AShooterPlayerController* PlayerController = Cast<AShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		if (PlayerTeam == TeamWin)
		{
			PlayerController->GameOver(WinScreenClass);
		}
		else
		{
			PlayerController->GameOver(LoseScreenClass);
		}
	}
}
