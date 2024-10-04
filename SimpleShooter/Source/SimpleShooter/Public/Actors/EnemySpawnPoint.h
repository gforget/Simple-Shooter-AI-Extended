// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnPoint.generated.h"

class AShooterCharacter;

UCLASS()
class SIMPLESHOOTER_API AEnemySpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemySpawnPoint();

	UPROPERTY(EditInstanceOnly)
	TSubclassOf<AShooterCharacter> ShooterCharacterClass;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
