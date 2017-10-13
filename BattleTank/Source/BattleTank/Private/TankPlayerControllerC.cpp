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
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
	}
		//TODO contolled tank to aim thats point
}
///get world location thouge crosshair, true if it lands landscape
bool ATankPlayerControllerC::GetSightRayHitLocation(FVector& OutHitLocation) const{
	OutHitLocation = FVector(1.0);
	return true;
}
