// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "GameFramework/Actor.h"
#include "MP_SpawningPoint.generated.h"

class AMP_ShooterCharacter;

UCLASS()
class SIMPLESHOOTER_API AMP_SpawningPoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMP_SpawningPoint();

	UPROPERTY(EditInstanceOnly)
	TEnumAsByte<ETeam> Team = ETeam::BlueTeam; 

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* BlueTeamIconTexture;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMP_ShooterCharacter> BlueTeamShooterCharacterClass;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* RedTeamIconTexture;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMP_ShooterCharacter> RedTeamShooterCharacterClass;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* NoTeamIconTexture;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMP_ShooterCharacter> NoTeamShooterCharacterClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	#if WITH_EDITOR
	virtual void PostActorCreated() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
public:
	
	void ChangeBillboardTexture();
	
	UPROPERTY()
	UBillboardComponent* Billboard; 
};
