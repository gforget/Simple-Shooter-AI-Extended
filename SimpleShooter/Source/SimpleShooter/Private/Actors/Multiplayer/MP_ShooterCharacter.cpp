// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Multiplayer/MP_ShooterCharacter.h"

#include "PlayMontageCallbackProxy.h"
#include "Actors/Multiplayer/MP_Gun.h"
#include "Actors/RotationViewPointRef.h"
#include "Actors/Multiplayer/MP_ShooterSpectatorPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Controllers/Multiplayer/MP_ShooterPlayerController.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameMode/Multiplayer/ShooterGameMode/MP_ShooterGameState.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"


// Sets default values
AMP_ShooterCharacter::AMP_ShooterCharacter()
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;

	// Create and setup head collision sphere
	HeadCollision = CreateDefaultSubobject<USphereComponent>(TEXT("HeadCollision"));
	HeadCollision->SetupAttachment(GetMesh());
	HeadCollision->SetCollisionProfileName(TEXT("OverlapAll")); // Adjust profile as needed
	HeadCollision->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AMP_ShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	
	Gun = GetWorld()->SpawnActor<AMP_Gun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), PBO_None);

	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);

	if (!IsLocallyControlled())
	{
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		Cast<AMP_ShooterPlayerController>(PlayerController)->AddOHHealthBar(this);
	}
	
	RotationViewPointRef = GetWorld()->SpawnActor<ARotationViewPointRef>(
		RotationViewPointRefClass,
		FVector(0.0f, 0.0f, 0.0f),
		FRotator(0.0f, 0.0f, 0.0f)
	);

	RotationViewPointRef->SetOwnerController(GetController());
	RotationViewPointRef->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	
	if (AMP_ShooterGameState* GameState = Cast<AMP_ShooterGameState>(GetWorld()->GetGameState()))
	{
		GameState->AddShooterCharacterCount(this);
		GameState->RegisterEvent(this);
	}
	
	// Set initial collision sphere size
	HeadCollision->SetSphereRadius(HeadshotRadius-5.0f);
	UpdateHeadCollision();
}

void AMP_ShooterCharacter::PostActorCreated()
{
	Super::PostActorCreated();
	GenerateEditorAnchorPositionVisualisation();
}

void AMP_ShooterCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	GenerateEditorAnchorPositionVisualisation();
}

void AMP_ShooterCharacter::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);
	GenerateEditorAnchorPositionVisualisation();
}

void AMP_ShooterCharacter::GenerateEditorAnchorPositionVisualisation() const
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

FVector AMP_ShooterCharacter::GetHeadAnchorLocation() const
{
	if (USkeletalMeshComponent* LocalMesh = GetMesh())
	{
		FTransform BoneTransform = LocalMesh->GetSocketTransform(HeadBoneName);
		return BoneTransform.TransformPosition(HeadAnchorOffset);
	}
	
	return GetActorLocation();
}

bool AMP_ShooterCharacter::GetIsReloading() const
{
	return IsReloading;
}

// Called every frame
void AMP_ShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HasAuthority())
	{
		if (Controller)
		{
			FVector NewLocation;
			FRotator NewRotation;
			Controller->GetPlayerViewPoint(NewLocation, NewRotation);

			if (!ShooterViewPointLocation.Equals(NewLocation, 0.01f) || !ShooterViewPointRotation.Equals(NewRotation, 0.1f))
			{
				ShooterViewPointLocation = NewLocation;
				ShooterViewPointRotation = NewRotation;
			}
		}
	}

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

void AMP_ShooterCharacter::UpdateHeadCollision()
{
	// Update collision sphere location to match anchor point
	FVector NewLocation = GetHeadAnchorLocation();
	HeadCollision->SetWorldLocation(NewLocation);	
}

// Called to bind functionality to input
void AMP_ShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMP_ShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMP_ShooterCharacter::LookUp);
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

float AMP_ShooterCharacter::GetHealth() const
{
	return Health;
}

float AMP_ShooterCharacter::GetMaxHealth() const
{
	return MaxHealth;
}

// float AMP_ShooterCharacter::GetHealthPercent() const
// {
// 	return Health/MaxHealth;
// }

// float AMP_ShooterCharacter::GetAmmoReservePercent() const
// {
// 	return (float)AmmoReserve/(float)MaxAmmoReserve;
// }

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

