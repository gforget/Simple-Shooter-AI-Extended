// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/RoomTriggerBox.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "ShooterAIController.generated.h"

UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
	
	// Sets default values for this actor's properties
	AShooterAIController();

	UPROPERTY(VisibleAnywhere)
	ARoomTriggerBox* CurrentRoomTriggerBox;
	
protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	
	UPROPERTY()
	FRotator SmoothPawnRotation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SmoothFocusInterpSpeed = 30.0f;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool IsDead() const;
	virtual void UpdateControlRotation(float DeltaTime, bool bUpdatePawn) override;
	
private:
	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehavior;
};
