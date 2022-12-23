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

	//Collision Enemy ���� Query and Physics�� �����Ѵ�.
	boxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//���� ä���� Object Type�� "Enemy"�� �����Ѵ�.
	boxComp->SetCollisionObjectType(ECC_GameTraceChannel2);

	//���� ä���� �ϰ������� Ignote���·� ó���Ѵ�.
	boxComp->SetCollisionResponseToAllChannels(ECR_Ignore);

	//���� ä���� Player�� Bullet ä�ο� ���ؼ��� overlap���� ó���Ѵ�.
	boxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);
	boxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel3, ECR_Overlap);


	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	meshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	//�浹(������)�� �߻��ϸ� ������ �Լ��� �����Ѵ�.





	// ��÷�� �ؼ� �ϳ��� ���� ����, �� �ٸ� �ϳ��� �÷��̾� �������� �̵��ϰ� �ʹ�.(�������߻�������ü������)
	// 1. ��÷�� �Ѵ�. Ȯ����(�����θ������°�������) ������ �̿��ؼ� ����70 : 30 �������Ѵ�. ��Ͼ����� �����Լ�����
	int32 drawNumber = FMath::RandRange(1,100);
	
	// 2.   ����, ���� ���� traceRate���� ������...(���ǹ��ʿ�.)
	if (drawNumber <= traceRate)
	{
    
		//���忡�� Ư���� ��ü�� ã�� ��� -1
	// 2-1 �÷��̾� ���͸� ã�´�.
	    /*/AActor* target = UGameplayStatics::GetActorOfClass(GetWorld()),
		APlayerFlight::StaticClass());*/
		
		
	//���忡�� Ư���� ��ü�� ã�� ��� -2
	
	for(TActorIterator<APlayerFlight> it(GetWorld()); it; ++it)
	{
	    target = *it;
	}
	//float temp=target->moveSpeed;   //�����ڵ��� ���ڵ带���̾���.

	if (target != nullptr) //=
	{
		float temp = target->moveSpeed;
	}

	// 2-2. �÷��̾��� ��ġ - ���� ��ġ = �� ������ �����Ѵ�.
	FVector targetDir = target->GetActorLocation() - GetActorLocation();
	targetDir.Normalize();
	direction = targetDir;
	}
	
	// 3.   �׷��� ������... (70���� ũ�ٴ� ��)
	else
	{
	// 3-1. �������� ������ ���Ѵ�.
		direction = GetActorForwardVector();
	}
  

}
//�ѹ����� �����̸� ���������� ����. ���������� �޸��ѹ����� �ٽû������. �׷��� ���������� ��������ʴ´�. �޸𸮹���������.


// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//���� ���� �������� ��� �̵��ϰ� �ʹ�.
	//direction = FVector(1, 0, 0);     //������ 1�̶�� ������������ ����
	//direction = GetActorForwardVector(); //����� ���Ƽ��� ���� ������ ���̵Ǵ°�

	SetActorLocation(GetActorLocation() + direction * moveSpeed * DeltaTime);//P=p0+vt
}

