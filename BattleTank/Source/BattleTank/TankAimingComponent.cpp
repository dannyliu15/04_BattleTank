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


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float FireSpeed)
{
	if (!BarralReference) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = BarralReference->GetSocketLocation(FName("Projectile"));

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
		FString OwnerName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *OwnerName, *AimDirection.ToString());
	}

	// If no solution found do nothing
	
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	BarralReference = BarrelToSet;
}

