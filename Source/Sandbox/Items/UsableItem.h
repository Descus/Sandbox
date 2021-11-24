// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sandbox/Items/BaseItem.h"
#include "UsableItem.generated.h"

UCLASS(Abstract, Blueprintable)
class SANDBOX_API AUsableItem : public ABaseItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AUsableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Use() PURE_VIRTUAL(AUsableItem::Use, );
};
