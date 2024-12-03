// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MP_ShooterCharacter.h"

#include "PlayMontageCallbackProxy.h"
#include "Actors/MP_Gun.h"
#include "Actors/RotationViewPointRef.h"


// Sets default values
AMP_ShooterCharacter::AMP_ShooterCharacter()
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMP_ShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Gun = GetWorld()->SpawnActor<AMP_Gun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), PBO_None);
	
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);

	RotationViewPointRef = GetWorld()->SpawnActor<ARotationViewPointRef>(
	RotationViewPointRefClass,
	FVector(0.0f, 0.0f, 0.0f),
	FRotator(0.0f, 0.0f, 0.0f)
);

	RotationViewPointRef->SetOwnerController(GetController());
	RotationViewPointRef->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	
}

// Called every frame
void AMP_ShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMP_ShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMP_ShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AMP_ShooterCharacter::LookUpRate);
	
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMP_ShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AMP_ShooterCharacter::LookRightRate);
	
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump); // already define in character class
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &AMP_ShooterCharacter::PullTrigger);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Released, this, &AMP_ShooterCharacter::ReleaseTrigger);
	PlayerInputComponent->BindAction(TEXT("Reload"), IE_Pressed, this, &AMP_ShooterCharacter::Reload);
}

ARotationViewPointRef* AMP_ShooterCharacter::GetRotationViewPointRef()
{
	return RotationViewPointRef;
}

float AMP_ShooterCharacter::GetHealthPercent() const
{
	return Health/MaxHealth;
}

float AMP_ShooterCharacter::GetAmmoReservePercent() const
{
	return (float)AmmoReserve/(float)MaxAmmoReserve;
}

float AMP_ShooterCharacter::GetAmmoTotalPercent() const
{
	int AmmoTotal = AmmoReserve + GetGunReference()->GetAmmoAmount();
	int AmmoMaxTotal = MaxAmmoReserve + GetGunReference()->GetMaxAmmo();
	
	return (float)AmmoTotal/(float)AmmoMaxTotal;
}

FString AMP_ShooterCharacter::GetAmmoReserveRatio() const
{
	return FString::FromInt(AmmoReserve) + "/" + FString::FromInt(MaxAmmoReserve);
}

AMP_Gun* AMP_ShooterCharacter::GetGunReference() const
{
	return Gun;
}

void AMP_ShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector()*AxisValue);
}

void AMP_ShooterCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector()*AxisValue);
}

void AMP_ShooterCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AMP_ShooterCharacter::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AMP_ShooterCharacter::PullTrigger()
{
	if (HasAuthority())
	{
		MulticastPullTrigger();
	}
	else
	{
		ServerPullTrigger();
	}
}

bool AMP_ShooterCharacter::ServerPullTrigger_Validate()
{
	// Optional: Add validation logic here (e.g., preventing cheating)
	return true;
}

void AMP_ShooterCharacter::ServerPullTrigger_Implementation()
{
	MulticastPullTrigger();
}

void AMP_ShooterCharacter::MulticastPullTrigger_Implementation()
{
	// Perform the shooting logic on all clients
	PerformPullTrigger();
}

void AMP_ShooterCharacter::PerformPullTrigger()
{
	if (Gun != nullptr)
	{
		Gun->PullTrigger();
	}
}

void AMP_ShooterCharacter::ReleaseTrigger()
{
	if (HasAuthority())
	{
		MulticastReleaseTrigger();
	}
	else
	{
		ServerReleaseTrigger();
	}
}

bool AMP_ShooterCharacter::ServerReleaseTrigger_Validate()
{
	// Optional: Add validation logic here (e.g., preventing cheating)
	return true;
}

void AMP_ShooterCharacter::ServerReleaseTrigger_Implementation()
{
	MulticastReleaseTrigger();
}

void AMP_ShooterCharacter::MulticastReleaseTrigger_Implementation()
{
	// Perform the shooting logic on all clients
	PerformReleaseTrigger();
}

void AMP_ShooterCharacter::PerformReleaseTrigger()
{
	if (Gun != nullptr)
	{
		Gun->ReleaseTrigger();	
	}
}

void AMP_ShooterCharacter::Reload()
{
	if (!IsReloading && AmmoReserve > 0 && Gun->GetAmmoPercent() < 1.0f )
	{
		ProxyReloadPlayMontage = UPlayMontageCallbackProxy::CreateProxyObjectForPlayMontage(
			GetMesh(),
			ReloadMontage
		);
		
		ProxyReloadPlayMontage->OnCompleted.AddDynamic(this, &AMP_ShooterCharacter::OnReloadAnimationCompleted);
		IsReloading = true;
	}
	else
	{
		//TODO: clip sound
	}
}

void AMP_ShooterCharacter::OnReloadAnimationCompleted(FName NotifyName)
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
