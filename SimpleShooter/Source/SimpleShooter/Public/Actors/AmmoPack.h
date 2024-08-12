// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AmmoPack.generated.h"

UCLASS()
class SIMPLESHOOTER_API AAmmoPack : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAmmoPack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly)
	float TimeToRecharge = 5.0f;
	
	UPROPERTY(EditDefaultsOnly)
	int AmmoAmount = 20;

	UPROPERTY(EditDefaultsOnly)
	UMaterial* AmmoPackActiveMaterial;

	UPROPERTY(EditDefaultsOnly)
	UMaterial* AmmoPackInactiveMaterial;

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
