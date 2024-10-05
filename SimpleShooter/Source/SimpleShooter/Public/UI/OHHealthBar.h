// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OHHealthBar.generated.h"

class UProgressBar;
class AShooterCharacter;
class APlayerController;
class UOverlay;
/**
 * 
 */

UCLASS()
class SIMPLESHOOTER_API UOHHealthBar : public UUserWidget
{
	GENERATED_BODY()
	
public :
	virtual bool Initialize() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UOverlay* OHHealthBarOverlay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UProgressBar* OHHealthBarProgressBar;
	
	UPROPERTY()
	APlayerController* AssignedPlayerController;
	
	UPROPERTY()
	AShooterCharacter* AssignedCharacter;

	UFUNCTION()
	void OnCharacterHit(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION()
	void OnCharacterHeal();

	UFUNCTION()
	void OnCharacterDeath(AShooterCharacter* DeadCharacter);
	
	void UpdateHealthBar();

	void InitializeAssignedCharacterAndPlayerController(AShooterCharacter* AssignedCharacterRef, APlayerController* AssignedPlayerControllerRef);
};
