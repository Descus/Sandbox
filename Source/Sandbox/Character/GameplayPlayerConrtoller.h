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
	virtual void BeginPlay() override;

private:
	void UseItemInHand();
	void SetupInputBindings();
};
