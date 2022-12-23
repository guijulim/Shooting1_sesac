// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodePractice.generated.h"

UCLASS()
class SHOOTING1_API ACodePractice : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Add)
	int32 Num1;

	UPROPERTY(EditAnywhere, Category = Add)
	int32 Num2;

	UPROPERTY(EditAnywhere, Category = CodeVariable)
	TArray<int32> ages;

public:	
	// Sets default values for this actor's properties
	ACodePractice();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	int32 Add(int32 num1, int32 num2);

	int32 Multiply(int32 num1, int32 num2);

};
