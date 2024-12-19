// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MP_OHHealthBar.generated.h"

class UProgressBar;
class AMP_ShooterCharacter;
class APlayerController;
class UOverlay;

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UMP_OHHealthBar : public UUserWidget
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
	AMP_ShooterCharacter* AssignedCharacter;

	UFUNCTION()
	void OnCharacterDeath(AMP_ShooterCharacter* DeadCharacter);

	void InitializeAssignedCharacterAndPlayerController(AMP_ShooterCharacter* AssignedCharacterRef);
};
