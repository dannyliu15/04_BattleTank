// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
    //+1 as MaxUpwardSpeed, -1 as MinDownwardSpeed
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20.0; 

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevateDegrees = 40.0; // TODO set
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevateDegrees = 0.0; // TODO set
	
};
