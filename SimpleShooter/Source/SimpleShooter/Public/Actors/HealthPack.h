// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "HealthPack.generated.h"

UCLASS()
class SIMPLESHOOTER_API AHealthPack : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHealthPack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	float TimeToRecharge = 5.0f;
	
	UPROPERTY(EditDefaultsOnly)
	float HealAmount = 10.0f;

	UPROPERTY(EditDefaultsOnly)
	UMaterial* HealthPackActiveMaterial;

	UPROPERTY(EditDefaultsOnly)
	UMaterial* HealthPackInactiveMaterial;

	bool IsRecharging();
	
private:
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;
	
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY()
	float RechargeTimer = 0.0f;
	
};
