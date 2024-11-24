﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShooterPlayerState.h"

#include "Net/UnrealNetwork.h"

AShooterPlayerState::AShooterPlayerState()
{
	bReplicates = true;
}

void AShooterPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AShooterPlayerState, Team);
}
