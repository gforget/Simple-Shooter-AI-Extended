// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayMontageCallbackProxy.h"
#include "Actors/BaseShooterCharacter.h"
#include "SP_ShooterCharacter.generated.h"

//class ASP_Gun;
class USphereComponent;
class AVisualStimuli_ShooterCharacter;
class ARotationViewPointRef;
class UPlayMontageCallbackProxy;
class UNavMeshUtility;
class ASP_ShooterSpectatorPawn;

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealEvent);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeadEvent, ASP_ShooterCharacter*, DeadShooterCharacter);

UCLASS()
class SIMPLESHOOTER_API ASP_ShooterCharacter : public ABaseShooterCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASP_ShooterCharacter();

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

	// UPROPERTY(VisibleAnywhere, Category = "Combat")
	// USphereComponent* HeadCollision;
	
public:
	// UPROPERTY()
	// FHealEvent OnHealEvent;

	// UPROPERTY()
	// FDeadEvent OnDeadEvent;
	
	// UPROPERTY()
	// UNavMeshUtility* NavMeshUtility;
	
	// UPROPERTY(EditDefaultsOnly, Category="Position Reference")
	// FVector HealthBarAnchor = FVector(0.0f, 0.0f, 88.0f);

	// UPROPERTY(EditDefaultsOnly, Category="Position Reference")
	// FVector FootPositionAnchor = FVector(0.0f, 0.0f, 25.0f);
	//
	// UPROPERTY(EditDefaultsOnly, Category="Position Reference")
	// FVector BodyPositionAnchor = FVector(0.0f, 0.0f, 50.0f);

	// UFUNCTION(BlueprintCallable, Category = "Combat")
	// FVector GetHeadAnchorLocation() const;
	
	// UFUNCTION(BlueprintPure)
	// bool GetIsReloading() const;
	
	// UFUNCTION(BlueprintPure)
	// bool IsDead() const;
	
	// UFUNCTION(BlueprintCallable)
	// float GetHealthPercent() const;

	// UFUNCTION(BlueprintCallable)
	// float GetAmmoReservePercent() const;

	// UFUNCTION(BlueprintCallable)
	// float GetAmmoTotalPercent() const;
	
	// UFUNCTION(BlueprintCallable)
	// FString GetAmmoReserveRatio() const;

	// UFUNCTION(BlueprintCallable)
	// ASP_Gun* GetGunReference() const;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	//float Heal(float HealAmount);

	//int AddAmmoReserve(int AmmoAmount);

	virtual void PullTrigger() override;
	virtual void ReleaseTrigger() override;
	virtual void Reload() override;

	UFUNCTION(BlueprintCallable)
	float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() const;
	
	void SelfDamage();
	
	AVisualStimuli_ShooterCharacter* GetVSShooterCharacter();
	
	ARotationViewPointRef* GetRotationViewPointRef();
	
private:
	
	// UPROPERTY(EditDefaultsOnly, Category = "Stimuli")
	// TSubclassOf<AVisualStimuli_ShooterCharacter> VisualStimuli_ShooterCharacterClass;
	//
	// UPROPERTY()
	// AVisualStimuli_ShooterCharacter* VSShooterCharacter;
	
	// UPROPERTY(EditDefaultsOnly, Category="Other")
	// TSubclassOf<ARotationViewPointRef> RotationViewPointRefClass;

	// UPROPERTY()
	// ARotationViewPointRef* RotationViewPointRef;

	//void Death();

	UPROPERTY()
	float ForwardAxisValue;
	
	// void MoveForward(float AxisValue);
	// void MoveRight(float AxisValue);
	//
	// void LookUpRate(float AxisValue);
	// void LookRightRate(float AxisValue);

	UPROPERTY()
	UPlayMontageCallbackProxy* ProxyReloadPlayMontage;
	
	UPROPERTY(EditAnywhere)
	UAnimMontage* ReloadMontage;
	
	// UPROPERTY(EditAnywhere)
	// float RotationRate = 10.0f;

	// UPROPERTY(EditDefaultsOnly, Category="Combat")
	// float MaxHealth = 100.0f;
	//
	// UPROPERTY(VisibleAnywhere, Category="Combat")
	// float Health = 10.0f;

	// UPROPERTY(EditDefaultsOnly, Category="Combat")
	// int MaxAmmoReserve = 100;
	//
	// UPROPERTY(EditDefaultsOnly, Category="Combat")
	// int AmmoReserve = 20;
	
	// UPROPERTY(EditDefaultsOnly, Category="Gun")
	// TSubclassOf<ASP_Gun> GunClass;
	//
	// UPROPERTY()
	// ASP_Gun* Gun;
	
	// UPROPERTY()
	// bool IsReloading = false;

	// UPROPERTY()
	// bool Dead = false;
	
	UPROPERTY()
	UPlayMontageCallbackProxy* PlayMontageCallbackProxy;

	UFUNCTION()
	void OnReloadAnimationCompleted(FName NotifyName);
	
	//void GenerateEditorAnchorPositionVisualisation() const;

	// UPROPERTY(EditDefaultsOnly, Category="Spectator")
	// TSubclassOf<ASP_ShooterSpectatorPawn> ShooterSpectatorPawnClass;
	
	void ActivateDebugSpectatorMode();
	
};