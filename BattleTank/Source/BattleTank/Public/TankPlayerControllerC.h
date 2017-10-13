// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerControllerC.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerControllerC : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
	
private:
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
