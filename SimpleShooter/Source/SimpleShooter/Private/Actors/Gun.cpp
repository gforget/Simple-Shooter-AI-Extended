// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/DamageEvents.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::Fire(float AIOffsetRadius)
{
	if (UseAmmo())
	{
		UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
		UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
	
		FHitResult Hit;
		FVector ShotDirection;
		bool bSuccess = GunTrace(Hit, ShotDirection, AIOffsetRadius);

		if (bSuccess)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
			UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ImpactSound, Hit.Location);
		
			AActor* HitActor = Hit.GetActor();
			if (HitActor != nullptr)
			{
				FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
				AController* OwnerController = GetOwnerController();
				HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
			}
		}
	}
	else
	{
		//TODO : clip sound
	}
}

void AGun::PullTrigger(float AIOffsetRadius)
{
	FireTimerTimerDel.BindUFunction(this, FName("Fire"), AIOffsetRadius);
	GetWorld()->GetTimerManager().SetTimer(
		FireTimerHandle,
		FireTimerTimerDel,
		TimeBetweenRound,
		true,
		0.0f
	);
}

void AGun::ReleaseTrigger()
{
	GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	Ammo = MaxAmmo;
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection, float AIOffsetRadius)
{
	const AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr) return false;
	
	FVector Location;
	FRotator Rotation;
	
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShotDirection = -Rotation.Vector();
	
	FVector End = Location + Rotation.Vector()*MaxRange;
	
	//Random offset
	FVector HorizontalAxis3D = Rotation.Vector().Cross(FVector::UpVector);
	
	FVector2D result = FVector2D(FMath::VRand()); 
	result.Normalize();
	result *= FMath::RandRange(AIOffsetRadius/2.0f,BaseOffsetRadius+AIOffsetRadius);
	
	float UpFinalPosition = End.Z + result.Y;
	FVector2D HorizontalAxis = FVector2D(HorizontalAxis3D.X, HorizontalAxis3D.Y);
	FVector2D HorizontalFinalPosition = FVector2D(End.X, End.Y) + HorizontalAxis*result.X;
	
	End.X += HorizontalFinalPosition.X;
	End.Y += HorizontalFinalPosition.Y;
	End.Z += UpFinalPosition;
	//End Random offset
	
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

bool AGun::UseAmmo()
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

int AGun::Reload(int AmmoAmount)
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

int AGun::GetMaxAmmo() const
{
	return MaxAmmo;
}

FString AGun::GetAmmoRatio() const
{
	return FString::FromInt(Ammo) + "/" + FString::FromInt(MaxAmmo); 
}

float AGun::GetAmmoPercent() const
{
	return (float)Ammo/(float)MaxAmmo;
}

int AGun::GetAmmoAmount() const
{
	return Ammo;
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return nullptr;
	
	return OwnerPawn->GetController();
}

