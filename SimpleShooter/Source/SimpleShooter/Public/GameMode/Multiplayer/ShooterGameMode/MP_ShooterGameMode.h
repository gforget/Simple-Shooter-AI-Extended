﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/Multiplayer/MP_GeneralGameMode.h"
#include "ActorComponents/TeamManager.h"
#include "MP_ShooterGameMode.generated.h"

/**
 * 
 */
class UTeamManager;
class AMP_ShooterCharacter;
class AMP_AmmoPack;
class AMP_SpawningPoint;
class AMP_HealthPack;
class AMP_Waypoint;

UCLASS()
class SIMPLESHOOTER_API AMP_ShooterGameMode : public AMP_GeneralGameMode
{
	GENERATED_BODY()

public:
	AMP_ShooterGameMode();

	UFUNCTION()
	virtual void OnShooterCharacterDeath(ABaseShooterCharacter* DeadShooterCharacter);
	
	TArray<AMP_Waypoint*> GetAllWayPoints();
	void AddWayPoint(AMP_Waypoint* WayPoint);
	
	TArray<AMP_AmmoPack*> GetAllAmmoPacks();
	void AddAmmoPack(AMP_AmmoPack* AmmoPack);

	TArray<AMP_HealthPack*> GetAllHealthPacks();
	void AddHealthPack(AMP_HealthPack* HealthPack);

	void RegisterEvent (AMP_ShooterCharacter* ShooterCharacterRef);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Global Object")
	UTeamManager* FactionManagerComponent;

	void CallLeaveSession();
	
protected:

	virtual void BeginPlay() override;
	virtual void OnPostLogin(AController* NewPlayer) override;
	
	UPROPERTY()
	TArray<AMP_SpawningPoint*> AllSpawnPoints;

	UPROPERTY()
	TArray<AMP_SpawningPoint*> AllRedSpawnPoints;

	UPROPERTY()
	TArray<AMP_SpawningPoint*> AllBlueSpawnPoints;
	
	UPROPERTY()
	TArray<AMP_Waypoint*> AllWayPoints;
	
	UPROPERTY()
	TArray<AMP_AmmoPack*> AllAmmoPacks;
	
	UPROPERTY()
	TArray<AMP_HealthPack*> AllHealthPacks;

	bool SpawningPointsHaveBeenFilled = false;
	void FillSpawningPoints();
	
private:
	FTimerHandle RestartTimer;
	
	UPROPERTY(EditDefaultsOnly)
	float RestartDelay = 5.0f;
	
	void LeaveSession();
};
