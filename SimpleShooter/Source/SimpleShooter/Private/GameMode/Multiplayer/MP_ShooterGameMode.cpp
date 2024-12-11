// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/Multiplayer/MP_ShooterGameMode.h"
#include "Actors/MP_AmmoPack.h"
#include "Actors/MP_SpawningPoint.h"
#include "Actors/MP_ShooterCharacter.h"

AMP_ShooterGameMode::AMP_ShooterGameMode()
{
	FactionManagerComponent = CreateDefaultSubobject<UTeamManager>(TEXT("Faction Manager Component"));
}

void AMP_ShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AMP_ShooterGameMode::OnShooterCharacterDeath(AMP_ShooterCharacter* DeadShooterCharacter)
{
	
}

TArray<AMP_Waypoint*> AMP_ShooterGameMode::GetAllWayPoints()
{
	return AllWayPoints;
}

void AMP_ShooterGameMode::AddWayPoint(AMP_Waypoint* Waypoint)
{
	AllWayPoints.Add(Waypoint);
}

TArray<AMP_AmmoPack*> AMP_ShooterGameMode::GetAllAmmoPacks()
{
	return AllAmmoPacks;
}

void AMP_ShooterGameMode::AddAmmoPack(AMP_AmmoPack* AmmoPack)
{
	AllAmmoPacks.Add(AmmoPack);
}

TArray<AMP_HealthPack*> AMP_ShooterGameMode::GetAllHealthPacks()
{
	return AllHealthPacks;
}

void AMP_ShooterGameMode::AddHealthPack(AMP_HealthPack* HealthPack)
{
	AllHealthPacks.Add(HealthPack);
}

void AMP_ShooterGameMode::RegisterEvent(AMP_ShooterCharacter* ShooterCharacterRef)
{
	ShooterCharacterRef->OnDeadEvent.AddDynamic(this, &AMP_ShooterGameMode::OnShooterCharacterDeath);
}