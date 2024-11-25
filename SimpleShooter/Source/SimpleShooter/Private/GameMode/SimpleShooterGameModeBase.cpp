// Fill out your copyright notice in the Description page of Project Settings.
#include "GameMode/SimpleShooterGameModeBase.h"

#include "Actors/AmmoPack.h"
#include "Actors/SpawningPoint.h"
#include "Actors/ShooterCharacter.h"

ASimpleShooterGameModeBase::ASimpleShooterGameModeBase()
{
	FactionManagerComponent = CreateDefaultSubobject<UTeamManager>(TEXT("Faction Manager Component"));
	bUseSeamlessTravel = true;
}

void ASimpleShooterGameModeBase::HandleSeamlessTravelPlayer(AController*& Controller)
{
	Super::HandleSeamlessTravelPlayer(Controller);
}

void ASimpleShooterGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ASimpleShooterGameModeBase::OnShooterCharacterDeath(AShooterCharacter* DeadShooterCharacter)
{
	
}

TArray<AWaypoint*> ASimpleShooterGameModeBase::GetAllWayPoints()
{
	return AllWayPoints;
}

void ASimpleShooterGameModeBase::AddWayPoint(AWaypoint* Waypoint)
{
	AllWayPoints.Add(Waypoint);
}

TArray<AAmmoPack*> ASimpleShooterGameModeBase::GetAllAmmoPacks()
{
	return AllAmmoPacks;
}

void ASimpleShooterGameModeBase::AddAmmoPack(AAmmoPack* AmmoPack)
{
	AllAmmoPacks.Add(AmmoPack);
}

TArray<AHealthPack*> ASimpleShooterGameModeBase::GetAllHealthPacks()
{
	return AllHealthPacks;
}

void ASimpleShooterGameModeBase::AddHealthPack(AHealthPack* HealthPack)
{
	AllHealthPacks.Add(HealthPack);
}

void ASimpleShooterGameModeBase::RegisterEvent(AShooterCharacter* ShooterCharacterRef)
{
	ShooterCharacterRef->OnDeadEvent.AddDynamic(this, &ASimpleShooterGameModeBase::OnShooterCharacterDeath);
}



