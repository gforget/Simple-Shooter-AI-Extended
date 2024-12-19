// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "Actors/HealthPack.h"
#include "Actors/Waypoint.h"
#include "GameFramework/GameMode.h"
#include "SP_ShooterGameMode.generated.h"

/**
 * 
 */

class UTeamManager;
class AShooterCharacter;
class ASP_AmmoPack;
class ASpawningPoint;
class AHealthPack;

UCLASS()
class SIMPLESHOOTER_API ASP_ShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASP_ShooterGameMode();

	UFUNCTION()
	virtual void OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter);

	virtual void AddShooterCharacterCount(AShooterCharacter* ShooterCharacterToRegister);

	UPROPERTY(EditDefaultsOnly)
	bool bBasicOHHealthBarAssociation = false;
	
	TArray<AWaypoint*> GetAllWayPoints();
	void AddWayPoint(AWaypoint* WayPoint);
	
	TArray<ASP_AmmoPack*> GetAllAmmoPacks();
	void AddAmmoPack(ASP_AmmoPack* AmmoPack);

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
	TArray<ASP_AmmoPack*> AllAmmoPacks;
	
	UPROPERTY()
	TArray<AHealthPack*> AllHealthPacks;
};
