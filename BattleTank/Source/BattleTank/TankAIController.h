// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank * GetPlayerTank() const;
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	
	void GetPlayerLocation(FVector& locatiion) const;

	virtual void Tick(float DeltaTime) override;
	
};
