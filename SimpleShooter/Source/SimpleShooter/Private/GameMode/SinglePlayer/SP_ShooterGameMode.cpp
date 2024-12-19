// Fill out your copyright notice in the Description page of Project Settings.
#include "GameMode/SinglePlayer/SP_ShooterGameMode.h"

#include "Actors/SinglePlayer/SP_AmmoPack.h"
#include "Actors/SpawningPoint.h"
#include "Actors/ShooterCharacter.h"

ASP_ShooterGameMode::ASP_ShooterGameMode()
{
	FactionManagerComponent = CreateDefaultSubobject<UTeamManager>(TEXT("Faction Manager Component"));
}

void ASP_ShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ASP_ShooterGameMode::OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter)
{
	
}

void ASP_ShooterGameMode::AddShooterCharacterCount(AShooterCharacter* ShooterCharacterToRegister)
{
}

TArray<AWaypoint*> ASP_ShooterGameMode::GetAllWayPoints()
{
	return AllWayPoints;
}

void ASP_ShooterGameMode::AddWayPoint(AWaypoint* Waypoint)
{
	AllWayPoints.Add(Waypoint);
}

TArray<ASP_AmmoPack*> ASP_ShooterGameMode::GetAllAmmoPacks()
{
	return AllAmmoPacks;
}

void ASP_ShooterGameMode::AddAmmoPack(ASP_AmmoPack* AmmoPack)
{
	AllAmmoPacks.Add(AmmoPack);
}

TArray<AHealthPack*> ASP_ShooterGameMode::GetAllHealthPacks()
{
	return AllHealthPacks;
}

void ASP_ShooterGameMode::AddHealthPack(AHealthPack* HealthPack)
{
	AllHealthPacks.Add(HealthPack);
}

void ASP_ShooterGameMode::RegisterEvent(AShooterCharacter* ShooterCharacterRef)
{
	ShooterCharacterRef->OnDeadEvent.AddDynamic(this, &ASP_ShooterGameMode::OnShooterCharacterDeath);
}



