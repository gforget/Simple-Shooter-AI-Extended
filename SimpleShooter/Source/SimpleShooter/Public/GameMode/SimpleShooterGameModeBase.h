// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/HealthPack.h"
#include "Actors/Waypoint.h"
#include "GameFramework/GameModeBase.h"
#include "SimpleShooterGameModeBase.generated.h"

/**
 * 
 */

class AShooterCharacter;
class AAmmoPack;
class AEnemySpawnPoint;
class AHealthPack;

UCLASS()
class SIMPLESHOOTER_API ASimpleShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	virtual void PawnKilled(APawn* PawnKilled);

	UPROPERTY(EditDefaultsOnly)
	bool SpawnEnemy = true;
	
	TArray<AWaypoint*> GetAllWayPoints();
	void AddWayPoint(AWaypoint* WayPoint);
	
	TArray<AAmmoPack*> GetAllAmmoPacks();
	void AddAmmoPack(AAmmoPack* AmmoPack);

	TArray<AHealthPack*> GetAllHealthPacks();
	void AddHealthPack(AHealthPack* HealthPack);
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AShooterCharacter> EnemyShooterCharacterClass;
	
protected:

	virtual void BeginPlay() override;
	
	UPROPERTY()
	TArray<AEnemySpawnPoint*> AllEnemySpawnPoints;
	
	UPROPERTY()
	TArray<AWaypoint*> AllWayPoints;
	
	UPROPERTY()
	TArray<AAmmoPack*> AllAmmoPacks;
	
	UPROPERTY()
	TArray<AHealthPack*> AllHealthPacks;
};
