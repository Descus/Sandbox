// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayCharacter.h"


// Sets default values
AGameplayCharacter::AGameplayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameplayCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGameplayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGameplayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGameplayCharacter::UseItem()
{
	if(Item)
	{
		Item->Use();
	}
}

void AGameplayCharacter::MoveForward(float Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Cyan, "Forward");
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * Value * ForwardSpeed);
}

void AGameplayCharacter::MoveRight(float Value)
{
	SetActorLocation(GetActorLocation() + GetActorRightVector() * Value * StrafeSpeed);
}

void AGameplayCharacter::Turn(float Value)
{
	SetActorRelativeRotation(FRotator(0,1,0) * Value * TurnSpeed);
}

void AGameplayCharacter::Pitch(float Value)
{
	SetActorRelativeRotation(FRotator(1,0,0) * Value * TurnSpeed);
}

