// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayPlayerConrtoller.h"



void AGameplayPlayerConrtoller::BeginPlay()
{
	
	PossesedCharacter = Cast<AGameplayCharacter>(GetPawn());
	Super::BeginPlay();
}



void AGameplayPlayerConrtoller::SetupInputBindings()
{
	InputComponent->BindAction("UseItemInHand", IE_Repeat, this, &AGameplayPlayerConrtoller::UseItemInHand);
	InputComponent->BindAxis("ForeBack",this, &AGameplayPlayerConrtoller::MoveForward);
	InputComponent->BindAxis("LeftRight", this, &AGameplayPlayerConrtoller::MoveRight);
	InputComponent->BindAxis("Turn", this, &AGameplayPlayerConrtoller::Turn);
	InputComponent->BindAxis("Pitch", this, &AGameplayPlayerConrtoller::Pitch);
}

void AGameplayPlayerConrtoller::SetupInputComponent()
{
	Super::SetupInputComponent();
	if(InputComponent)
	{
		SetupInputBindings();
	}
}

void AGameplayPlayerConrtoller::UseItemInHand()
{
	PossesedCharacter->UseItem();
}

void AGameplayPlayerConrtoller::MoveForward(float Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, "Forward");
	PossesedCharacter->MoveForward(Value);
	//PossesedCharacter->GetMovementComponent()->Forward?
}
void AGameplayPlayerConrtoller::MoveRight(float Value)
{
	PossesedCharacter->MoveRight(Value);
}

void AGameplayPlayerConrtoller::Pitch(float Value)
{
	PossesedCharacter->Pitch(Value);
}

void AGameplayPlayerConrtoller::Turn(float Value)
{
	PossesedCharacter->Turn(Value);
}

