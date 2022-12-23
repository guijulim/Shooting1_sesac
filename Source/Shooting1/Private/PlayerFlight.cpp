// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFlight.h"
#include "Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"   //��Ÿƽ�� ���̾��¸޽�, 
#include "UObject/ConstructorHelpers.h"      //���ۿ��� ã���� �ϴ� ��� �˻��ؼ� ��Ŭ��� �׺����� �����ؿ���
#include "Bullet.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
APlayerFlight::APlayerFlight()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// �浹�ڽ� ������Ʈ�� �����Ѵ�.
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
    // ������ �浹�ڽ� ������Ʈ�� ��Ʈ ������Ʈ�� �����Ѵ�.
	SetRootComponent(boxComp);   //�ڽ�������Ʈ�� ��Ʈ�� ���������.
	// �ڽ� �ݸ����� ũ�⸦ ����x����x���� ��� 50��Ƽ���ͷ� �����Ѵ�.
	boxComp->SetBoxExtent(FVector(50.0f));   //�� �ڽ��ͽ���Ʈ �Լ��� ����Ѵ�.//������ ���� ������ 50.0f�ϸ� �ȴ�.//�⺻���� �����س����� �������Ʈâ���� �ǵ������ϸ� �⺻�� ������ ��밡 ���������� �� ���ϴ�.

	//�ڽ� �ݸ����� �浹 ó�� �������� "PlayerPreset"���� �����Ѵ�. 
	boxComp->SetCollisionProfileName(TEXT("PlayerPreset"));


	//�޽� ������Ʈ�� �����Ѵ�.
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	//�޽� ������Ʈ�� ��Ʈ ������Ʈ�� ���� ��ü�� ����Ѵ�.
	meshComp->SetupAttachment(RootComponent);

	//�޽� ������Ʈ�� static mesh �׸� ť�� ������ �Ҵ��Ѵ�.
	ConstructorHelpers::FObjectFinder<UStaticMesh>cubeMesh(TEXT("/Script / Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")); //�޽�,���׸��� �Լ� �������� ���δ��� ã�´�.

	//����, ť�� ������ �ε��ϴµ� �����ߴٸ�...
	if (cubeMesh.Succeeded())
	{
	//�ε��� ������ �޽� ������Ʈ�� static mesh �׸� �ִ´�.   -> �� . ������ ->�����ͺ���  . �� �׳� Ŭ���� ����
	meshComp->SetStaticMesh(cubeMesh.Object);

	}



}

// Called when the game starts or when spawned
void APlayerFlight::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* playerCon = Cast<APlayerController> (GetController()); //�Լ��� �����Ǿ������� �Լ��κҷ����� ��������.

	if (playerCon != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* subsys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerCon->GetLocalPlayer());


		if (subsys != nullptr)
		{
			subsys->AddMappingContext(IMC_myMapping, 0);
		}
	}
}

// Called every frame
void APlayerFlight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // ����ڰ� �Է��� ������ �̵��ϰ� �ʹ�. ���������üũ�ؾ� �ϴ� Tick���� �����Ѵ�.
	// ������ ����ȭ
	direction.Normalize();  //Normalize ������ ����ȭ

	// P = P0 + vt
	FVector dir = GetActorLocation() + direction * moveSpeed * DeltaTime;  //
	SetActorLocation(dir);
}
 
// Called to bind functionality to input
void APlayerFlight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) //SetupPlayerInputComponent ����â���� ����ƮŰ�� �������� �Է¹޴��Լ�
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//������ UInputComponent* ������ UEnhancedInputComponent*�� ��ȯ�Ѵ�.
	UEnhancedInputComponent*enhacedInputComponent=Cast<UEnhancedInputComponent>(PlayerInputComponent);

	//�Լ������ϱ�
	enhacedInputComponent->BindAction(ia_horizontal, ETriggerEvent::Triggered, this, &APlayerFlight::Horizontal);
	enhacedInputComponent->BindAction(ia_horizontal, ETriggerEvent::Completed, this, &APlayerFlight::Horizontal);

	enhacedInputComponent->BindAction(ia_vertical, ETriggerEvent::Triggered, this, &APlayerFlight::Vertical);
	enhacedInputComponent->BindAction(ia_vertical, ETriggerEvent::Completed, this, &APlayerFlight::Vertical);

	enhacedInputComponent->BindAction(ia_Fire, ETriggerEvent::Triggered, this, &APlayerFlight::FireBullet);

	
// 	//Horizontal Axis �Է¿� �Լ��� �����Ѵ�. �Լ� �����Ͷ�� �Ѵ�. �Լ��� �ּҰ��� �Ѱ��ְ�
// 	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerFlight::Horizontal);
// 
// 	//Vertical Axis �Է¿� �Լ��� �����Ѵ�.
// 	PlayerInputComponent->BindAxis("Vertical", this, &APlayerFlight::Vertical);
// 	
// 	
// 	//Fire Action �Է¿� �Լ��� �����Ѵ�.
// 	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerFlight::FireBullet);



}

// �¿� �Է��� ���� �� ����� �Լ�
// void APlayerFlight::Horizontal(float value)
// {
// 	h = value;
// 	//UE_LOG(LogTemp, Warning, TEXT("h:%.4f"), h);
// 	direction.Y = h;     //h=1�̸� �����ʺ���. d�� ��
// }

void APlayerFlight::Horizontal(const FInputActionValue& Value)
{
	h = Value.Get<float>();
	UE_LOG(LogTemp, Warning, TEXT("h:%.4f"), h);
	direction.Y = h;
}

//���� �Է��� ���� �� ����� �Լ�
// void APlayerFlight::Vertical(float value)
// {
// 	v = value;
// 	//UE_LOG(LogTemp, Warning, TEXT("h:%.4f"), v);
// 	direction.Z = v;  //W������ ���ΰ��� ����, SŰ�� �Ʒ��ΰ��� ����, �ƹ��͵� �ȴ�����.�Ѵٴ����� �Ѵٴ����ش�.
// }

void APlayerFlight::Vertical(const FInputActionValue& value)
{
	//UE_LOG(LogTemp, Warning, TEXT("h:%.4f"), v);
	v = value.Get<float>();
	direction.Z = v;
}

//���콺 ������ư�� �������� �߻�� �Լ�
void APlayerFlight::FireBullet()
{
	//�Ѿ��� �����Ѵ�.
	//�Ѿ� �������Ʈ ����
	FVector spawnPosition = GetActorLocation() + GetActorUpVector() * 90.0f;//GetActorUpVector() ���������̱⶧����1  , 90.0f;��ġ�� ���ϸ� 90
	FRotator spawnRotation = FRotator(90.0f, 0, 0);
	FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride =ESpawnActorCollisionHandlingMethod::AlwaysSpawn ;//SpawnCollisionHandlingOverride ������Ʈ�� �����ƴµ�, �������ڸ��� �ε�ĥ�� ��� �������ٱ��Ҷ��ϴ� �ɼ�
	GetWorld()->SpawnActor< ABullet > (bulletFactory, spawnPosition, spawnRotation, param);//GetWorld()->SpawnActor()������忡�� �������͸� �����Ҳ���

}
