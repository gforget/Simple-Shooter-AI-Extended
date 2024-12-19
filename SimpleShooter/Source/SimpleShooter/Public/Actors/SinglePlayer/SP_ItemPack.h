﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SP_ItemPack.generated.h"
class ASP_ShooterCharacter;
class UBoxComponent;

UCLASS(Abstract)
class SIMPLESHOOTER_API ASP_ItemPack : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASP_ItemPack();

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

	void AttemptGivePackTo(ASP_ShooterCharacter* TargetShooterCharacter);
	virtual void GivePackTo(ASP_ShooterCharacter* TargetShooterCharacter);
	virtual bool PackValidation(ASP_ShooterCharacter* TargetShooterCharacter);
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;
	
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
};

