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
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get world location if linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank to aim at this point

}
