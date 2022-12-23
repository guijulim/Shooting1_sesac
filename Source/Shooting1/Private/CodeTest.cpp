// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeTest.h"
#include "PointerTest.h"


// Sets default values
// 생성자 함수:반환자료형없이 만들어진 함수_특별한함수_처음생성하려고할때 한번만 생성된다.비긴플레이와 비슷해보이지만 다르다.class의 life cycle과 관련이있다.(생에 주기) 기본 값을 설정할 수 있다.//함수라고하는데 반환자료형이없다.
ACodeTest::ACodeTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodeTest::BeginPlay()
{
	Super::BeginPlay();
	*(pointerTest2->myAge) = 15;
	//pointerTest2->realAge = 15;

	//문자열의 경우에는 앞에 *별로를 붙여야한다.(*result)연산자오버로드
// 
// 
////number변수에 3을 넣는다.
//number = 3;
////이렇게 쓰면 둘다 3을 가지게 된다.
//number2 = number;
//number2 = -7;

//fnumber1 = 3.14f;

////number의 값을 output 콘솔창에 출력한다.
//UE_LOG(LogTemp, Warning, TEXT(" number1 is %d, number2 is %d"), number, number2);
//UE_LOG(LogTemp, Warning, TEXT(" float number1 is %.2f"), fnumber1);
//UE_LOG(LogTemp, Warning, TEXT(" Hello World! %s"),*name2);

//isTeacher = false;
//if (isTeacher == true)
//{
//	UE_LOG(LogTemp, Warning, TEXT("true"));
//}
//else
//{
//	UE_LOG(LogTemp, Warning, TEXT("false"));
//}

#pragma region 함수

	//UE_LOG(LogTemp, Warning, TEXT(" Hello World! %s"),*name2);
	//int32 result = Add(8, 4);
	//UE_LOG(LogTemp, Warning, TEXT("Result : %d"), result);

	//int32 result1 = Add(8, 4);
	//UE_LOG(LogTemp, Warning, TEXT("Result : %d"), result1);

	int32 result2 = Subtract(8, 4);
	UE_LOG(LogTemp, Warning, TEXT("Result : %d"), result2);


	int32 result3 = Multiply(8, 4);
	UE_LOG(LogTemp, Warning, TEXT("Result : %d"), result3);

	float result4 = Divide(4, 8);
	UE_LOG(LogTemp, Warning, TEXT("Result : %.1f"), result4);
#pragma endregion 
	
	//만일 나이가 30살이상이면,할배라고 출력하고 싶다.
	if (age >= 30)
	{

	}
	//그렇지 않고 만일, 나이가 20살 이상히면"꼰대"라고 출력하고 싶다.
	//else if (age >= 20)
	{
		//UE_LOG(LogTemp, Warning, TEXT("꼰대시군요~"));
		//그렇지 않다면, "꼬맹이"라고 출력하고 싶다. 
		{
			//UE_LOG(LogTemp, Warning, TEXT("10살~"));
		}
	}

	//UE_LOG(LogTemp, Warning, TEXT("%s"), *Appender(name1, Tory2));

	//구구단출력,7단
	//for (int32 i = 1; i <= 9; i++)
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("%d x %d = %d"), 7, i, 7 * i);
// 	}

	//for (int32 i = 2; i < 10; i++)
// 	{
// 		for (int32 j = 1; j < 10; j++)
// 			{
// 		UE_LOG(LogTemp, Warning, TEXT("%d x %d = %d"), i, j, i * j)		
// 		}
// 		UE_LOG(LogTemp, Warning, TEXT("======================="));
// 	}



	//TMap<FString, float> distances;
	//distances.Add(TEXT("Seoul")) //한글을쓰면글씨가 깨져서 텍스트로 감싼경우
// 	distances.Add("Seoul", 250.f);
// 	distances.Add("Incheon", 450.f);
// 	distances.Add("SungNam", 135.f);

