// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "Actors/SinglePlayer/SP_HealthPack.h"
#include "Actors/SinglePlayer/SP_Waypoint.h"
#include "GameFramework/GameMode.h"
#include "SP_ShooterGameMode.generated.h"

/**
 * 
 */

class UTeamManager;
class ASP_ShooterCharacter;
class ASP_AmmoPack;
class ASP_SpawningPoint;
class ASP_HealthPack;

UCLASS()
class SIMPLESHOOTER_API ASP_ShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASP_ShooterGameMode();

	UFUNCTION()
	virtual void OnShooterCharacterDeath(ASP_ShooterCharacter* DeadShooterCharacter);

	virtual void AddShooterCharacterCount(ASP_ShooterCharacter* ShooterCharacterToRegister);

	UPROPERTY(EditDefaultsOnly)
	bool bBasicOHHealthBarAssociation = false;
	
	TArray<ASP_Waypoint*> GetAllWayPoints();
	void AddWayPoint(ASP_Waypoint* WayPoint);
	
	TArray<ASP_AmmoPack*> GetAllAmmoPacks();
	void AddAmmoPack(ASP_AmmoPack* AmmoPack);

	TArray<ASP_HealthPack*> GetAllHealthPacks();
	void AddHealthPack(ASP_HealthPack* HealthPack);

	void RegisterEvent (ASP_ShooterCharacter* ShooterCharacterRef);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Global Object")
	UTeamManager* FactionManagerComponent;

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY()
	TArray<ASP_SpawningPoint*> AllSpawnPoints;

	UPROPERTY()
	TArray<ASP_SpawningPoint*> AllRedSpawnPoints;

	UPROPERTY()
	TArray<ASP_SpawningPoint*> AllBlueSpawnPoints;
	
	UPROPERTY()
	TArray<ASP_Waypoint*> AllWayPoints;
	
	UPROPERTY()
	TArray<ASP_AmmoPack*> AllAmmoPacks;
	
	UPROPERTY()
	TArray<ASP_HealthPack*> AllHealthPacks;
};
