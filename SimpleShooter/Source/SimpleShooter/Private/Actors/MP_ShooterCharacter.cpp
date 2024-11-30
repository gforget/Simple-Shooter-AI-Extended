// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/MP_ShooterCharacter.h"


// Sets default values
AMP_ShooterCharacter::AMP_ShooterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMP_ShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMP_ShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMP_ShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMP_ShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AMP_ShooterCharacter::LookUpRate);
	
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMP_ShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AMP_ShooterCharacter::LookRightRate);
}

void AMP_ShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector()*AxisValue);
}

void AMP_ShooterCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector()*AxisValue);
}

void AMP_ShooterCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AMP_ShooterCharacter::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

