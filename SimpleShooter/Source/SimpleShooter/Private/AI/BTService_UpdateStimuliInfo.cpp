// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_UpdateStimuliInfo.h"

#include "AIController.h"
#include "Actors/ShooterCharacter.h"
#include "Actors/Stimuli/SoundStimuli.h"
#include "Actors/Stimuli/VisualStimuli.h"
#include "Actors/Stimuli/SoundStimuli/SoundStimuli_BulletImpactSound.h"
#include "Actors/Stimuli/SoundStimuli/SoundStimuli_ShootingSound.h"
#include "Actors/Stimuli/VisualStimuli/VisualStimuli_ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Controllers/ShooterAIController.h"
#include "Kismet/KismetSystemLibrary.h"

UBTService_UpdateStimuliInfo::UBTService_UpdateStimuliInfo()
{
	NodeName = TEXT("Update Stimuli Info");
}

void UBTService_UpdateStimuliInfo::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	OwnerCompPtr = &OwnerComp;

	//initiate blackboard value
	if (!bInitiated)
	{
		OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), 9999999.9f); // Service - StimulusUpdate
		bInitiated = true;	
	}
	
	if (OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("TimeSeenAnEnemy")) > MaxTimeSeenAnEnemy)
	{
		OwnerCompPtr->GetBlackboardComponent()->ClearValue(FName("LastKnownEnemyLocation"));
	}
	
	AShooterAIController* ShooterAIController = Cast<AShooterAIController>(OwnerCompPtr->GetAIOwner());
	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(OwnerCompPtr->GetAIOwner()->GetPawn());
	
	if (OwnerCompPtr != nullptr && ShooterCharacter != nullptr && ShooterAIController != nullptr)
	{
		// Visual Stimuli collection
		TArray<AActor*> VSFound;
		
		TArray<AActor*> VSToIgnore;
		VSToIgnore.Add(ShooterCharacter->GetVSShooterCharacter());

		const TSubclassOf<AActor> filterVS = AVisualStimuli::StaticClass();
		
		TArray<TEnumAsByte<EObjectTypeQuery>> VSQuery;
		VSQuery.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));
		
		bool bVSHasHit = UKismetSystemLibrary::SphereOverlapActors(
			GetWorld(),
			ShooterAIController->GetPawn()->GetActorLocation(),
			ShooterAIController->GetSightRange(),
			VSQuery,
			filterVS,
			VSToIgnore,
			VSFound);
		
		bool bHaveSeenAnEnemy = false;
		if (bVSHasHit)
		{
			for (int i=0; i<VSFound.Num(); i++)
			{
				//VS of ShooterCharacter
				if (AVisualStimuli_ShooterCharacter* VS_Shooter = Cast<AVisualStimuli_ShooterCharacter> (VSFound[i]))
				{
					//check if you have line of sight first
					if (OwnerCompPtr->GetAIOwner()->LineOfSightTo(VS_Shooter->GetShooterCharacterRef()))
					{
						FVector EyesLocation;
						FRotator EyesRotation;
						OwnerCompPtr->GetAIOwner()->GetActorEyesViewPoint(EyesLocation, EyesRotation);

						const FVector EyesForward = EyesRotation.Vector();
						FVector EyesToPlayer = VS_Shooter->GetShooterCharacterRef()->GetActorLocation() - EyesLocation;
						EyesToPlayer.Normalize();

						//vision cone
						// factor of 0 to 1, 0 = 180 degree vision, 1 = 0 degree vision, 0.5 = 90 (45 split from the middle)
						if (FVector::DotProduct(EyesForward, EyesToPlayer) > (1-(ShooterAIController->GetFieldOfView()/90.0f))) 
						{
							OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("EnemyInSight"), VS_Shooter->GetShooterCharacterRef());
							OwnerCompPtr->GetBlackboardComponent()->SetValueAsVector(FName("LastKnownEnemyLocation"), VS_Shooter->GetShooterCharacterRef()->GetActorLocation());
							OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), 0.0f);
							bHaveSeenAnEnemy = true;
						}
					}
				}
			}
		}

		if (!bHaveSeenAnEnemy)
		{
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsObject(FName("EnemyInSight"), nullptr);
			float TimeRegistered = OwnerCompPtr->GetBlackboardComponent()->GetValueAsFloat(FName("TimeSeenAnEnemy")); // Service - StimulusUpdate
			TimeRegistered += DeltaSeconds;
			OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), TimeRegistered); 
		}
		
		// Sound Stimuli Collection
		TArray<AActor*> SSFound;
		TArray<AActor*> SSToIgnore;

		const TSubclassOf<AActor> filterSS = ASoundStimuli::StaticClass();
		
		TArray<TEnumAsByte<EObjectTypeQuery>> SSQuery;
		SSQuery.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));
		
		bool bSSHasHit = UKismetSystemLibrary::SphereOverlapActors(
			GetWorld(),
			ShooterAIController->GetPawn()->GetActorLocation(),
			ShooterAIController->GetHearingRange(),
			SSQuery,
			filterSS,
			SSToIgnore,
			SSFound);
		
		if (bSSHasHit)
		{
			for (int i=0; i<SSFound.Num(); i++)
			{
				//Skip the analysis if the sound owner is the ShooterCharacter
				ASoundStimuli* SoundStimuli = Cast<ASoundStimuli> (SSFound[i]);
				if (SoundStimuli->GetSoundOwner()->GetUniqueID() == ShooterCharacter->GetUniqueID())
				{
					continue;
				}
				
				//SS of ShootingSound
				if (ASoundStimuli_ShootingSound* SS_ShootingSound = Cast<ASoundStimuli_ShootingSound> (SSFound[i]))
				{
					if (OwnerCompPtr->GetAIOwner()->LineOfSightTo(SS_ShootingSound))
					{
						OwnerCompPtr->GetBlackboardComponent()->SetValueAsVector(FName("LastKnownEnemyLocation"), SS_ShootingSound->GetActorLocation());
						OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), 0.0f);
					}
				}
				
				//SS of BulletImpact
				if (ASoundStimuli_BulletImpactSound* SS_BulletImpact= Cast<ASoundStimuli_BulletImpactSound> (SSFound[i]))
				{
					if (OwnerCompPtr->GetAIOwner()->LineOfSightTo(SS_BulletImpact))
					{
						OwnerCompPtr->GetBlackboardComponent()->SetValueAsVector(FName("LastKnownEnemyLocation"), SS_BulletImpact->GetShootingOriginPosition());
						OwnerCompPtr->GetBlackboardComponent()->SetValueAsFloat(FName("TimeSeenAnEnemy"), 0.0f);
					}
				}
			}
		}
	}
}
