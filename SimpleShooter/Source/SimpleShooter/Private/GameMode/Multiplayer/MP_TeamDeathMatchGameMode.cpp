// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/MP_TeamDeathMatchGameMode.h"

#include "Actors/MP_ShooterCharacter.h"
#include "Actors/MP_SpawningPoint.h"
#include "Controllers/MP_ShooterPlayerController.h"
#include "GameMode/MainGameInstance.h"
#include "GameMode/Multiplayer/MP_TeamDeathMatchGameState.h"
#include "GameMode/Multiplayer/ShooterPlayerState.h"
#include "Kismet/GameplayStatics.h"

AMP_TeamDeathMatchGameMode::AMP_TeamDeathMatchGameMode()
{
	bUseSeamlessTravel = true;
}

void AMP_TeamDeathMatchGameMode::BeginPlay()
{
	Super::BeginPlay();
	FillSpawningPoints();
	
	if (UMainGameInstance* GameInstance = Cast<UMainGameInstance>(GetGameInstance()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Team Alliance = %d"), GameInstance->AllianceMode.GetIntValue());

		for (const TPair<FString, FPlayerStateData>& Pair : GameInstance->PlayerStateDataStructs)
		{
			const FString& PlayerId = Pair.Key;
			const FPlayerStateData& PlayerData = Pair.Value;

			UE_LOG(LogTemp, Warning, TEXT("PlayerId: %s, Team: %d"), *PlayerId, PlayerData.Team.GetIntValue());
		}

		for (int i=0; i<GameInstance->BotDataStructs.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("Bot Index: %d, Team: %d"), i, GameInstance->BotDataStructs[i].Team.GetIntValue());
		}
		
		UE_LOG(LogTemp, Warning, TEXT("------------------"));
	}
}

void AMP_TeamDeathMatchGameMode::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);
	FillSpawningPoints();
	
	UWorld* WorldPtr = GetWorld();
	if (UMainGameInstance* GameInstance = Cast<UMainGameInstance>(GetGameInstance()))
	{
		AShooterPlayerState* PlayerState = NewPlayer->GetPlayerState<AShooterPlayerState>();
		FPlayerStateData PlayerStateData = GameInstance->PlayerStateDataStructs[PlayerState->GetUniqueId().ToString()];
		PlayerState->Team = PlayerStateData.Team;

		AMP_ShooterCharacter* ShooterCharacter = nullptr;
		
		if (PlayerState->Team == ETeam::BlueTeam)
		{
			const int SpawnIndex = FMath::RandRange(0, AllBlueSpawnPoints.Num()-1);
			const AMP_SpawningPoint* CurrentSpawningPoint = AllBlueSpawnPoints[SpawnIndex];
		
			ShooterCharacter = WorldPtr->SpawnActor<AMP_ShooterCharacter>(
				CurrentSpawningPoint->BlueTeamShooterCharacterClass,
				CurrentSpawningPoint->GetActorLocation(),
				CurrentSpawningPoint->GetActorRotation()
			);
			
			AllBlueSpawnPoints.RemoveAt(SpawnIndex);
		}
		else if (PlayerState->Team == ETeam::RedTeam)
		{
			const int SpawnIndex = FMath::RandRange(0, AllRedSpawnPoints.Num()-1);
			const AMP_SpawningPoint* CurrentSpawningPoint = AllRedSpawnPoints[SpawnIndex];
		
			ShooterCharacter = WorldPtr->SpawnActor<AMP_ShooterCharacter>(
				CurrentSpawningPoint->RedTeamShooterCharacterClass,
				CurrentSpawningPoint->GetActorLocation(),
				CurrentSpawningPoint->GetActorRotation()
			);
			
			AllRedSpawnPoints.RemoveAt(SpawnIndex);
		}

		if (ShooterCharacter != nullptr)
		{
			if (AMP_TeamDeathMatchGameState* TeamDeathMatchGameState = Cast<AMP_TeamDeathMatchGameState>(GetWorld()->GetGameState()))
			{
				TeamDeathMatchGameState->AddShooterCharacterCount(ShooterCharacter);
			}
			
			if (AMP_ShooterPlayerController* ShooterPlayerController = Cast<AMP_ShooterPlayerController>(NewPlayer))
			{
				ShooterPlayerController->Possess(ShooterCharacter);
			}
		}
	}
}

void AMP_TeamDeathMatchGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}

void AMP_TeamDeathMatchGameMode::FillSpawningPoints()
{
	if (!SpawningPointsHaveBeenFilled)
	{
		//Gather all spawn point
		UWorld* WorldPtr = GetWorld();
		TArray<AActor*> AllActors;
		UGameplayStatics::GetAllActorsOfClass(WorldPtr,AActor::StaticClass(),AllActors);

		if (WorldPtr && AllActors.Num() > 0)
		{
			for (int i=0; i<AllActors.Num(); i++)
			{
				if (AMP_SpawningPoint* SpawningPoint = Cast<AMP_SpawningPoint>(AllActors[i]))
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
		SpawningPointsHaveBeenFilled = true;
	}
}

void AMP_TeamDeathMatchGameMode::OnShooterCharacterDeath(AMP_ShooterCharacter* DeadShooterCharacter)
{
	// TeamCount[DeadShooterCharacter->GetTeam()]--;
	// if (TeamCount[DeadShooterCharacter->GetTeam()] == 0)
	// {
	// 	const ETeam WinningTeam = DeadShooterCharacter->GetTeam() == ETeam::RedTeam ? ETeam::BlueTeam : ETeam::RedTeam; 
	// 	EndGame(WinningTeam);
	// }
}

void AMP_TeamDeathMatchGameMode::EndGame(ETeam TeamWin)
{
	// if (AMP_ShooterPlayerController* PlayerController = Cast<AMP_ShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
	// {
	// 	if (PlayerTeam == TeamWin)
	// 	{
	// 		PlayerController->GameOver(WinScreenClass);
	// 	}
	// 	else
	// 	{
	// 		PlayerController->GameOver(LoseScreenClass);
	// 	}
	// }
}
