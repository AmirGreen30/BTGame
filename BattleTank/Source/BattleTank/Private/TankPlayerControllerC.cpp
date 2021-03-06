// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "GameFramework/Actor.h"
#include "TankPlayerControllerC.h"

void ATankPlayerControllerC::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("playerController not possed by tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("playerController possesing %s"), *(ControlledTank->GetName()));
	}

}
void ATankPlayerControllerC::Tick(float DeltaTime) {
	//Super
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();
}


ATank* ATankPlayerControllerC::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerControllerC::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation)) {
		GetControlledTank()->AimAt(OutHitLocation);
		//TODO contolled tank to aim thats point
	}
		
}
///get world location thouge crosshair, true if it lands landscape
bool ATankPlayerControllerC::GetSightRayHitLocation(FVector& OutHitLocation) const{
	
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	//"de-Projection" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//line trace along that LookDirection and see what we hit.
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
	}
	
	return true;
}

bool ATankPlayerControllerC::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const {
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerControllerC::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
	) {
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}
