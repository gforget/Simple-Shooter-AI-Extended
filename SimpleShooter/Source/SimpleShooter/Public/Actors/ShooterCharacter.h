// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayMontageCallbackProxy.h"
#include "ShooterCharacter.generated.h"

class AGun;
class UPlayMontageCallbackProxy;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintCallable)
	float GetHealthPercent() const;

	UFUNCTION(BlueprintCallable)
	float GetAmmoReservePercent() const;
	
	UFUNCTION(BlueprintCallable)
	FString GetAmmoReserveRatio() const;

	UFUNCTION(BlueprintCallable)
	AGun* GetGunReference() const;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	float Heal(float HealAmount);

	int AddAmmoReserve(int AmmoAmount);

	void PullTrigger();
	void PullTrigger(float AIOffsetRadius);
	void ReleaseTrigger();
	
	void Reload();

	void SelfDamage();
	
private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);

	void PlayReloadAnimationMontage();
	
	UPROPERTY(EditAnywhere)
	UAnimMontage* ReloadMontage;
	
	UPROPERTY(EditAnywhere)
	float RotationRate = 10.0f;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.0f;

	UPROPERTY(VisibleAnywhere)
	float Health = 10.0f;

	UPROPERTY(EditDefaultsOnly)
	int MaxAmmoReserve = 100;

	UPROPERTY(EditDefaultsOnly)
	int AmmoReserve = 20;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

	UPROPERTY()
	UPlayMontageCallbackProxy* PlayMontageCallbackProxy;

	UFUNCTION()
	void OnMontageCompleted(FName NotifyName);
};

