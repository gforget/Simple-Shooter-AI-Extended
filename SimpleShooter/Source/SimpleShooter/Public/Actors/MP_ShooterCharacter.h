// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MP_ShooterCharacter.generated.h"

class AMP_Gun;
class ARotationViewPointRef;
class UPlayMontageCallbackProxy;

UCLASS()
class SIMPLESHOOTER_API AMP_ShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMP_ShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintPure)
	bool GetIsReloading() const;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float RotationRate = 100.0f;
	
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	// Look Up functionality
	void LookUp(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);

	void PullTrigger();
	void ReleaseTrigger();
	void Reload();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	ARotationViewPointRef* GetRotationViewPointRef();

	UFUNCTION(BlueprintCallable)
	float GetHealthPercent() const;

	UFUNCTION(BlueprintCallable)
	float GetAmmoReservePercent() const;

	UFUNCTION(BlueprintCallable)
	float GetAmmoTotalPercent() const;
	
	UFUNCTION(BlueprintCallable)
	FString GetAmmoReserveRatio() const;

	UFUNCTION(BlueprintCallable)
	AMP_Gun* GetGunReference() const;

	UFUNCTION(BlueprintPure)
	FRotator GetReplicatedControlRotation() const { return ReplicatedControlRotation; }

	UPROPERTY(Replicated)
	FVector ShooterViewPointLocation;
	
	UPROPERTY(Replicated)
	FRotator ShooterViewPointRotation;
	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	bool IsDead() const;
	
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
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ARotationViewPointRef> RotationViewPointRefClass;

	UPROPERTY()
	ARotationViewPointRef* RotationViewPointRef;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMP_Gun> GunClass;
	
	UPROPERTY()
	AMP_Gun* Gun;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.0f;

	UPROPERTY(Replicated, VisibleAnywhere)
	float Health = 10.0f;
	
	UPROPERTY()
	bool IsReloading = false;

	UPROPERTY(EditDefaultsOnly)
	int MaxAmmoReserve = 100;
	
	UPROPERTY(EditDefaultsOnly)
	int AmmoReserve = 20;

	UPROPERTY()
	UPlayMontageCallbackProxy* ProxyReloadPlayMontage;

	UPROPERTY(EditAnywhere)
	UAnimMontage* ReloadMontage;

	UFUNCTION()
	void OnReloadAnimationCompleted(FName NotifyName);

	UPROPERTY()
	bool Dead = false;
};


