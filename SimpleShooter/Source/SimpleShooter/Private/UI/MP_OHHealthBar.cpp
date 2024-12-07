// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MP_OHHealthBar.h"

#include "Actors/MP_ShooterCharacter.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Actors/ShooterCharacter.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Overlay.h"
#include "Components/ProgressBar.h"
#include "GameFramework/SpectatorPawn.h"

bool UMP_OHHealthBar::Initialize()
{
	return Super::Initialize();
}

void UMP_OHHealthBar::InitializeAssignedCharacterAndPlayerController(AMP_ShooterCharacter* AssignedCharacterRef)
{
	AssignedCharacter = AssignedCharacterRef;
	
	UpdateHealthBar();
	AssignedCharacter->OnTakeAnyDamage.AddDynamic(this, &UMP_OHHealthBar::OnCharacterHit);
	AssignedCharacter->OnHealEvent.AddDynamic(this, &UMP_OHHealthBar::OnCharacterHeal);
	AssignedCharacter->OnDeadEvent.AddDynamic(this, &UMP_OHHealthBar::OnCharacterDeath);
}

void UMP_OHHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (AssignedCharacter != nullptr)
	{
		const float ViewPortScale = UWidgetLayoutLibrary::GetViewportScale(GetWorld());
	
		if (AssignedCharacter->GetMesh()->WasRecentlyRendered())
		{
			FHitResult Hit;
			
			FCollisionQueryParams Params;
			Params.AddIgnoredActor(AssignedCharacter);
			
			if (ASpectatorPawn* SpectatorPawn = Cast<ASpectatorPawn>(GetOwningPlayer()->GetPawn()))
			{
				Params.AddIgnoredActor(SpectatorPawn);
			}
			
			FVector ViewPortLocation;
			FRotator ViewPortRotation;
			GetOwningPlayer()->GetPlayerViewPoint(ViewPortLocation, ViewPortRotation);

			//Confirm there is no obstacle between the camera of the player and the 3D position of the healthbar anchor.
			//The reason is that WasRecentlyRendered is less costly than a raycast, but is imperfect
			if (!GetWorld()->LineTraceSingleByChannel(Hit, AssignedCharacter->HealthBarAnchor + AssignedCharacter->GetActorLocation(), ViewPortLocation, ECollisionChannel::ECC_GameTraceChannel1, Params))
			{
				FVector2d ScreenLocation;
				const FVector UnitLocation = AssignedCharacter->GetActorLocation() + AssignedCharacter->HealthBarAnchor;
	
				GetOwningPlayer()->ProjectWorldLocationToScreen(UnitLocation, ScreenLocation, true);

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

void UMP_OHHealthBar::OnCharacterHit(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	UpdateHealthBar();
}

void UMP_OHHealthBar::OnCharacterHeal()
{
	UpdateHealthBar();
}

void UMP_OHHealthBar::OnCharacterDeath(AMP_ShooterCharacter* DeadCharacter)
{
	RemoveFromParent();
}

void UMP_OHHealthBar::UpdateHealthBar()
{
	if (AssignedCharacter != nullptr && OHHealthBarProgressBar != nullptr)
	{
		OHHealthBarProgressBar->SetPercent(AssignedCharacter->GetHealthPercent());
	}
}


