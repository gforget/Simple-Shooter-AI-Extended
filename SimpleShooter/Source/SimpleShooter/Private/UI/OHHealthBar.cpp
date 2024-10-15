// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OHHealthBar.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Actors/ShooterCharacter.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Overlay.h"
#include "Components/ProgressBar.h"
#include "GameFramework/SpectatorPawn.h"


bool UOHHealthBar::Initialize()
{
	return Super::Initialize();
}

void UOHHealthBar::InitializeAssignedCharacterAndPlayerController(AShooterCharacter* AssignedCharacterRef, APlayerController* AssignedPlayerControllerRef)
{
	AssignedCharacter = AssignedCharacterRef;
	AssignedPlayerController = AssignedPlayerControllerRef;
	
	UpdateHealthBar();
	AssignedCharacter->OnTakeAnyDamage.AddDynamic(this, &UOHHealthBar::OnCharacterHit);
	AssignedCharacter->OnHealEvent.AddDynamic(this, &UOHHealthBar::OnCharacterHeal);
	AssignedCharacter->OnDeadEvent.AddDynamic(this, &UOHHealthBar::OnCharacterDeath);
}

void UOHHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (AssignedCharacter != nullptr && AssignedPlayerController != nullptr)
	{
		const float ViewPortScale = UWidgetLayoutLibrary::GetViewportScale(GetWorld());
	
		if (AssignedCharacter->GetMesh()->WasRecentlyRendered())
		{
			FHitResult Hit;
			
			FCollisionQueryParams Params;
			Params.AddIgnoredActor(AssignedCharacter);
			if (ASpectatorPawn* SpectatorPawn = Cast<ASpectatorPawn>(AssignedPlayerController->GetPawn()))
			{
				Params.AddIgnoredActor(SpectatorPawn);
			}
			
			FVector ViewPortLocation;
			FRotator ViewPortRotation;
			AssignedPlayerController->GetPlayerViewPoint(ViewPortLocation, ViewPortRotation);

			//Confirm there is no obstacle between the camera of the player and the 3D position of the healthbar anchor.
			//The reason is that WasRecentlyRendered is less costly than a raycast, but is imperfect
			if (!GetWorld()->LineTraceSingleByChannel(Hit, AssignedCharacter->HealthBarAnchor + AssignedCharacter->GetActorLocation(), ViewPortLocation, ECollisionChannel::ECC_GameTraceChannel1, Params))
			{
				FVector2d ScreenLocation;
				const FVector UnitLocation = AssignedCharacter->GetActorLocation() + AssignedCharacter->HealthBarAnchor;
	
				AssignedPlayerController->ProjectWorldLocationToScreen(UnitLocation, ScreenLocation, true);

				//Prevent offsetting caused by the UMG system
				ScreenLocation = ScreenLocation/ViewPortScale;

				Cast<UCanvasPanelSlot>(OHHealthBarOverlay->Slot)->SetPosition(ScreenLocation);
				OHHealthBarOverlay->SetVisibility(ESlateVisibility::Visible);
			}
			else
			{
				OHHealthBarOverlay->SetVisibility(ESlateVisibility::Hidden);
			}
		}
		else
		{
			OHHealthBarOverlay->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void UOHHealthBar::OnCharacterHit(
	AActor* DamagedActor,
	float Damage,
	const UDamageType* DamageType,
	AController* InstigatedBy,
	AActor* DamageCauser)
{
	UpdateHealthBar();
}

void UOHHealthBar::OnCharacterHeal()
{
	UpdateHealthBar();
}

void UOHHealthBar::OnCharacterDeath(AShooterCharacter* DeadCharacter)
{
	RemoveFromParent();
}

void UOHHealthBar::UpdateHealthBar()
{
	if (AssignedCharacter != nullptr && OHHealthBarProgressBar != nullptr)
	{
		OHHealthBarProgressBar->SetPercent(AssignedCharacter->GetHealthPercent());
	}
}
