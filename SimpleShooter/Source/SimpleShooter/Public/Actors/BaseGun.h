// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGun.generated.h"

class ASoundStimuli_ShootingSound;
class ASoundStimuli_BulletImpactSound;

UCLASS(Abstract)
class SIMPLESHOOTER_API ABaseGun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseGun();

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UFUNCTION()
	virtual void Fire()PURE_VIRTUAL(ABaseGun::Fire, ;);
	FTimerDelegate FireTimerTimerDel;
	FTimerHandle FireTimerHandle;

	void PullTrigger();
	void ReleaseTrigger();
	
	int Reload(int AmmoAmount);

	UFUNCTION(BlueprintCallable)
	FString GetAmmoRatio() const;

	UFUNCTION(BlueprintCallable)
	float GetAmmoPercent() const;

	UFUNCTION(BlueprintCallable)
	int GetAmmoAmount() const;

	UFUNCTION(BlueprintCallable)
	int GetMaxAmmo() const;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASoundStimuli_ShootingSound> SoundStimuli_ShootingSoundClass;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASoundStimuli_BulletImpactSound> SoundStimuli_BulletImpactSoundClass;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
	USoundBase* MuzzleSound;
	
	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)
	USoundBase* ImpactSound;
	
	UPROPERTY(EditAnywhere)
	float MaxRange = 1000.0f;

	UPROPERTY(EditAnywhere)
	float Damage = 10.0f;

	UPROPERTY(EditDefaultsOnly)
	int MaxAmmo = 10;

	UPROPERTY(VisibleAnywhere)
	int Ammo = 10;

	UPROPERTY(EditAnywhere)
	float TimeBetweenRound = 0.15f;
	
	UPROPERTY(EditAnywhere)
	float BulletSpreadRadius = 200.0f;

	UPROPERTY()
	bool TriggerPulled = false;
	
	virtual bool GunTrace(FHitResult& Hit, FVector& ShotDirection)PURE_VIRTUAL(ABaseGun::GunTrace, return false;);
	
	bool UseAmmo();

	AController* GetOwnerController() const;
};
