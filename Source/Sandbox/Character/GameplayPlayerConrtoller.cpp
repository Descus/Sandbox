// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayPlayerConrtoller.h"

void AGameplayPlayerConrtoller::BeginPlay()
{
	if(InputComponent)
	{
		SetupInputBindings();
	}
	
	Super::BeginPlay();
}

void AGameplayPlayerConrtoller::SetupInputBindings()
{
	InputComponent->BindAction("UseItemInHand", IE_Repeat, this, &AGameplayPlayerConrtoller::UseItemInHand);
}

void AGameplayPlayerConrtoller::UseItemInHand()
{
	PossesedCharacter->UseItem();
}


