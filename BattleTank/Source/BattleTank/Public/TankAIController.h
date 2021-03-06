// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

///#include "BattleTank.h"
#include "AIController.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
private:
	virtual void Tick(float DeltaTime) override;

	ATank* GetAiControlledTank() const;
	
	ATank* GetPlayerTank() const;
	
	
};
