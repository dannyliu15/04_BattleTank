// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{

	APawn* OwnerTank = GetPawn();
	if (!OwnerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController Error: Failed to find OwnerTank"));
	}

	return Cast<ATank>(OwnerTank);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank() )
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController Owner: %s"), *GetControlledTank()->GetName());
	}

	if (GetPlayerTank() )
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController PlayerTank: %s"), *GetPlayerTank()->GetName());
	}
}


ATank * ATankAIController::GetPlayerTank() const
{
	APawn* PlayerTank =  GetWorld()->GetFirstPlayerController()->GetPawn() ;
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController Error: GetPlayerTank failed !"));
	}
	return Cast<ATank>(PlayerTank);
}