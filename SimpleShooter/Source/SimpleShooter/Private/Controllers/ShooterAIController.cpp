// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/ShooterAIController.h"
#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Stimuli/TouchStimuli/HurtStimuli.h"

// Sets default values
AShooterAIController::AShooterAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AShooterAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (AIBehavior != nullptr)
	{
		HurtStimuli =NewObject<UHurtStimuli>(GetTransientPackage(), UHurtStimuli::StaticClass());
		HurtStimuli->Initialize(this, Cast<AShooterCharacter>(InPawn));
		
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), InPawn->GetActorLocation());
	}
}

// Called every frame
void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDebug)
	{
		DrawDebugSphere(
			GetWorld(),
			GetPawn()->GetActorLocation(),
			SightRange,
			12,
			FColor::Green,
			false,
			0.0f,
			0,
			1.0f);
		
		DrawDebugSphere(
			GetWorld(),
			GetPawn()->GetActorLocation(),
			HearingRange,
			12,
			FColor::Magenta,
			false,
			0.0f,
			0,
			1.0f);
		
		FVector EyesLocation;
		FRotator EyesRotation;
		GetActorEyesViewPoint(EyesLocation, EyesRotation);

		const FVector EyesForward = EyesRotation.Vector();
		const FVector EyesRightFieldOfView = EyesForward.RotateAngleAxis(FieldOfView/2, EyesForward.UpVector);
		DrawDebugLine(
			GetWorld(),
			EyesLocation,
			EyesLocation + EyesRightFieldOfView*SightRange,
			FColor::Yellow,
			false, -1, 0,
			1.0f
		);
		
		const FVector EyesLeftFieldOfView = EyesForward.RotateAngleAxis(-FieldOfView/2, EyesForward.UpVector);
		DrawDebugLine(
			GetWorld(),
			EyesLocation,
			EyesLocation + EyesLeftFieldOfView*SightRange,
			FColor::Yellow,
			false, -1, 0,
			1.0f
		);
		
		const FVector EyesRight = EyesForward.Cross(EyesForward.UpVector); //For some reason, RightVector from EyesForward doesn't work, so calculate it with a CrossP
		const FVector EyesTopFieldOfView = EyesForward.RotateAngleAxis(FieldOfView/2, EyesRight);
		DrawDebugLine(
			GetWorld(),
			EyesLocation,
			EyesLocation + EyesTopFieldOfView*SightRange,
			FColor::Yellow,
			false, -1, 0,
			1.0f
		);
		
		const FVector EyesBottomFieldOfView = EyesForward.RotateAngleAxis(-FieldOfView/2, EyesRight);
		DrawDebugLine(
			GetWorld(),
			EyesLocation,
			EyesLocation + EyesBottomFieldOfView*SightRange,
			FColor::Yellow,
			false, -1, 0,
			1.0f
		);
	}
}

bool AShooterAIController::IsDead() const
{
	AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead(); 
	}

	return true;
}

void AShooterAIController::UpdateControlRotation(float DeltaTime, bool bUpdatePawn)
{
	//Super::UpdateControlRotation(DeltaTime, bUpdatePawn);
	
	//Following code is the original UpdateControlRotation without bUpdatePawn
	//it include a fix so pitch can now work with focal point
	
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		FRotator NewControlRotation = GetControlRotation();
	
		// Look toward focus
		const FVector FocalPoint = GetFocalPoint();
		if (FAISystem::IsValidLocation(FocalPoint))
		{
			NewControlRotation = (FocalPoint - MyPawn->GetPawnViewLocation()).Rotation();
		}
		else if (bSetControlRotationFromPawnOrientation)
		{
			NewControlRotation = MyPawn->GetActorRotation();
		}
		
		// Don't pitch view unless you have an enemy target
		AActor* EnemyTarget = Cast<AActor>(GetBlackboardComponent()->GetValueAsObject("EnemyInSight"));
		if (NewControlRotation.Pitch != 0 && EnemyTarget == nullptr)
		{
			NewControlRotation.Pitch = 0.f;
		}
		
		//Get Pawn current rotation
		const FRotator CurrentControlRotation = GetControlRotation();
		
		//Calculate smoothed rotation
		SmoothControlRotation = UKismetMathLibrary::RInterpTo_Constant(CurrentControlRotation, NewControlRotation, DeltaTime, SmoothFocusInterpSpeed);
		
		//Check if we need to change
		if (CurrentControlRotation.Equals(SmoothControlRotation, 1e-3f) == false)
		{
			SetControlRotation(SmoothControlRotation);
		}
		else
		{
			SetControlRotation(NewControlRotation);
		}
		
		if (bUpdatePawn)
		{
			const FRotator CurrentPawnRotation = MyPawn->GetActorRotation();
			
			if (CurrentPawnRotation.Equals(GetControlRotation(), 1e-3f) == false)
			{
				MyPawn->FaceRotation(GetControlRotation(), DeltaTime);
			}
		}
	}
}

float AShooterAIController::GetFieldOfView()
{
	return FieldOfView;
}

float AShooterAIController::GetSightRange()
{
	return SightRange;
}

float AShooterAIController::GetHearingRange()
{
	return HearingRange;
}

UHurtStimuli* AShooterAIController::GetHurtStimuli()
{
	return HurtStimuli;
}



