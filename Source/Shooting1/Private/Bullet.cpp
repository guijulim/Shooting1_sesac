// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Enemy.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//총알 영역 생성
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	boxComp->SetWorldScale3D(FVector(0.75f, 0.25f, 1.0));  //디폴트값
	//박스 콜리전의 충돌 처리 프리셋을 "BulletPreset"으로 설정한다. 
	boxComp->SetCollisionProfileName(TEXT("BulletPreset"));

	//메쉬 생성
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	meshComp->SetupAttachment(RootComponent);
	meshComp->SetRelativeLocation(FVector(0, 0, -50.0f)); //Relative 상대적인
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	//충돌(오버랩)이 발생하면 실행할 함수를 연결한다
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//나의 정면 방향으로 계속 이동하고 싶다.
	//direction = FVector(1, 0, 0);     //앞으로 1이라는 절대적인정면 벡터
	direction = GetActorForwardVector(); //사람이 돌아서면 보는 정면이 앞이되는것

	SetActorLocation(GetActorLocation() + direction * moveSpeed * DeltaTime);//P=p0+vt

	
}


void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//만일, 부딪힌 대상이 총알이라면

	AEnemy* enemy = Cast<AEnemy>(OtherActor);

	if (enemy != nullptr)
	{
		//적을 제거한다.
		enemy->Destroy();

		//나 자신도 제거한다.
		Destroy();
	}
}