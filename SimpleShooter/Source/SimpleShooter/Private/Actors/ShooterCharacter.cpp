// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleShooter/Public/Actors/ShooterCharacter.h"
#include "Actors/Gun.h"
#include "GameMode/SimpleShooterGameModeBase.h"
#include "Components/CapsuleComponent.h"
#include "PlayMontageCallbackProxy.h"
#include "Actors/Stimuli/VisualStimuli/VisualStimuli_ShooterCharacter.h"
#include "Controllers/ShooterPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Utility/NavMeshUtility.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), PBO_None);
	
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);

	//Add OHHealthBar to the Only player instantiated
	//TODO: when multiplayer arrive, find a way to do this on every player controller
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (GetController()->GetUniqueID() != PlayerController->GetUniqueID())
	{
		Cast<AShooterPlayerController>(PlayerController)->AddOHHealthBar(this);
	}

	NavMeshUtility = NewObject<UNavMeshUtility>(GetTransientPackage(), UNavMeshUtility::StaticClass());

	AVisualStimuli_ShooterCharacter* VisualStimuliShooterCharacter = GetWorld()->SpawnActor<AVisualStimuli_ShooterCharacter>(
		VisualStimuli_ShooterCharacterClass,
		FVector(0.0f, 0.0f, 0.0f),
		FRotator(0.0f, 0.0f, 0.0f)
	);

	VisualStimuliShooterCharacter->SetShooterCharacterRef(this);
	VisualStimuliShooterCharacter->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
}

bool AShooterCharacter::IsDead() const
{
	return Health <= 0.0f;
}

bool AShooterCharacter::GetIsReloading() const
{
	return IsReloading;
}

float AShooterCharacter::GetHealthPercent() const
{
	return Health/MaxHealth;
}

float AShooterCharacter::GetAmmoReservePercent() const
{
	return (float)AmmoReserve/(float)MaxAmmoReserve;
}

FString AShooterCharacter::GetAmmoReserveRatio() const
{
	return FString::FromInt(AmmoReserve) + "/" + FString::FromInt(MaxAmmoReserve); 
}

AGun* AShooterCharacter::GetGunReference() const
{
	return Gun;
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AShooterCharacter::LookUpRate);
	
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AShooterCharacter::LookRightRate);
	
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump); // already define in character class
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &AShooterCharacter::PullTrigger);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Released, this, &AShooterCharacter::ReleaseTrigger);
	PlayerInputComponent->BindAction(TEXT("Reload"), IE_Pressed, this, &AShooterCharacter::Reload);

	PlayerInputComponent->BindAction(TEXT("SelfDamage"), IE_Pressed, this, &AShooterCharacter::SelfDamage);
}

float AShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	float DamageToApply =  Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;

	if (IsDead())
	{
		ASimpleShooterGameModeBase* GameMode =  GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
		
		DetachFromControllerPendingDestroy();
		ReleaseTrigger();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	
	return DamageToApply;
}

float AShooterCharacter::Heal(float HealAmount)
{
	if (Health+HealAmount <= MaxHealth)
	{
		Health += HealAmount;
		return HealAmount;
	}
	else
	{
		Health = MaxHealth;
		return (Health+HealAmount) - MaxHealth;
	}
}

int AShooterCharacter::AddAmmoReserve(int AmmoAmount)
{
	if (AmmoReserve+AmmoAmount <= MaxAmmoReserve)
	{
		AmmoReserve += AmmoAmount;
		return AmmoAmount;
	}
	else
	{
		AmmoReserve = MaxAmmoReserve;
		return (AmmoReserve+AmmoAmount) - MaxAmmoReserve;
	}
}

void AShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector()*AxisValue);
}

void AShooterCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector()*AxisValue);
}

void AShooterCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::PullTrigger()
{
	Gun->PullTrigger();
}

void AShooterCharacter::PullTrigger(float AIOffsetRadius)
{
	Gun->PullTrigger(AIOffsetRadius);
}

void AShooterCharacter::ReleaseTrigger()
{
	Gun->ReleaseTrigger();
}

void AShooterCharacter::Reload()
{	
	if (!IsReloading && AmmoReserve > 0 && Gun->GetAmmoPercent() < 1.0f )
	{
		ProxyReloadPlayMontage = UPlayMontageCallbackProxy::CreateProxyObjectForPlayMontage(
			GetMesh(),
			ReloadMontage
		);
		
		ProxyReloadPlayMontage->OnCompleted.AddDynamic(this, &AShooterCharacter::OnReloadAnimationCompleted);
		IsReloading = true;
	}
	else
	{
		//TODO: clip sound
	}
}

#if WITH_EDITOR
void AShooterCharacter::PostActorCreated()
{
	Super::PostActorCreated();
	GenerateEditorAnchorPositionVisualisation();	
}

void AShooterCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	GenerateEditorAnchorPositionVisualisation();
}

void AShooterCharacter::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);
	GenerateEditorAnchorPositionVisualisation();
}
#endif

void AShooterCharacter::GenerateEditorAnchorPositionVisualisation() const
{
#if WITH_EDITOR
	if (const UWorld* World = GetWorld())
	{
		if (World->WorldType == EWorldType::EditorPreview)
		{
			UKismetSystemLibrary::FlushPersistentDebugLines(this);
			const FVector ActorLocation = GetActorLocation();
			
			// HealtBar Anchor
			DrawDebugSphere(GetWorld(), ActorLocation + HealthBarAnchor, 5.0f, 12, FColor::Cyan, true, 0.0f, 0, 0.0f);
		}
	}
#endif
}

void AShooterCharacter::OnReloadAnimationCompleted(FName NotifyName)
{
	IsReloading = false;
	int ReloadAmount = Gun->GetMaxAmmo();
	int CurrentReloadAmount = ReloadAmount;
	if (AmmoReserve - ReloadAmount < 0)
	{
		CurrentReloadAmount = ReloadAmount - FMath::Abs(AmmoReserve-ReloadAmount);
	}
	
	AmmoReserve -= CurrentReloadAmount;
	const int LeftOver = Gun->Reload(CurrentReloadAmount);
	AmmoReserve += LeftOver;
}

void AShooterCharacter::SelfDamage()
{
	Health -= 10.0f;
}

