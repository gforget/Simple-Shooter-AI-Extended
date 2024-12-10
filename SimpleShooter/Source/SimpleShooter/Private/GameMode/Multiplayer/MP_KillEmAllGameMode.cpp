// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/MP_KillEmAllGameMode.h"

#include "Actors/MP_SpawningPoint.h"
#include "GameMode/MainGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/MP_ShooterPlayerController.h"

AMP_KillEmAllGameMode::AMP_KillEmAllGameMode()
{
	bUseSeamlessTravel = true;
}

void AMP_KillEmAllGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Gather all player controller in the scene
	TArray<AActor*> AllPlayerControllersRef;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMP_ShooterPlayerController::StaticClass(),AllPlayerControllersRef);
	
	for (int i=0; i<AllPlayerControllersRef.Num(); i++)
	{
		AllPlayerControllers.Add(Cast<AMP_ShooterPlayerController>(AllPlayerControllersRef[i]));
	}

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
