// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/AmmoPack.h"
#include "Actors/ShooterCharacter.h"
#include "Components/BoxComponent.h"
#include "GameMode/SimpleShooterGameModeBase.h"

// Sets default values
AAmmoPack::AAmmoPack()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxComponent->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AAmmoPack::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AAmmoPack::OnOverlapBegin);
	
	ASimpleShooterGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
	if (GameModeBase != nullptr)
	{
		GameModeBase->AddAmmoPack(this);
	}
}

// Called every frame
void AAmmoPack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RechargeTimer > 0.0f)
	{
		RechargeTimer -= DeltaTime;
		if (RechargeTimer <= 0.0f)
		{
			Mesh->SetMaterial(0, AmmoPackActiveMaterial);
			RechargeTimer = 0.0f;
		}
	}
}

void AAmmoPack::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(OtherActor);
	if (ShooterCharacter != nullptr && !IsRecharging() && ShooterCharacter->GetAmmoReservePercent() < 1.0f)
	{
		RechargeTimer = TimeToRecharge;
		Mesh->SetMaterial(0, AmmoPackInactiveMaterial);
		ShooterCharacter->AddAmmoReserve(AmmoAmount);
	}
}

bool AAmmoPack::IsRecharging()
{
	return RechargeTimer > 0.0f;
}

