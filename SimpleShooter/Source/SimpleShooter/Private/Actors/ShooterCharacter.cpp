// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleShooter/Public/Actors/ShooterCharacter.h"
#include "Actors/Gun.h"
#include "GameMode/SimpleShooterGameModeBase.h"
#include "Components/CapsuleComponent.h"
#include "PlayMontageCallbackProxy.h"
#include "Actors/RotationViewPointRef.h"
#include "Actors/ShooterSpectatorPawn.h"
#include "Stimuli/VisualStimuli/VisualStimuli_ShooterCharacter.h"
#include "Controllers/ShooterPlayerController.h"
#include "GameMode/KillEmAllGameMode.h"
#include "Kismet/GameplayStatics.h"
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

	VSShooterCharacter = GetWorld()->SpawnActor<AVisualStimuli_ShooterCharacter>(
		VisualStimuli_ShooterCharacterClass,
		FVector(0.0f, 0.0f, 0.0f),
		FRotator(0.0f, 0.0f, 0.0f)
	);

	VSShooterCharacter->SetShooterCharacterRef(this);
	VSShooterCharacter->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);

	RotationViewPointRef = GetWorld()->SpawnActor<ARotationViewPointRef>(
		RotationViewPointRefClass,
		FVector(0.0f, 0.0f, 0.0f),
		FRotator(0.0f, 0.0f, 0.0f)
	);

	RotationViewPointRef->SetOwnerController(GetController());
	RotationViewPointRef->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);

	Cast<ASimpleShooterGameModeBase>(GetWorld()->GetAuthGameMode())->RegisterEvent(this);

	if (AKillEmAllGameMode* KillEmAllGameMode = Cast<AKillEmAllGameMode>(GetWorld()->GetAuthGameMode()))
	{
		KillEmAllGameMode->AddShooterCharacterCount(this);
	}
}

bool AShooterCharacter::IsDead() const
{
	return Dead;
}

ETeam AShooterCharacter::GetTeam() const
{
	return Team;
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

float AShooterCharacter::GetAmmoTotalPercent() const
{
	int AmmoTotal = AmmoReserve + GetGunReference()->GetAmmoAmount();
	int AmmoMaxTotal = MaxAmmoReserve + GetGunReference()->GetMaxAmmo();
	
	return (float)AmmoTotal/(float)AmmoMaxTotal;
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
	PlayerInputComponent->BindAction(TEXT("ToggleDebugSpectatorMode"), IE_Pressed, this, &AShooterCharacter::ActivateDebugSpectatorMode);
}

float AShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	
	float DamageToApply =  Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;

	if (Health <= 0.0f)
	{
		Death();
	}
	
	return DamageToApply;
}

void AShooterCharacter::Death()
{
	if (!IsDead())
	{
		OnDeadEvent.Broadcast(this);
		
		ReleaseTrigger();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		VSShooterCharacter->Destroy();
		RotationViewPointRef->Destroy();

		Dead = true;

		// Become spectator
		ASpectatorPawn* SpectatorPawn = GetWorld()->SpawnActor<ASpectatorPawn>(
			SpectatorPawnClass,
			GetActorLocation(),
			GetActorRotation()
		);
		
		AShooterPlayerController* ShooterPlayerController = Cast<AShooterPlayerController>(GetController());
		DetachFromControllerPendingDestroy();
		if (ShooterPlayerController != nullptr)
		{
			ShooterPlayerController->Possess(SpectatorPawn);
		}
	}
}

float AShooterCharacter::Heal(float HealAmount)
{
	if (Health+HealAmount <= MaxHealth)
	{
		Health += HealAmount;
		OnHealEvent.Broadcast();
		return HealAmount;
	}
	else
	{
		Health = MaxHealth;
		OnHealEvent.Broadcast();
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

void AShooterCharacter::ReleaseTrigger()
{
	if (Gun != nullptr)
	{
		Gun->ReleaseTrigger();	
	}
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
			DrawDebugSphere(GetWorld(), ActorLocation + FootPositionAnchor, 5.0f, 12, FColor::Purple, true, 0.0f, 0, 0.0f);
			DrawDebugSphere(GetWorld(), ActorLocation + BodyPositionAnchor, 5.0f, 12, FColor::Blue, true, 0.0f, 0, 0.0f);
		}
	}
#endif
}

void AShooterCharacter::ActivateDebugSpectatorMode()
{
	AShooterPlayerController* ShooterPlayerController = Cast<AShooterPlayerController>(GetController());
	if (ShooterPlayerController != nullptr)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		GEngine->Exec(GetWorld(), TEXT("r.MotionBlurQuality 0"));
		
		AShooterSpectatorPawn* DebugShooterSpectatorPawn = GetWorld()->SpawnActor<AShooterSpectatorPawn>(
			DebugShooterSpectatorPawnClass,
			GetActorLocation(),
			GetActorRotation()
		);
		
		UnPossessed();
		DebugShooterSpectatorPawn->SetPlayerShooterCharacter(this);
		ShooterPlayerController->SetTickableWhenPaused(true);
		DebugShooterSpectatorPawn->SetTickableWhenPaused(true);
		ShooterPlayerController->Possess(DebugShooterSpectatorPawn);
	}
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

AVisualStimuli_ShooterCharacter* AShooterCharacter::GetVSShooterCharacter() 
{
	return VSShooterCharacter;
}

ARotationViewPointRef* AShooterCharacter::GetRotationViewPointRef()
{
	return RotationViewPointRef;
}

