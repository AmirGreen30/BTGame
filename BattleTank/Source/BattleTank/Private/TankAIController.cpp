// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

#include "GameFramework/Actor.h"


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		//TODO moveToward The Player

		//Aim toward the player
		GetAiControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//Fire if ready

	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!GetPlayerTank()) {
		UE_LOG(LogTemp, Warning, TEXT("playerController not possed by tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("playerController possesing %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetAiControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