//---- Look UP RPC ----/
void AMP_ShooterCharacter::LookUp(float AxisValue)
{
	if (Controller && AxisValue != 0.0f)
	{
		// Locally modify the rotation for immediate response
		FRotator NewRotation = Controller->GetControlRotation();
		NewRotation.Pitch -= AxisValue;
		
		UpdateControlRotation(NewRotation);

		// Send the rotation to the server
		if (!HasAuthority())
		{
			ServerSetControlRotation(NewRotation);
		}
	}
}

void AMP_ShooterCharacter::ServerSetControlRotation_Implementation(const FRotator& NewRotation)
{
	UpdateControlRotation(NewRotation); // Update the server's rotation
}

bool AMP_ShooterCharacter::ServerSetControlRotation_Validate(const FRotator& NewRotation)
{
	return true;
}

void AMP_ShooterCharacter::UpdateControlRotation(const FRotator& NewRotation)
{
	ReplicatedControlRotation = NewRotation;

	if (Controller)
	{
		Controller->SetControlRotation(NewRotation);
	}
}

void AMP_ShooterCharacter::OnRep_ControlRotation()
{
	if (!IsLocallyControlled())
	{
		UpdateControlRotation(ReplicatedControlRotation);
	}
}

//---- [END] Look UP RPC ----/

void AMP_ShooterCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AMP_ShooterCharacter::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

//---- Pull Trigger ----/
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

float AMP_ShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
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
		MulticastDeath();
	}
	
	return DamageToApply;
}

// float AMP_ShooterCharacter::Heal(float HealAmount)
// {
// 	if (Health+HealAmount <= MaxHealth)
// 	{
// 		Health += HealAmount;
// 		OnHealEvent.Broadcast();
// 		return HealAmount;
// 	}
// 	else
// 	{
// 		Health = MaxHealth;
// 		OnHealEvent.Broadcast();
// 		return (Health+HealAmount) - MaxHealth;
// 	}	
// }

int AMP_ShooterCharacter::AddAmmoReserve(int AmmoAmount)
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

void AMP_ShooterCharacter::MulticastDeath_Implementation()
{
	if (!IsDead())
	{
		ReleaseTrigger();
		
		GetCharacterMovement()->GravityScale = 0.0f; //client for some reason pass through floor when no collision
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
		//VSShooterCharacter->Destroy();
		RotationViewPointRef->Destroy();

		Dead = true;
		
		if (HasAuthority())
		{
			//Become spectator - Only Server has authority to spawn actor and assign control
			AMP_ShooterSpectatorPawn* SpectatorPawn = GetWorld()->SpawnActor<AMP_ShooterSpectatorPawn>(
				ShooterSpectatorPawnClass,
				GetActorLocation(),
				GetActorRotation()
			);
			SpectatorPawn->SetTeam(GetTeam());

			AMP_ShooterPlayerController* ShooterPlayerController = Cast<AMP_ShooterPlayerController>(GetController());
			DetachFromControllerPendingDestroy();
			if (ShooterPlayerController != nullptr)
			{
				SpectatorPawn->SetOwner(ShooterPlayerController);
				ShooterPlayerController->Possess(SpectatorPawn);
			}
		}
		
		OnDeadEvent.Broadcast(this);
	}
}

bool AMP_ShooterCharacter::IsDead() const
{
	return Dead;
}

void AMP_ShooterCharacter::PerformPullTrigger()
{
	if (Gun != nullptr)
	{
		Gun->PullTrigger();
	}
}

//---- Release Trigger ----/
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

//---- Reload ----/
void AMP_ShooterCharacter::Reload()
{
	if (HasAuthority())
	{
		MulticastReload();
	}
	else
	{
		ServerReload();
	}
}

void AMP_ShooterCharacter::ServerReload_Implementation()
{
	MulticastReload();
}

bool AMP_ShooterCharacter::ServerReload_Validate()
{
	return true;
}

void AMP_ShooterCharacter::MulticastReload_Implementation()
{
	PerformReload();
}

void AMP_ShooterCharacter::PerformReload()
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

void AMP_ShooterCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Ensure All Replicated variable to be replicated
	DOREPLIFETIME(AMP_ShooterCharacter, ReplicatedControlRotation);
	DOREPLIFETIME(AMP_ShooterCharacter, ShooterViewPointLocation);
	DOREPLIFETIME(AMP_ShooterCharacter, ShooterViewPointRotation);
	DOREPLIFETIME(AMP_ShooterCharacter, Health);
}
