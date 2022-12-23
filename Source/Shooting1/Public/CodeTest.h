// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodeTest.generated.h"

UCLASS()
class SHOOTING1_API ACodeTest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACodeTest();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//정수형 변수 number를 선언한다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CodeVariable)
		int32 number;
	//int32 number = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CodeVariable)
		int32 number2;

	// 실수형 변수 fnumber를 선언한다.
	float fnumber1;
	//float fnumber1=0;
	float fnumber2;

	////문자열 변수 name을 선언한다
	//FString name;
	////FString name; = "";
	//FString name2 = FString(TEXT("임귀주"));

	bool isStudent;
	//bool isStudent = false;
	bool isTeacher = true;


	//바로 밑에 있는 코드를 선언한다.
	UPROPERTY(EditAnywhere)
	int32 age = 41;
	UPROPERTY(EditAnywhere)
	FString Nation = FString(TEXT("한국"));


	//정수형변수2개를 입력값으로 받아서 정수형함수1개로 내뱉는다는 말,구현은 소스파일에서한다.
	int32 Add(int32* number1, int32* number2);
	int32 Subtract(int32 number1, int32 number2);
	int32 Multiply(int32 number1, int32 number2);
	float Divide(int32 number1, int32 number2);

	//함수를 선언할때는 헤더파일에 ;으로 마무리한다.


	//FString name;
	//FString name; = "";
	//FString name2 = FString(TEXT("임귀주"));


	UPROPERTY(EditAnywhere)
	FString name1 = TEXT("토");

	UPROPERTY(EditAnywhere)
	FString Tory2;

	//정수형변수2개를 입력값으로 받아서 정수형함수1개로 내뱉는다는 말,구현은 소스파일에서한다.
	FString Appender(FString, FString);
	//타입, 함수이름(매개변수)

	//문자열 두 개를 받아서 문자열 한 개로 합쳐서 반환하는 함수를 만들고 싶다.
	//UFUNCTION(Blupr intPure)
	//Unknown specifier 'Blupr' found while parsing function specifiers	FString StringAppender(FString a, FString b);



	//123부분에 정수를 하나 넣어본다.선생님이123정수 넣은 것
	int32 checker = 123;
	//만일, checker 변수의 값이 짝수라면
	//"even"이라고 출력한다.
	//그렇지 않고, 변수의 값이 홀수라면
	//"odd"라고 출력한다.
	

	//구구단 7단출력
	int32 num = 7;


	TMap<FString, float> distances;

	UPROPERTY(EditAnywhere)
	TArray<class APointerTest*> pointerTest;
	
	class APointerTest* pointerTest2;
};




