// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserBeamGun.h"

#include "DrawDebugHelpers.h"

// Sets default values
ALaserBeamGun::ALaserBeamGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	
	MuzzleComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzlePosition"));
	MuzzleComponent->SetupAttachment(Mesh);
	MuzzleComponent->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void ALaserBeamGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaserBeamGun::Tick(float DeltaTime)
{
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &ALaserBeamGun::ShootBeam, .01f, false);
	Super::Tick(DeltaTime);
}

void ALaserBeamGun::ShootBeam()
{
	FVector BeamStart = MuzzleComponent->GetComponentLocation();
	FVector ShotDirection = MuzzleComponent->GetForwardVector();

	TraceLine(BeamStart, ShotDirection, BeamLength);
}

void ALaserBeamGun::TraceLine(FVector Start, FVector ShotDirection, float Distance)
{
	FHitResult OutHit;
	FCollisionQueryParams CollisionParams;
	FVector End = Start + (ShotDirection * Distance);
	bool hit = true;
	do
	{
		if(GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_GameTraceChannel1, CollisionParams))
		{
			if(OutHit.Actor->ActorHasTag(TEXT("Reflects")))
			{
				Start = OutHit.ImpactPoint;
				ShotDirection = Reflect(ShotDirection, OutHit.ImpactNormal);
				hit = true;
			} else hit = false;
		}else hit = false;
	}
	while (hit);
	
}

void ALaserBeamGun::Use()
{
	ShootBeam();
}

FVector ALaserBeamGun::Reflect(FVector InVector, FVector ReflectNormal)
{
	return InVector - 2 * FVector::DotProduct(ReflectNormal, InVector) * ReflectNormal;
}



