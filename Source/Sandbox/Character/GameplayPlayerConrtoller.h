// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCharacter.h"
#include "GameFramework/PlayerController.h"
#include "GameplayPlayerConrtoller.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOX_API AGameplayPlayerConrtoller : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY()
	AGameplayCharacter* PossesedCharacter;

protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

private:
	void UseItemInHand();
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void Pitch(float Value);
	
	void SetupInputBindings();
};
