// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleShooter/Public/Actors/SinglePlayer/SP_ShooterCharacter.h"
#include "Actors/SinglePlayer/SP_Gun.h"
#include "GameMode/SinglePlayer/SP_ShooterGameMode.h"
#include "Components/CapsuleComponent.h"
#include "PlayMontageCallbackProxy.h"
#include "Actors/RotationViewPointRef.h"
#include "Actors/SinglePlayer/SP_ShooterSpectatorPawn.h"
#include "Components/SphereComponent.h"
#include "Stimuli/VisualStimuli/VisualStimuli_ShooterCharacter.h"
#include "Controllers/SinglePlayer/SP_ShooterPlayerController.h"
#include "Engine/DamageEvents.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Utility/NavMeshUtility.h"

// Sets default values
ASP_ShooterCharacter::ASP_ShooterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create and setup head collision sphere
	HeadCollision = CreateDefaultSubobject<USphereComponent>(TEXT("HeadCollision"));
	HeadCollision->SetupAttachment(GetMesh());
	HeadCollision->SetCollisionProfileName(TEXT("OverlapAll")); // Adjust profile as needed
	HeadCollision->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ASP_ShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	
	Gun = GetWorld()->SpawnActor<ASP_Gun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), PBO_None);
	
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
	
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

	if (ASP_ShooterGameMode* ShooterGameMode = Cast<ASP_ShooterGameMode>(GetWorld()->GetAuthGameMode()))
	{
		ShooterGameMode->RegisterEvent(this);
		ShooterGameMode->AddShooterCharacterCount(this);

		if (ShooterGameMode->bBasicOHHealthBarAssociation)
		{
			if (ASP_ShooterPlayerController* PlayerController = Cast<ASP_ShooterPlayerController>(GetWorld()->GetFirstPlayerController()))
			{
				if (Cast<ASP_ShooterCharacter>(PlayerController->GetPawn()) != this)
				{
					PlayerController->AddOHHealthBar(this);
				}
			}
		}
	}
	
	// Set initial collision sphere size
	HeadCollision->SetSphereRadius(HeadshotRadius-5.0f);
	UpdateHeadCollision();
}

bool ASP_ShooterCharacter::IsDead() const
{
	return Dead;
}

FVector ASP_ShooterCharacter::GetHeadAnchorLocation() const
{
	if (USkeletalMeshComponent* LocalMesh = GetMesh())
	{
		FTransform BoneTransform = LocalMesh->GetSocketTransform(HeadBoneName);
		return BoneTransform.TransformPosition(HeadAnchorOffset);
	}
	
	return GetActorLocation();
}

bool ASP_ShooterCharacter::GetIsReloading() const
{
	return IsReloading;
}

float ASP_ShooterCharacter::GetAmmoReservePercent() const
{
	return (float)AmmoReserve/(float)MaxAmmoReserve;
}

float ASP_ShooterCharacter::GetAmmoTotalPercent() const
{
	int AmmoTotal = AmmoReserve + GetGunReference()->GetAmmoAmount();
	int AmmoMaxTotal = MaxAmmoReserve + GetGunReference()->GetMaxAmmo();
	
	return (float)AmmoTotal/(float)AmmoMaxTotal;
}

FString ASP_ShooterCharacter::GetAmmoReserveRatio() const
{
	return FString::FromInt(AmmoReserve) + "/" + FString::FromInt(MaxAmmoReserve); 
}

ASP_Gun* ASP_ShooterCharacter::GetGunReference() const
{
	return Gun;
}

// Called every frame
void ASP_ShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Update collision sphere position every frame
	UpdateHeadCollision();
	
	if (bShowHeadshotDebug)
	{
		DrawDebugSphere(
			GetWorld(),
			GetHeadAnchorLocation(),
			HeadshotRadius,
			24,
			FColor::Green,
			false,
			-1.0f,
			0,
			1.0f
		);
	}
}

void ASP_ShooterCharacter::UpdateHeadCollision()
{
	// Update collision sphere location to match anchor point
	FVector NewLocation = GetHeadAnchorLocation();
	HeadCollision->SetWorldLocation(NewLocation);
}

// Called to bind functionality to input
void ASP_ShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ASP_ShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &ASP_ShooterCharacter::LookUpRate);
	
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ASP_ShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &ASP_ShooterCharacter::LookRightRate);
	
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump); // already define in character class
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &ASP_ShooterCharacter::PullTrigger);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Released, this, &ASP_ShooterCharacter::ReleaseTrigger);
	PlayerInputComponent->BindAction(TEXT("Reload"), IE_Pressed, this, &ASP_ShooterCharacter::Reload);

	PlayerInputComponent->BindAction(TEXT("SelfDamage"), IE_Pressed, this, &ASP_ShooterCharacter::SelfDamage);
	PlayerInputComponent->BindAction(TEXT("ToggleDebugSpectatorMode"), IE_Pressed, this, &ASP_ShooterCharacter::ActivateDebugSpectatorMode);
}

