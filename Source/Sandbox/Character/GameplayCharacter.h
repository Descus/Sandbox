// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sandbox/Items/UsableItem.h"
#include "GameplayCharacter.generated.h"

UCLASS()
class SANDBOX_API AGameplayCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameplayCharacter();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Item")
	AUsableItem* Item;		

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Movement")
	float ForwardSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Movement")
	float StrafeSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Movement")
	float TurnSpeed;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void UseItem();
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void Pitch(float Value);
};
