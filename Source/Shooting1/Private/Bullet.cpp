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

	//�Ѿ� ���� ����
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	boxComp->SetWorldScale3D(FVector(0.75f, 0.25f, 1.0));  //����Ʈ��
	//�ڽ� �ݸ����� �浹 ó�� �������� "BulletPreset"���� �����Ѵ�. 
	boxComp->SetCollisionProfileName(TEXT("BulletPreset"));

	//�޽� ����
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	meshComp->SetupAttachment(RootComponent);
	meshComp->SetRelativeLocation(FVector(0, 0, -50.0f)); //Relative �������
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	//�浹(������)�� �߻��ϸ� ������ �Լ��� �����Ѵ�
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//���� ���� �������� ��� �̵��ϰ� �ʹ�.
	//direction = FVector(1, 0, 0);     //������ 1�̶�� ������������ ����
	direction = GetActorForwardVector(); //����� ���Ƽ��� ���� ������ ���̵Ǵ°�

	SetActorLocation(GetActorLocation() + direction * moveSpeed * DeltaTime);//P=p0+vt

	
}


void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//����, �ε��� ����� �Ѿ��̶��

	AEnemy* enemy = Cast<AEnemy>(OtherActor);

	if (enemy != nullptr)
	{
		//���� �����Ѵ�.
		enemy->Destroy();

		//�� �ڽŵ� �����Ѵ�.
		Destroy();
	}
}