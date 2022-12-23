// Fill out your copyright notice in the Description page of Project Settings.


#include "CodePractice.h"

// Sets default values
ACodePractice::ACodePractice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodePractice::BeginPlay()
{
	Super::BeginPlay();
	
	//덧셈결과를 출력하고 그렇지않으면 곱셉결과를 출력한다.
	if (Num1 + Num2 >= 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), Add(Num1, Num2));
	
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("%d"), Multiply(Num1, Num2));
	}
}

// Called every frame
void ACodePractice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACodePractice::Add(int32 num1, int32 num2) 
{

	return num1 + num2;
}


int32 ACodePractice::Multiply(int32 num1, int32 num2) {

	return num1 * num2;
}
