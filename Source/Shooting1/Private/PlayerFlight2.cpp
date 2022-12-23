// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFlight2.h"

// Sets default values
APlayerFlight2::APlayerFlight2()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerFlight2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerFlight2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerFlight2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

