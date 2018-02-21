// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{

	ATank* OwnerTank = Cast<ATank>(GetPawn());
	if (!OwnerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController Error: Failed to find OwnerTank"));
	}

	return OwnerTank;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController Owner: %s"), *GetControlledTank()->GetName());
}
