// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Sandbox/Items/UsableItem.h"
#include "LaserBeamGun.generated.h"

UCLASS()
class SANDBOX_API ALaserBeamGun : public AUsableItem
{

private:
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ALaserBeamGun();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USceneComponent* MuzzleComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float BeamLength = 500.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxBounces = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float BounceDistanceReduction = 10.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Enable = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void TraceLine(FVector MuzzlePosition, FVector ShotDirection, float Distance);
	void ShootBeam();
	virtual void Use() override;

private:
	FVector Reflect(FVector InVector, FVector ReflectNormal);
};
