// Fill out your copyright notice in the Description page of Project Settings.

#include "GameMode/Multiplayer/MP_FFADeathMatchGameMode.h"
#include "Actors/MP_SpawningPoint.h"
#include "Actors/MP_ShooterCharacter.h"
#include "Controllers/MP_ShooterPlayerController.h"
#include "GameMode/MainGameInstance.h"

AMP_FFADeathMatchGameMode::AMP_FFADeathMatchGameMode()
{
	FactionManagerComponent->AllianceMode = EAllianceMode::FFA;
}

void AMP_FFADeathMatchGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AMP_FFADeathMatchGameMode::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);
	
	UWorld* WorldPtr = GetWorld();
	if (UMainGameInstance* GameInstance = Cast<UMainGameInstance>(GetGameInstance()))
	{
		const int SpawnIndex = FMath::RandRange(0, AllSpawnPoints.Num()-1);
		const AMP_SpawningPoint* CurrentSpawningPoint = AllSpawnPoints[SpawnIndex];
	
		AMP_ShooterCharacter* ShooterCharacter = WorldPtr->SpawnActor<AMP_ShooterCharacter>(
			CurrentSpawningPoint->RedTeamShooterCharacterClass,
			CurrentSpawningPoint->GetActorLocation(),
			CurrentSpawningPoint->GetActorRotation()
		);
		
		if (ShooterCharacter != nullptr)
		{
			if (AMP_ShooterPlayerController* ShooterPlayerController = Cast<AMP_ShooterPlayerController>(NewPlayer))
			{
				ShooterPlayerController->Possess(ShooterCharacter);
			}
		}
		
		AllSpawnPoints.RemoveAt(SpawnIndex);
	}
}

void AMP_FFADeathMatchGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}
