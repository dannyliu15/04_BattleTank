// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO: Should this tick?

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float FireSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

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
	    auto Time = GetWorld()->GetTimeSeconds();
        UE_LOG(LogTemp, Warning, TEXT("%f: AimDirection Found!"), Time);
	
	}

	// If no solution found print UE_LOG
    auto Time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("%f: AimDirection Not Found!"), Time);
	
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelToward(FVector AimDirection)
{
	// work-out difference between current barrel rotation and AimDirection
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5);// TODO remove magic number

}

