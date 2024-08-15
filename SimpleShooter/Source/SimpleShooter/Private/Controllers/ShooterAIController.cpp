// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/ShooterAIController.h"

#include "Actors/ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"


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
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), InPawn->GetActorLocation());
	}
}

// Called every frame
void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
		
		SetControlRotation(NewControlRotation);

		// if (bUpdatePawn)
		// {
		// 	const FRotator CurrentPawnRotation = MyPawn->GetActorRotation();
		//
		// 	if (CurrentPawnRotation.Equals(NewControlRotation, 1e-3f) == false)
		// 	{
		// 		MyPawn->FaceRotation(NewControlRotation, DeltaTime);
		// 	}
		// }
		
		//Smooth and change the pawn rotation
		//TODO: when fleeing, the rotation is wrong, let see why. Check my note for more details
		if (bUpdatePawn)
		{
			//Get Pawn current rotation
			const FRotator CurrentPawnRotation = MyPawn->GetActorRotation();
 
			//Calculate smoothed rotation
			SmoothPawnRotation = UKismetMathLibrary::RInterpTo_Constant(MyPawn->GetActorRotation(), ControlRotation, DeltaTime, SmoothFocusInterpSpeed);
	 	
			//Check if we need to change
			if (CurrentPawnRotation.Equals(SmoothPawnRotation, 1e-3f) == false)
			{
				//Change rotation using the Smooth Target Rotation
				MyPawn->FaceRotation(SmoothPawnRotation, DeltaTime);
			}
		}
	}
}



