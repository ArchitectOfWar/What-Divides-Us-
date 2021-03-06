// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
//Rotation camera in Yaw rotation
void APlayerCharacter::RotateCameraYaw(float Rate)
{
	AddControllerYawInput(Rate * 45.0f * GetWorld()->GetDeltaSeconds());
}
//Rotation camera in Pitch rotation
void APlayerCharacter::RotateCameraPitch(float Rate)
{
	AddControllerPitchInput(Rate * 45.0f * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::MoveForward(float Ratio)
{
	if (Controller)
	{
		AddMovementInput(this->GetActorForwardVector(), Ratio);
	}
}

void APlayerCharacter::MoveRight(float Ratio)
{
	if (Controller)
	{
		AddMovementInput(this->GetActorRightVector(), Ratio);
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("RotateCameraYaw", this, &APlayerCharacter::RotateCameraYaw);
	PlayerInputComponent->BindAxis("RotateCameraPitch", this, &APlayerCharacter::RotateCameraPitch);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

}

