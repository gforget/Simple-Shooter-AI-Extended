// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "GameFramework/Actor.h"
#include "SpawningPoint.generated.h"

class AShooterCharacter;

UCLASS()
class SIMPLESHOOTER_API ASpawningPoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawningPoint();

	UPROPERTY(EditInstanceOnly)
	TEnumAsByte<ETeam> Team = ETeam::BlueTeam; 

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* BlueTeamIconTexture;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AShooterCharacter> BlueTeamShooterCharacterClass;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* RedTeamIconTexture;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AShooterCharacter> RedTeamShooterCharacterClass;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* NoTeamIconTexture;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AShooterCharacter> NoTeamShooterCharacterClass;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	#if WITH_EDITOR
		virtual void PostActorCreated() override;
		virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	#endif

private:
	void ChangeBillboardTexture();
	
	UPROPERTY()
	UBillboardComponent* Billboard; 
};
