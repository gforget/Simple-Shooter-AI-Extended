// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemPack.generated.h"
class AShooterCharacter;
class UBoxComponent;

UCLASS(Abstract)
class SIMPLESHOOTER_API AItemPack : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemPack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	bool IsRecharging();

protected:
	
	UPROPERTY(EditDefaultsOnly)
	float TimeToRecharge = 5.0f;

	UPROPERTY(EditDefaultsOnly)
	UMaterial* ActiveMaterial;

	UPROPERTY(EditDefaultsOnly)
	UMaterial* InactiveMaterial;
	
	UPROPERTY()
	float RechargeTimer = 0.0f;

	void AttemptGivePackTo(AShooterCharacter* TargetShooterCharacter);
	virtual void GivePackTo(AShooterCharacter* TargetShooterCharacter);
	virtual bool PackValidation(AShooterCharacter* TargetShooterCharacter);
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;
	
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
};

