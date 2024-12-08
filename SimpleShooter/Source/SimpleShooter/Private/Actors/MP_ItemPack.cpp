// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/MP_ItemPack.h"
#include "Actors/MP_ShooterCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
AMP_ItemPack::AMP_ItemPack()
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
void AMP_ItemPack::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AMP_ItemPack::OnOverlapBegin);
}

// Called every frame
void AMP_ItemPack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RechargeTimer > 0.0f)
	{
		RechargeTimer -= DeltaTime;
		if (RechargeTimer <= 0.0f)
		{
			//Reactivate the ammo pack
			Mesh->SetMaterial(0, ActiveMaterial);
			RechargeTimer = 0.0f;

			//Check next if there is still a shooter character within the box collision
			// Define the box bounds
			const FVector BoxCenter = GetActorLocation();
			const FVector BoxExtent((100.0f*GetActorScale().X)/2, (100.0f*GetActorScale().Y)/2, (100.0f*GetActorScale().Z)/2); // Half extents
			
			// Query all overlapping actors
			TArray<FOverlapResult> OverlapResults;
			FCollisionQueryParams QueryParams;
			QueryParams.AddIgnoredActor(this);  // Ignore the current actor

			// Perform overlap check
			const bool bHasOverlap = GetWorld()->OverlapMultiByObjectType(
				OverlapResults,
				BoxCenter,
				FQuat::Identity,
				FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn),
				FCollisionShape::MakeBox(BoxExtent),
				QueryParams
			);

			// Process the results
			if (bHasOverlap && OverlapResults.Num() > 0)
			{
				for (int i=0; i<OverlapResults.Num(); i++)
				{
					if (AMP_ShooterCharacter* ShooterCharacter = Cast<AMP_ShooterCharacter>(OverlapResults[i].GetActor()))
					{
						AttemptGivePackTo(ShooterCharacter);
					}
				}
			}
		}
	}
}

bool AMP_ItemPack::IsRecharging()
{
	return RechargeTimer > 0.0f;
}

void AMP_ItemPack::AttemptGivePackTo(AMP_ShooterCharacter* TargetShooterCharacter)
{
	if (!IsRecharging() && PackValidation(TargetShooterCharacter))
	{
		GivePackTo(TargetShooterCharacter);
	}
}

void AMP_ItemPack::GivePackTo(AMP_ShooterCharacter* TargetShooterCharacter)
{
	RechargeTimer = TimeToRecharge;
	Mesh->SetMaterial(0, InactiveMaterial);
}

bool AMP_ItemPack::PackValidation(AMP_ShooterCharacter* TargetShooterCharacter)
{
	return true;
}

void AMP_ItemPack::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (AMP_ShooterCharacter* ShooterCharacter = Cast<AMP_ShooterCharacter>(OtherActor))
	{
		AttemptGivePackTo(ShooterCharacter);
	}
}

