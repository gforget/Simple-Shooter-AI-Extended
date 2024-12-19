// Fill out your copyright notice in the Description page of Project Settings.


#include "Stimuli/TouchStimuli/HurtStimuli.h"

#include "Actors/SinglePlayer/SP_ShooterCharacter.h"
#include "Controllers/SinglePlayer/SP_ShooterAIController.h"

void UHurtStimuli::Initialize(ASP_ShooterAIController* OwnerControllerRef, ASP_ShooterCharacter* OwnerCharacterRef)
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

void UHurtStimuli::SetDamageDealer(ASP_ShooterCharacter* DamageDealerRef)
{
	DamageDealer = DamageDealerRef;
}

ASP_ShooterCharacter* UHurtStimuli::GetDamageDealer()
{
	return DamageDealer;
}

void UHurtStimuli::OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	DamageDealer = Cast<ASP_ShooterCharacter>(DamageCauser);
	DamageDone = Damage;
}
