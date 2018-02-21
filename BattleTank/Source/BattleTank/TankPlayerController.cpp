// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank * ATankPlayerController::GetControlledTank() const
{
	
	ATank* OwnerTank = Cast<ATank>(GetPawn());
	if (!OwnerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController Error: Failed to find OwnerTank"));
	}

	return OwnerTank;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Owner: %s"), *GetControlledTank()->GetName());
}
