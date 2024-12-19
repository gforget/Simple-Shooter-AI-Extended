// Fill out your copyright notice in the Description page of Project Settings.
#include "GameMode/SinglePlayer/SP_ShooterGameMode.h"

#include "Actors/SinglePlayer/SP_AmmoPack.h"
#include "Actors/SinglePlayer/SP_SpawningPoint.h"
#include "Actors/SinglePlayer/SP_ShooterCharacter.h"

ASP_ShooterGameMode::ASP_ShooterGameMode()
{
	FactionManagerComponent = CreateDefaultSubobject<UTeamManager>(TEXT("Faction Manager Component"));
}

void ASP_ShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ASP_ShooterGameMode::OnShooterCharacterDeath(ASP_ShooterCharacter* DeadShooterCharacter)
{
	
}

void ASP_ShooterGameMode::AddShooterCharacterCount(ASP_ShooterCharacter* ShooterCharacterToRegister)
{
}

TArray<ASP_Waypoint*> ASP_ShooterGameMode::GetAllWayPoints()
{
	return AllWayPoints;
}

void ASP_ShooterGameMode::AddWayPoint(ASP_Waypoint* Waypoint)
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

TArray<ASP_HealthPack*> ASP_ShooterGameMode::GetAllHealthPacks()
{
	return AllHealthPacks;
}

void ASP_ShooterGameMode::AddHealthPack(ASP_HealthPack* HealthPack)
{
	AllHealthPacks.Add(HealthPack);
}

void ASP_ShooterGameMode::RegisterEvent(ASP_ShooterCharacter* ShooterCharacterRef)
{
	ShooterCharacterRef->OnDeadEvent.AddDynamic(this, &ASP_ShooterGameMode::OnShooterCharacterDeath);
}



