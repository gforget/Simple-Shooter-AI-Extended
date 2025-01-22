// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "Actors/BaseShooterCharacter.h"
#include "GameFramework/Character.h"
#include "MP_ShooterCharacter.generated.h"

//class AMP_Gun;
class ARotationViewPointRef;
class UPlayMontageCallbackProxy;
class AMP_ShooterSpectatorPawn;
class USphereComponent;

UCLASS()
class SIMPLESHOOTER_API AMP_ShooterCharacter : public ABaseShooterCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMP_ShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Update collision sphere location
	//void UpdateHeadCollision();
	
// #if WITH_EDITOR
// 	virtual void PostActorCreated() override;
// 	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
// 	virtual void PostEditMove(bool bFinished) override;
// #endif

	// UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	// float HeadshotMultiplier = 2.0f;
	//
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	// FName HeadBoneName = TEXT("head");
	//
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	// FVector HeadAnchorOffset = FVector::ZeroVector;
	//
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	// float HeadshotRadius = 15.0f;
	//
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	// bool bShowHeadshotDebug = false;
	//
	// UPROPERTY(VisibleAnywhere, Category = "Combat")
	// USphereComponent* HeadCollision;
	
public:

	// UPROPERTY(EditDefaultsOnly, Category="Position Reference")
	// FVector FootPositionAnchor = FVector(0.0f, 0.0f, 25.0f);
	//
	// UPROPERTY(EditDefaultsOnly, Category="Position Reference")
	// FVector BodyPositionAnchor = FVector(0.0f, 0.0f, 50.0f);

	// UFUNCTION(BlueprintCallable, Category = "Combat")
	// FVector GetHeadAnchorLocation() const;
	
	// UFUNCTION(BlueprintPure)
	// bool GetIsReloading() const;

	// UPROPERTY(EditAnywhere)
	// float RotationRate = 100.0f;
	
	// void MoveForward(float AxisValue);
	// void MoveRight(float AxisValue);

	// Look Up functionality
	void LookUp(float AxisValue);
	// void LookUpRate(float AxisValue);
	// void LookRightRate(float AxisValue);

	virtual void PullTrigger() override;
	virtual void ReleaseTrigger() override;
	virtual void Reload() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	ARotationViewPointRef* GetRotationViewPointRef();

	UFUNCTION(BlueprintCallable)
	float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() const;

	// UFUNCTION(BlueprintCallable)
	// float GetAmmoReservePercent() const;

	// UFUNCTION(BlueprintCallable)
	// float GetAmmoTotalPercent() const;
	
	// UFUNCTION(BlueprintCallable)
	// FString GetAmmoReserveRatio() const;

	// UFUNCTION(BlueprintCallable)
	// AMP_Gun* GetGunReference() const;

	UFUNCTION(BlueprintPure)
	FRotator GetReplicatedControlRotation() const { return ReplicatedControlRotation; }

	UPROPERTY(Replicated)
	FVector ShooterViewPointLocation;
	
	UPROPERTY(Replicated)
	FRotator ShooterViewPointRotation;
	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	//float Heal(float HealAmount);

	//int AddAmmoReserve(int AmmoAmount);
	
	// UFUNCTION(BlueprintPure)
	// bool IsDead() const;
	
protected:
	
	//Pull Trigger RPC
	// Server RPC - executed on the server
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerPullTrigger();

	// Multicast RPC - executed on all clients
	UFUNCTION(NetMulticast, Reliable)
	void MulticastPullTrigger();

	// Function to perform the actual shooting logic
	void PerformPullTrigger();

	//Release Trigger RPC
	// Server RPC - executed on the server
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerReleaseTrigger();

	// Multicast RPC - executed on all clients
	UFUNCTION(NetMulticast, Reliable)
	void MulticastReleaseTrigger();

	// Function to perform the actual shooting logic
	void PerformReleaseTrigger();

	//Reload Trigger RPC
	// Server RPC - executed on the server
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerReload();

	// Multicast RPC - executed on all clients
	UFUNCTION(NetMulticast, Reliable)
	void MulticastReload();

	// Function to perform the actual Reload logic
	void PerformReload();

	// Death RPC
	// Multicast RPC - executed on all clients
	UFUNCTION(NetMulticast, Reliable)
	void MulticastDeath();
	
	//ControlRotation Replication
	//Replicated Variable
	UPROPERTY(ReplicatedUsing = OnRep_ControlRotation)
	FRotator ReplicatedControlRotation;

	UFUNCTION()
	void OnRep_ControlRotation();
	
	// Server RPC - executed on the server
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetControlRotation(const FRotator& NewRotation);
	
	// Function to directly modify the control rotation
	void UpdateControlRotation(const FRotator& NewRotation);

private:
	
	// UPROPERTY(EditDefaultsOnly)
	// TSubclassOf<ARotationViewPointRef> RotationViewPointRefClass;

	// UPROPERTY()
	// ARotationViewPointRef* RotationViewPointRef;
	
	// UPROPERTY(EditDefaultsOnly)
	// TSubclassOf<AMP_Gun> GunClass;
	//
	// UPROPERTY()
	// AMP_Gun* Gun;
	
	// UPROPERTY()
	// bool IsReloading = false;

	// UPROPERTY(EditDefaultsOnly)
	// int MaxAmmoReserve = 100;
	//
	// UPROPERTY(EditDefaultsOnly)
	// int AmmoReserve = 20;

	UPROPERTY()
	UPlayMontageCallbackProxy* ProxyReloadPlayMontage;

	UPROPERTY(EditAnywhere)
	UAnimMontage* ReloadMontage;

	UFUNCTION()
	void OnReloadAnimationCompleted(FName NotifyName);

	// UPROPERTY()
	// bool Dead = false;
	
	//void GenerateEditorAnchorPositionVisualisation() const;
	
	// UPROPERTY(EditDefaultsOnly)
	// TSubclassOf<AMP_ShooterSpectatorPawn> ShooterSpectatorPawnClass;
};
