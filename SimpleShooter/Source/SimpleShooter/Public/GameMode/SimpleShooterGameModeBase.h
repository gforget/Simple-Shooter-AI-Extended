﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "Actors/HealthPack.h"
#include "Actors/Waypoint.h"
#include "GameFramework/GameModeBase.h"
#include "SimpleShooterGameModeBase.generated.h"

/**
 * 
 */

class UTeamManager;
class AShooterCharacter;
class AAmmoPack;
class AEnemySpawnPoint;
class AHealthPack;

UCLASS()
class SIMPLESHOOTER_API ASimpleShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASimpleShooterGameModeBase();

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

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<EAllianceMode> AllianceMode;
	
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
