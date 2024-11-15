// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "Blueprint/UserWidget.h"
#include "SplashScreenUI.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API USplashScreenUI : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Main Functions")
	void CallSinglePlayerMap(TEnumAsByte<EAllianceMode> AllianceMode, int NbRedBots, int NbBlueBots, FName LevelName);
};
