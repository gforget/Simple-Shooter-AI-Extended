// Fill out your copyright notice in the Description page of Project Settings.
#include "GameMode/SimpleShooterGameModeBase.h"

#include "Actors/AmmoPack.h"
#include "Actors/EnemySpawnPoint.h"
#include "Actors/ShooterCharacter.h"
#include "Controllers/ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void ASimpleShooterGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* WorldPtr = GetWorld();

	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(WorldPtr,AActor::StaticClass(),AllActors);

	if (WorldPtr && AllActors.Num() > 0 && SpawnEnemy)
	{
		for (int i=0; i<AllActors.Num(); i++)
		{
			AEnemySpawnPoint* SpawnPointPtr = Cast<AEnemySpawnPoint>(AllActors[i]);
			if (SpawnPointPtr != nullptr)
			{
				AllEnemySpawnPoints.Add(SpawnPointPtr);
			}
		}

		const int IndexSpawnPoint = FMath::RandRange(0, AllEnemySpawnPoints.Num()-1);
		const AShooterCharacter* ShooterCharacter = WorldPtr->SpawnActor<AShooterCharacter>(
			EnemyShooterCharacterClass,
			AllEnemySpawnPoints[IndexSpawnPoint]->GetActorLocation(),
			FRotator(0.0f, 0.0f, 0.0f)
			);

		if (ShooterCharacter != nullptr)
		{
			if (AShooterAIController* AIController = Cast<AShooterAIController>(ShooterCharacter->GetController()))
			{
				AIController->CurrentRoomTriggerBox = AllEnemySpawnPoints[IndexSpawnPoint]->SpawnedRoomTriggerBox;
			}
		}
	}
}

void ASimpleShooterGameModeBase::PawnKilled(APawn* PawnKilled)
{
}

TArray<AWaypoint*> ASimpleShooterGameModeBase::GetAllWayPoints()
{
	return AllWayPoints;
}

void ASimpleShooterGameModeBase::AddWayPoint(AWaypoint* Waypoint)
{
	AllWayPoints.Add(Waypoint);
}

TArray<AFleePoint*> ASimpleShooterGameModeBase::GetAllFleePoints()
{
	return AllFleePoints;
}

void ASimpleShooterGameModeBase::AddFleePoint(AFleePoint* FleePoint)
{
	AllFleePoints.Add(FleePoint);
}

TArray<AAmmoPack*> ASimpleShooterGameModeBase::GetAllAmmoPacks()
{
	return AllAmmoPacks;
}

void ASimpleShooterGameModeBase::AddAmmoPack(AAmmoPack* AmmoPack)
{
	AllAmmoPacks.Add(AmmoPack);
}

TArray<AHealthPack*> ASimpleShooterGameModeBase::GetAllHealthPacks()
{
	return AllHealthPacks;
}

void ASimpleShooterGameModeBase::AddHealthPack(AHealthPack* HealthPack)
{
	AllHealthPacks.Add(HealthPack);
}



