// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/TeamManager.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<EAllianceMode> AllianceMode;
	
	UPROPERTY()
	int NbRedBots = 0;
	
	UPROPERTY()
	int NbBlueBots = 0;
};
