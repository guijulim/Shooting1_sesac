// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h" 
#include "PlayerFlight.h"
#include "EngineUtils.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50.0f));

	//Collision Enemy 값을 Query and Physics로 설정한다.
	boxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//응답 채널의 Object Type을 "Enemy"로 설정한다.
	boxComp->SetCollisionObjectType(ECC_GameTraceChannel2);

	//응답 채널을 일괄적으로 Ignote상태로 처리한다.
	boxComp->SetCollisionResponseToAllChannels(ECR_Ignore);

	//응답 채널의 Player와 Bullet 채널에 대해서만 overlap으로 처리한다.
	boxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);
	boxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel3, ECR_Overlap);


	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	meshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	//충돌(오버랩)이 발생하면 실행할 함수를 연결한다.





	// 추첨을 해서 하나는 정면 방향, 또 다른 하나는 플레이어 방향으로 이동하고 싶다.(아직은추상적더구체적으로)
	// 1. 추첨을 한다. 확률은(변수로만들어놓는것이좋다) 변수를 이용해서 정면70 : 30 비율로한다. 언니얼제공 렌덤함수있음
	int32 drawNumber = FMath::RandRange(1,100);
	
	// 2.   만일, 뽑은 값이 traceRate보다 작으면...(조건문필요.)
	if (drawNumber <= traceRate)
	{
    
		//월드에서 특정한 객체를 찾는 방법 -1
	// 2-1 플레이어 엑터를 찾는다.
	    /*/AActor* target = UGameplayStatics::GetActorOfClass(GetWorld()),
		APlayerFlight::StaticClass());*/
		
		
	//월드에서 특정한 객체를 찾는 방법 -2
	
	for(TActorIterator<APlayerFlight> it(GetWorld()); it; ++it)
	{
	    target = *it;
	}
	//float temp=target->moveSpeed;   //개발자들이 이코드를많이쓴다.

	if (target != nullptr) //=
	{
		float temp = target->moveSpeed;
	}

	// 2-2. 플레이어의 위치 - 나의 위치 = 갈 방향을 설정한다.
	FVector targetDir = target->GetActorLocation() - GetActorLocation();
	targetDir.Normalize();
	direction = targetDir;
	}
	
	// 3.   그렇지 않으면... (70보다 크다는 뜻)
	else
	{
	// 3-1. 정면으로 방향을 정한다.
		direction = GetActorForwardVector();
	}
  

}
//한번쓰고 말것이면 지역변수로 쓴다. 지역변수는 메모리한번쓰고 다시사라진다. 그래서 전역변수는 사용하지않는다. 메모리문제때문에.


// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//나의 정면 방향으로 계속 이동하고 싶다.
	//direction = FVector(1, 0, 0);     //앞으로 1이라는 절대적인정면 벡터
	//direction = GetActorForwardVector(); //사람이 돌아서면 보는 정면이 앞이되는것

	SetActorLocation(GetActorLocation() + direction * moveSpeed * DeltaTime);//P=p0+vt
}

