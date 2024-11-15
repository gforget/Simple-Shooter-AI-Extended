// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SplashScreenUI.h"

#include "GameMode/MainGameInstance.h"
#include "Kismet/GameplayStatics.h"


void USplashScreenUI::CallSinglePlayerMap(TEnumAsByte<EAllianceMode>  AllianceMode, int NbRedBots, int NbBlueBots, FName LevelName)
{
	if (UMainGameInstance* MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		MainGameInstance->AllianceMode = AllianceMode;
		MainGameInstance->NbRedBots = NbRedBots;
		MainGameInstance->NbBlueBots = NbBlueBots;
		
		UGameplayStatics::OpenLevel(GetWorld(), LevelName, true);
	}
}
