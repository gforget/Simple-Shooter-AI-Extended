// Fill out your copyright notice in the Description page of Project Settings.


#include "Stimuli/TouchStimuli/HurtStimuli.h"

#include "Actors/ShooterCharacter.h"
#include "Controllers/ShooterAIController.h"

void UHurtStimuli::Initialize(AShooterAIController* OwnerControllerRef, AShooterCharacter* OwnerCharacterRef)
{
	OwnerController = OwnerControllerRef;
	
	OwnerCharacter = OwnerCharacterRef;
	OwnerCharacter->OnTakeAnyDamage.AddDynamic(this, &UHurtStimuli::OnTakeDamage);
}

void UHurtStimuli::SetDamageDone(float DamageDoneRef)
{
	DamageDone = DamageDoneRef;
}

float UHurtStimuli::GetDamageDone()
{
	return DamageDone;
}

void UHurtStimuli::SetDamageDealer(AShooterCharacter* DamageDealerRef)
{
	DamageDealer = DamageDealerRef;
}

AShooterCharacter* UHurtStimuli::GetDamageDealer()
{
	return DamageDealer;
}

void UHurtStimuli::OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	DamageDealer = Cast<AShooterCharacter>(DamageCauser);
	DamageDone = Damage;
}
