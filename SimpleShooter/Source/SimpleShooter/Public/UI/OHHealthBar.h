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
	
	UPROPERTY(BlueprintReadOnly)
	AShooterCharacter* AssignedCharacter;

	UFUNCTION()
	void OnCharacterDeath(AShooterCharacter* DeadCharacter);

	void InitializeAssignedCharacterAndPlayerController(AShooterCharacter* AssignedCharacterRef);
};