// 	FString myKey = TEXT("Incheon");  //변수를 준다
// 	UE_LOG(LogTemp, Warning, TEXT("%s : %f"), *myKey, distances[myKey]);
// 	*%s - % f

	for(auto dist : distances)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s-%f"), *dist.Key, dist.Value);
	}
	//더이상반복할것이없을때까지 반복하는 반복문 


	//auto >만능형자료형, 누군가로부터 받을때 사용가능

	//TArray<int32> ages;
	//ages = { 3, 4, 5 };
	//{
	///UE_LOG(LogTemp, Warning, TEXT("Array Length %d"), Num());

	///for (int32 i = 0; i<ages,Num(); i++)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("%d"), ages[i]);
	//}



	int32 number1 = 10;
	int32* copyNum = &number1;
	UE_LOG(LogTemp, Warning, TEXT("number1:%d, copyNum:%d"), number1, *copyNum);

	int32 aa = 10;
	int32 bb = 15;
	int32 result;
	result = Add(&aa, &bb);   //aa , bb는 원본아닌,복사값일뿐

	UE_LOG(LogTemp, Warning, TEXT("Result= %d, aa=%d, bb=%d"), result, aa, bb);     //& 엔퍼센트를 변수앞에 붙이면 참조하겠다는 뜻, 참조자, 참조자와 주소값을넘긴다를 헷갈려한다.


	
	number1 = 30;

	UE_LOG(LogTemp, Warning, TEXT("number1:%d, copyNum:%d"), number1, copyNum);
	
	//포인터 변수사용할때
	//UE_LOG(LogTemp, Warning, TEXT("number1: %p, copyNum:%p"), &number1, copyNum); 
	

	for (APointerTest* pt : pointerTest)
	{
		pt->pt_Number = 15;
	}
	
	//if (pointerTest != nullptr)       //조건문을 만들어 준다.
	//{
	//	*(pointerTest > myAge) = 15;
	//	//pointerTest->realAge= 15;
	//}
}







// Called every frame
void ACodeTest::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);


}

//class를 만들어 줘야한다.ACodeTest >접두어A가붙는다.조상중에A Actor가있다는뜻
int32 ACodeTest::Add(int32* num1, int32* num2)
{
	//함수를 정의할때는 중괄호{}로 안에 정의한다.
	//실제로 하고싶은일을 여기에 쓰면된다.to do
	return *num1 + *num2;


	//반환할것이니깐 앞에 return을 적어준다.
	//자료형이 달라지만 빌드할때 오류난다. 정수+정수 = 정수
	//함수선언, 구현,하고 실행할때는 함수를 호출해야한다.> 이름만 부르면된다.

	//*num1 *= 2;
	//*num2 *= 2;

	//int32 result = num1 + num2;
	//return result;

}



//ACodeTest::Add 구현할때는 클래스와 함수를 같이 써준다.
//{}중과로가들어가면;처럼 끝내는 역할
int32 ACodeTest::Subtract(int32 num1, int32 num2)
{
	return num1 - num2;
}

float ACodeTest::Divide(int32 num1, int32 num2)
{
	return (float)num1 / (float)num2;
}



int32 ACodeTest::Multiply(int32 num1, int32 num2)
{
	return num1 * num2;
}
//함수정의구현은.cpp(소스)파일에 한다.

////&& 은 And조건
////만일 나이가 20살 이상이면서, 키가 160 이상인 경우에는 
//if (age >= 20 || height >= 160)
//{
//	//"환영"이라고 출력한다.
//	UE_LOG((LogTemp, Warning, TEXT("환영합니다~"));
//}
////그렇지 않으면 
//else
//{
//	//"외면"이라고 출력한다.
//	UE_LOG((LogTemp, Warning, TEXT("실례했니다~"));
//}

//함수 






//
////만일 국적이(nation) "한국"이면서, 나이가"age" 20살 이상 40세 미만인 
//if (nation >= "Korea" && age >= 20)
//{
//	//"환영"이라고 출력한다.
//	UE_LOG((LogTemp, Warning, TEXT("환영합니다~"));
//	
//}
//
//if (nation >= "Korea" && 40 > age)
//{
//	// 경우 "청년"이라고 출력한다.
//	UE_LOG((LogTemp, Warning, TEXT("청년"));
//}
//
//
////그밖에는 "청년 아님"이라고 출력한다. 
//else
//{
//	UE_LOG((LogTemp, Warning, TEXT("청년 아님"));
//}


////국적이"한국"이면서, 나이가 20살 이상 40세 미만일 떄,
//if(Nation == TEXT("한국") && age >= 20&& age < 40)
//{
//	//"청년"이라고 출력한다.
//UE_LOG((LogTemp, Warning, TEXT("청년"));
//}
////그렇지 않으면,
//
//else
//{
//	//"청년이 아니다"라고 출력한다.
//	UE_LOG((LogTemp, Warning, TEXT("청년이 아니시군요"));
//}




FString ACodeTest::Appender(FString string1, FString string2)
{
	return string1 + string2;
}
//함수정의구현은.cpp(소스)파일에 한다.
