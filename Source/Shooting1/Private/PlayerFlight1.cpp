// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFlight1.h"

// Sets default values
APlayerFlight1::APlayerFlight1()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerFlight1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerFlight1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerFlight1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

