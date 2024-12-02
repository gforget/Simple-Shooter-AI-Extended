// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MP_ShooterCharacter.generated.h"

class AMP_Gun;
class ARotationViewPointRef;

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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float RotationRate = 100.0f;
	
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);

	void PullTrigger();
	void ReleaseTrigger();
	void Reload();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	ARotationViewPointRef* GetRotationViewPointRef();

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

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ARotationViewPointRef> RotationViewPointRefClass;

	UPROPERTY()
	ARotationViewPointRef* RotationViewPointRef;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMP_Gun> GunClass;
	
	UPROPERTY()
	AMP_Gun* Gun;
};
