// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MP_Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AMP_Gun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMP_Gun();

	UFUNCTION()
	void Fire();
	
	FTimerDelegate FireTimerTimerDel;
	FTimerHandle FireTimerHandle;
	
	void PullTrigger();
	void ReleaseTrigger();
	
	int Reload (int AmmoAmount);

	UFUNCTION(BlueprintCallable)
	FString GetAmmoRatio() const;

	UFUNCTION(BlueprintCallable)
	float GetAmmoPercent() const;

	UFUNCTION(BlueprintCallable)
	int GetAmmoAmount() const;

	UFUNCTION(BlueprintCallable)
	int GetMaxAmmo() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
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
	float BulletSpreadRadius = 10000.0;

	UPROPERTY()
	bool TriggerPulled = false;
	
	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);
	
	bool UseAmmo();

	AController* GetOwnerController() const;
};