float ASP_ShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	if (DamageEvent.IsOfType(FPointDamageEvent::ClassID))
	{
		const FPointDamageEvent* PointDamageEvent = static_cast<const FPointDamageEvent*>(&DamageEvent);
		FVector ImpactPoint = PointDamageEvent->HitInfo.ImpactPoint;
        
		// Get current head location and check distance
		float DistanceToHead = FVector::Distance(GetHeadAnchorLocation(), ImpactPoint);
        
		if (DistanceToHead <= HeadshotRadius)
		{
			DamageAmount *= HeadshotMultiplier;

			if (bShowHeadshotDebug && GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, 
					FString::Printf(TEXT("Headshot! Distance: %f, Damage: %f"), 
					DistanceToHead, DamageAmount));

				UE_LOG(LogTemp, Warning, TEXT("Headshot! Distance: %f, Damage: %f"), DistanceToHead, DamageAmount);
				
				DrawDebugSphere(GetWorld(), ImpactPoint, 5.0f, 12, FColor::Red, 
					false, 2.0f, 0, 1.0f);
                
				DrawDebugLine(GetWorld(), GetHeadAnchorLocation(), ImpactPoint, 
					FColor::Yellow, false, 2.0f, 0, 1.0f);
			}
		}
	}
	
	float DamageToApply =  Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	
	DamageToApply = FMath::Min(Health, DamageToApply);
	if (bShowHeadshotDebug && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, 
		FString::Printf(TEXT("Health before damage applied:  %f"), 
		Health));
		UE_LOG(LogTemp, Warning, TEXT("Health before damage applied: %f"), Health);
	}
	
	Health -= DamageToApply;
	
	if (bShowHeadshotDebug && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, 
		FString::Printf(TEXT("Final Health :  %f"), 
		Health));
		
		UE_LOG(LogTemp, Warning, TEXT("Final Health: %f"), Health);
	}
	
	if (Health <= 0.0f)
	{
		Death();
	}
	
	return DamageToApply;
}

void ASP_ShooterCharacter::Death()
{
	if (!IsDead())
	{
		ReleaseTrigger();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		VSShooterCharacter->Destroy();
		RotationViewPointRef->Destroy();

		Dead = true;

		// Become spectator
		ASP_ShooterSpectatorPawn* SpectatorPawn = GetWorld()->SpawnActor<ASP_ShooterSpectatorPawn>(
			ShooterSpectatorPawnClass,
			GetActorLocation(),
			GetActorRotation()
		);
		SpectatorPawn->SetTeam(GetTeam());

		ASP_ShooterPlayerController* ShooterPlayerController = Cast<ASP_ShooterPlayerController>(GetController());
		DetachFromControllerPendingDestroy();
		if (ShooterPlayerController != nullptr)
		{
			ShooterPlayerController->Possess(SpectatorPawn);
		}
		
		OnDeadEvent.Broadcast(this);
	}
}

float ASP_ShooterCharacter::Heal(float HealAmount)
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

int ASP_ShooterCharacter::AddAmmoReserve(int AmmoAmount)
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

void ASP_ShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector()*AxisValue);
}

void ASP_ShooterCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector()*AxisValue);
}

void ASP_ShooterCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void ASP_ShooterCharacter::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void ASP_ShooterCharacter::PullTrigger()
{
	if (Gun != nullptr)
	{
		Gun->PullTrigger();
	}
}

void ASP_ShooterCharacter::ReleaseTrigger()
{
	if (Gun != nullptr)
	{
		Gun->ReleaseTrigger();	
	}
}

void ASP_ShooterCharacter::Reload()
{	
	if (!IsReloading && AmmoReserve > 0 && Gun->GetAmmoPercent() < 1.0f )
	{
		ProxyReloadPlayMontage = UPlayMontageCallbackProxy::CreateProxyObjectForPlayMontage(
			GetMesh(),
			ReloadMontage
		);
		
		ProxyReloadPlayMontage->OnCompleted.AddDynamic(this, &ASP_ShooterCharacter::OnReloadAnimationCompleted);
		IsReloading = true;
	}
	else
	{
		//TODO: clip sound
	}
}

float ASP_ShooterCharacter::GetHealth() const
{
	return Health;
}

float ASP_ShooterCharacter::GetMaxHealth() const
{
	return MaxHealth;
}

#if WITH_EDITOR
void ASP_ShooterCharacter::PostActorCreated()
{
	Super::PostActorCreated();
	GenerateEditorAnchorPositionVisualisation();	
}

void ASP_ShooterCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	GenerateEditorAnchorPositionVisualisation();
}

void ASP_ShooterCharacter::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);
	GenerateEditorAnchorPositionVisualisation();
}
#endif

void ASP_ShooterCharacter::GenerateEditorAnchorPositionVisualisation() const
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

void ASP_ShooterCharacter::ActivateDebugSpectatorMode()
{
	ASP_ShooterPlayerController* ShooterPlayerController = Cast<ASP_ShooterPlayerController>(GetController());
	if (ShooterPlayerController != nullptr)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		GEngine->Exec(GetWorld(), TEXT("r.MotionBlurQuality 0"));
		
		ASP_ShooterSpectatorPawn* ShooterSpectatorPawn = GetWorld()->SpawnActor<ASP_ShooterSpectatorPawn>(
			ShooterSpectatorPawnClass,
			GetActorLocation(),
			GetActorRotation()
		);
		
		UnPossessed();
		ShooterSpectatorPawn->SetPlayerShooterCharacter(this);
		ShooterPlayerController->SetTickableWhenPaused(true);
		ShooterSpectatorPawn->SetTickableWhenPaused(true);
		ShooterPlayerController->Possess(ShooterSpectatorPawn);
	}
}

void ASP_ShooterCharacter::OnReloadAnimationCompleted(FName NotifyName)
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

void ASP_ShooterCharacter::SelfDamage()
{
	Health -= 10.0f;
}

AVisualStimuli_ShooterCharacter* ASP_ShooterCharacter::GetVSShooterCharacter() 
{
	return VSShooterCharacter;
}

ARotationViewPointRef* ASP_ShooterCharacter::GetRotationViewPointRef()
{
	return RotationViewPointRef;
}