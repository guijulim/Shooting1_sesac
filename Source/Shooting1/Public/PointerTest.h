// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointerTest.generated.h"

UCLASS()
class SHOOTING1_API APointerTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointerTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 pt_Number = 30;
	
	int32* myAge;

private:

	UPROPERTY(EditAnywhere)
	int32 realAge = 20;
	
};
