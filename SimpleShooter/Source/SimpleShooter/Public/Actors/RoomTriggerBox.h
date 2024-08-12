// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "RoomTriggerBox.generated.h"

class AFleePoint;
UCLASS()
class SIMPLESHOOTER_API ARoomTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:

	UPROPERTY(EditInstanceOnly)
	TArray<AFleePoint*> FleePointsOfRoom;
	
	// Sets default values for this actor's properties
	ARoomTriggerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:

	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
	
	UFUNCTION()
	void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);
};
