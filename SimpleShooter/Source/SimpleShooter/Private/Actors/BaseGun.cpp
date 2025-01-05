// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/BaseGun.h"

// Sets default values
ABaseGun::ABaseGun()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ABaseGun::BeginPlay()
{
	Super::BeginPlay();
	Ammo = MaxAmmo;
}

void ABaseGun::PullTrigger()
{
	if (!TriggerPulled)
	{
		FireTimerTimerDel.BindUFunction(this, FName("Fire"));
		GetWorld()->GetTimerManager().SetTimer(
			FireTimerHandle,
			FireTimerTimerDel,
			TimeBetweenRound,
			true,
			0.0f
		);
		
		TriggerPulled = true;
	}
}

void ABaseGun::ReleaseTrigger()
{
	if (TriggerPulled)
	{
		GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
		TriggerPulled = false;
	}
}

int ABaseGun::Reload(int AmmoAmount)
{
	int LeftOver = 0;
	
	if (Ammo + AmmoAmount > MaxAmmo)
	{
		LeftOver = (Ammo + AmmoAmount) - MaxAmmo;
		Ammo += AmmoAmount-LeftOver;
	}
	else
	{
		Ammo += AmmoAmount;
	}

	return LeftOver;
}

FString ABaseGun::GetAmmoRatio() const
{
	return FString::FromInt(Ammo) + "/" + FString::FromInt(MaxAmmo); 
}

float ABaseGun::GetAmmoPercent() const
{
	return static_cast<float>(Ammo)/static_cast<float>(MaxAmmo);
}

int ABaseGun::GetAmmoAmount() const
{
	return Ammo;
}

int ABaseGun::GetMaxAmmo() const
{
	return MaxAmmo;
}

bool ABaseGun::UseAmmo()
{
	if (Ammo-1 > 0)
	{
		Ammo--;
		return true;
	}
	else
	{
		Ammo = 0;
		return false;
	}
}

AController* ABaseGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return nullptr;
	
	return OwnerPawn->GetController();
}

