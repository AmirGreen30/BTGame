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
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	
private:
	ATank* GetControlledTank() const;	
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.333333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
};
