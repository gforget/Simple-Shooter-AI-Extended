// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "Actors/HealthPack.h"
#include "Actors/Waypoint.h"
#include "GameFramework/GameMode.h"
#include "ShooterGameMode.generated.h"

/**
 * 
 */

class UTeamManager;
class AShooterCharacter;
class AAmmoPack;
class ASpawningPoint;
class AHealthPack;

UCLASS()
class SIMPLESHOOTER_API AShooterGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	AShooterGameMode();

	UFUNCTION()
	virtual void OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter);

	UPROPERTY(EditDefaultsOnly)
	bool SpawnEnemy = true;
	
	TArray<AWaypoint*> GetAllWayPoints();
	void AddWayPoint(AWaypoint* WayPoint);
	
	TArray<AAmmoPack*> GetAllAmmoPacks();
	void AddAmmoPack(AAmmoPack* AmmoPack);

	TArray<AHealthPack*> GetAllHealthPacks();
	void AddHealthPack(AHealthPack* HealthPack);

	void RegisterEvent (AShooterCharacter* ShooterCharacterRef);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Global Object")
	UTeamManager* FactionManagerComponent;

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY()
	TArray<ASpawningPoint*> AllSpawnPoints;

	UPROPERTY()
	TArray<ASpawningPoint*> AllRedSpawnPoints;

	UPROPERTY()
	TArray<ASpawningPoint*> AllBlueSpawnPoints;
	
	UPROPERTY()
	TArray<AWaypoint*> AllWayPoints;
	
	UPROPERTY()
	TArray<AAmmoPack*> AllAmmoPacks;
	
	UPROPERTY()
	TArray<AHealthPack*> AllHealthPacks;
};
