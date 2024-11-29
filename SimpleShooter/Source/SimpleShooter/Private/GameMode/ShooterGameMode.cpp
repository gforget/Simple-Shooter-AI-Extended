// Fill out your copyright notice in the Description page of Project Settings.
#include "GameMode/ShooterGameMode.h"

#include "Actors/AmmoPack.h"
#include "Actors/SpawningPoint.h"
#include "Actors/ShooterCharacter.h"

AShooterGameMode::AShooterGameMode()
{
	FactionManagerComponent = CreateDefaultSubobject<UTeamManager>(TEXT("Faction Manager Component"));
}

void AShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AShooterGameMode::OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter)
{
	
}

TArray<AWaypoint*> AShooterGameMode::GetAllWayPoints()
{
	return AllWayPoints;
}

void AShooterGameMode::AddWayPoint(AWaypoint* Waypoint)
{
	AllWayPoints.Add(Waypoint);
}

TArray<AAmmoPack*> AShooterGameMode::GetAllAmmoPacks()
{
	return AllAmmoPacks;
}

void AShooterGameMode::AddAmmoPack(AAmmoPack* AmmoPack)
{
	AllAmmoPacks.Add(AmmoPack);
}

TArray<AHealthPack*> AShooterGameMode::GetAllHealthPacks()
{
	return AllHealthPacks;
}

void AShooterGameMode::AddHealthPack(AHealthPack* HealthPack)
{
	AllHealthPacks.Add(HealthPack);
}

void AShooterGameMode::RegisterEvent(AShooterCharacter* ShooterCharacterRef)
{
	ShooterCharacterRef->OnDeadEvent.AddDynamic(this, &AShooterGameMode::OnShooterCharacterDeath);
}



