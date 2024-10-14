// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stimuli/TouchStimuli.h"
#include "HurtStimuli.generated.h"

class AShooterAIController;
class AShooterCharacter;
/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UHurtStimuli : public UTouchStimuli
{
	GENERATED_BODY()

public :
	void Initialize(AShooterAIController* OwnerControllerRef, AShooterCharacter* OwnerCharacterRef);
	
	void SetDamageDone(float DamageDoneRef);
	float GetDamageDone();
	
	void SetDamageDealer(AShooterCharacter* DamageDealerRef);
	AShooterCharacter* GetDamageDealer();

private:
	UPROPERTY()
	AShooterAIController* OwnerController;

	UPROPERTY()
	AShooterCharacter* OwnerCharacter;
	
	UPROPERTY()
	float DamageDone;
	
	UPROPERTY()
	AShooterCharacter* DamageDealer;

	UFUNCTION()
	void OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
};
