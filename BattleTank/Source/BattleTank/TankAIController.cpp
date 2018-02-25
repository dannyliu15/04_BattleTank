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
		
		//UE_LOG(LogTemp, Warning, TEXT("TankAIController PlayerTank location: %s"), *FirstPlayerLocation.ToString() );
	}
}

void ATankAIController::GetPlayerLocation(FVector & location) const
{
	location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	return;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector HitLocation;

	if (GetPlayerTank())
	{
		// TODO move towards teh player
		
		
		// Aim towards teh player
		GetPlayerLocation(HitLocation);
		GetControlledTank()->AimAt(HitLocation);

		// Fire if ready

	}
}


ATank * ATankAIController::GetPlayerTank() const
{
	APawn* PlayerTank =  GetWorld()->GetFirstPlayerController()->GetPawn() ;
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController Error: GetPlayerTank failed !"));
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}