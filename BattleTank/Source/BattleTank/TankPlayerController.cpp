// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank * ATankPlayerController::GetControlledTank() const
{
	
	APawn* OwnerTank = GetPawn();
	if (!OwnerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController Error: Failed to find OwnerTank"));
		return nullptr;
	}

	return Cast<ATank>(OwnerTank) ;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* OwnerTankPtr = GetControlledTank();
	if (OwnerTankPtr)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Owner: %s"), *OwnerTankPtr->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }


	// Get world location if linetrace through crosshair
	FVector OutHitLocation;
	if (GetSightRayHitLocation(OUT OutHitLocation))// Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController OutHitLocation: %s"), *OutHitLocation.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController OutHitLocation: %s"), *OutHitLocation.ToString());
	}




		// Tell controlled tank to aim at this point

}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	FVector2D ScreenLocation;
	int32 ViewportXSize, ViewportYSize;
	FVector LookDirection;
	GetViewportSize(ViewportXSize, ViewportYSize);
	ScreenLocation.X = ViewportXSize * CrossHairXLocation;
	ScreenLocation.Y = ViewportYSize * CrossHairYLocation;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);

	}
	// Get crosshair position and rotation
	// do the ray tracking
	// If it hits the landscape
		// if hit, return hit location
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & OutLookDirection) const
{
	FVector CameraWorldLocation;// To be discared
	return (DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		OutLookDirection
	));
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDir, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + LookDir * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	
	HitLocation = FVector(0.0f);
	return false;
}
