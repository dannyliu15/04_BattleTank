// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float FireSpeed)
{
	if (!BarrelRef) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = BarrelRef->GetSocketLocation(FName("Projectile"));

	// Calculate the OutLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity( 
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		FireSpeed,
		false,
		0.0,
		0.0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	)
		)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		//FString OwnerName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *OwnerName, *AimDirection.ToString());
		MoveBarrelToward(AimDirection);
	
	}

	// If no solution found do nothing
	
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	BarrelRef = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelToward(FVector AimDirection)
{
	// work-out difference between current barrel rotation and AimDirection
	FRotator BarrelRotator = BarrelRef->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *DeltaRotator.ToString() );

	// move teh barrel the right amount this frame

	// Given a max elevation speed, and the frame time

}

