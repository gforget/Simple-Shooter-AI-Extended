// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stimuli/TouchStimuli.h"
#include "HurtStimuli.generated.h"

class ASP_ShooterAIController;
class ASP_ShooterCharacter;
/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UHurtStimuli : public UTouchStimuli
{
	GENERATED_BODY()

public :
	void Initialize(ASP_ShooterAIController* OwnerControllerRef, ASP_ShooterCharacter* OwnerCharacterRef);
	
	void SetDamageDone(float DamageDoneRef);
	float GetDamageDone();
	
	void SetDamageDealer(ASP_ShooterCharacter* DamageDealerRef);
	ASP_ShooterCharacter* GetDamageDealer();

private:
	UPROPERTY()
	ASP_ShooterAIController* OwnerController;

	UPROPERTY()
	ASP_ShooterCharacter* OwnerCharacter;
	
	UPROPERTY()
	float DamageDone;
	
	UPROPERTY()
	ASP_ShooterCharacter* DamageDealer;

	UFUNCTION()
	void OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
};
