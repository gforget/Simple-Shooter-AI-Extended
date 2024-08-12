// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/HealthPack.h"
#include "Actors/ShooterCharacter.h"
#include "GameMode/SimpleShooterGameModeBase.h"

// Sets default values
AHealthPack::AHealthPack()
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
void AHealthPack::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AHealthPack::OnOverlapBegin);
	
	ASimpleShooterGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
	if (GameModeBase != nullptr)
	{
		GameModeBase->AddHealthPack(this);
	}
}

// Called every frame
void AHealthPack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (RechargeTimer > 0.0f)
	{
		RechargeTimer -= DeltaTime;
		if (RechargeTimer <= 0.0f)
		{
			Mesh->SetMaterial(0, HealthPackActiveMaterial);
			RechargeTimer = 0.0f;
		}
	}
}

void AHealthPack::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(OtherActor);
	if (ShooterCharacter != nullptr && !IsRecharging() && ShooterCharacter->GetHealthPercent() < 1.0f)
	{
		RechargeTimer = TimeToRecharge;
		Mesh->SetMaterial(0, HealthPackInactiveMaterial);
		ShooterCharacter->Heal(HealAmount);
	}
}

bool AHealthPack::IsRecharging()
{
	return RechargeTimer > 0.0f;
}

