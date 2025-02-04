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

class ABaseAmmoPack;
class ABaseHealthPack;
class ABaseShooterCharacter;
class UTeamManager;
class ASP_SpawningPoint;

UCLASS()
class SIMPLESHOOTER_API ASP_ShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASP_ShooterGameMode();

	UFUNCTION()
	virtual void OnShooterCharacterDeath(ABaseShooterCharacter* DeadShooterCharacter);

	virtual void AddShooterCharacterCount(ABaseShooterCharacter* ShooterCharacterToRegister);

	UPROPERTY(EditDefaultsOnly)
	bool bBasicOHHealthBarAssociation = false;
	
	TArray<ASP_Waypoint*> GetAllWayPoints();
	void AddWayPoint(ASP_Waypoint* WayPoint);
	
	TArray<ABaseAmmoPack*> GetAllAmmoPacks();
	void AddAmmoPack(ABaseAmmoPack* AmmoPack);

	TArray<ABaseHealthPack*> GetAllHealthPacks();
	void AddHealthPack(ABaseHealthPack* HealthPack);

	void RegisterEvent (ABaseShooterCharacter* ShooterCharacterRef);

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
	TArray<ABaseAmmoPack*> AllAmmoPacks;
	
	UPROPERTY()
	TArray<ABaseHealthPack*> AllHealthPacks;
};
