// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFlight.h"
#include "Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"   //스타틱은 본이없는메쉬, 
#include "UObject/ConstructorHelpers.h"      //구글에서 찾고자 하는 헤더 검색해서 인클루드 항복에서 복사해오기
#include "Bullet.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
APlayerFlight::APlayerFlight()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// 충돌박스 컴포넌트를 생성한다.
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
    // 생성된 충돌박스 컴포넌트를 루트 컴포넌트로 설정한다.
	SetRootComponent(boxComp);   //박스컴포넌트가 루트로 만들어진다.
	// 박스 콜리전의 크기를 가로x세로x높이 모두 50센티미터로 설정한다.
	boxComp->SetBoxExtent(FVector(50.0f));   //셋 박스익스텐트 함수를 사용한다.//세개의 값이 같으면 50.0f하면 된다.//기본값을 설정해놓으면 블루프린트창에서 되돌리기하면 기본값 기준의 토대가 잡혀있으면 더 편하다.

	//박스 콜리전의 충돌 처리 프리셋을 "PlayerPreset"으로 설정한다. 
	boxComp->SetCollisionProfileName(TEXT("PlayerPreset"));


	//메시 컴포넌트를 생성한다.
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	//메시 컴포넌트를 루트 컴포넌트의 하위 개체로 등록한다.
	meshComp->SetupAttachment(RootComponent);

	//메시 컴포넌트의 static mesh 항목에 큐브 파일을 할당한다.
	ConstructorHelpers::FObjectFinder<UStaticMesh>cubeMesh(TEXT("/Script / Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")); //메쉬,메테리얼 함수 오브젝터 파인더로 찾는다.

	//만일, 큐브 파일을 로드하는데 성공했다면...
	if (cubeMesh.Succeeded())
	{
	//로드한 파일을 메시 컴포넌트의 static mesh 항목에 넣는다.   -> 와 . 의차이 ->포인터변수  . 은 그냥 클래스 변수
	meshComp->SetStaticMesh(cubeMesh.Object);

	}



}

// Called when the game starts or when spawned
void APlayerFlight::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* playerCon = Cast<APlayerController> (GetController()); //함수가 구현되어있음녀 함수로불러오는 것이좋다.

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

    // 사용자가 입력한 방향대로 이동하고 싶다. 방향은계속체크해야 하니 Tick에서 구현한다.
	// 벡터의 정규화
	direction.Normalize();  //Normalize 벡터의 정규화

	// P = P0 + vt
	FVector dir = GetActorLocation() + direction * moveSpeed * DeltaTime;  //
	SetActorLocation(dir);
}
 
// Called to bind functionality to input
void APlayerFlight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) //SetupPlayerInputComponent 에딧창설정 엑시트키를 눌렀을때 입력받는함수
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//기존의 UInputComponent* 변수를 UEnhancedInputComponent*로 변환한다.
	UEnhancedInputComponent*enhacedInputComponent=Cast<UEnhancedInputComponent>(PlayerInputComponent);

	//함수연결하기
	enhacedInputComponent->BindAction(ia_horizontal, ETriggerEvent::Triggered, this, &APlayerFlight::Horizontal);
	enhacedInputComponent->BindAction(ia_horizontal, ETriggerEvent::Completed, this, &APlayerFlight::Horizontal);

	enhacedInputComponent->BindAction(ia_vertical, ETriggerEvent::Triggered, this, &APlayerFlight::Vertical);
	enhacedInputComponent->BindAction(ia_vertical, ETriggerEvent::Completed, this, &APlayerFlight::Vertical);

	enhacedInputComponent->BindAction(ia_Fire, ETriggerEvent::Triggered, this, &APlayerFlight::FireBullet);

	
// 	//Horizontal Axis 입력에 함수를 연결한다. 함수 포인터라고 한다. 함수에 주소값을 넘겨주고
// 	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerFlight::Horizontal);
// 
// 	//Vertical Axis 입력에 함수를 연결한다.
// 	PlayerInputComponent->BindAxis("Vertical", this, &APlayerFlight::Vertical);
// 	
// 	
// 	//Fire Action 입력에 함수를 연결한다.
// 	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerFlight::FireBullet);



}

// 좌우 입력이 있을 때 실행될 함수
// void APlayerFlight::Horizontal(float value)
// {
// 	h = value;
// 	//UE_LOG(LogTemp, Warning, TEXT("h:%.4f"), h);
// 	direction.Y = h;     //h=1이면 오른쪽벡터. d를 누
// }

void APlayerFlight::Horizontal(const FInputActionValue& Value)
{
	h = Value.Get<float>();
	UE_LOG(LogTemp, Warning, TEXT("h:%.4f"), h);
	direction.Y = h;
}

//상하 입력이 있을 때 실행될 함수
// void APlayerFlight::Vertical(float value)
// {
// 	v = value;
// 	//UE_LOG(LogTemp, Warning, TEXT("h:%.4f"), v);
// 	direction.Z = v;  //W누르면 위로가는 벡터, S키는 아래로가는 벡터, 아무것도 안누르면.둘다누르면 둘다더해준다.
// }

void APlayerFlight::Vertical(const FInputActionValue& value)
{
	//UE_LOG(LogTemp, Warning, TEXT("h:%.4f"), v);
	v = value.Get<float>();
	direction.Z = v;
}

//마우스 왼족버튼을 눌렀을때 발사될 함수
void APlayerFlight::FireBullet()
{
	//총알을 생성한다.
	//총알 블루프린트 변수
	FVector spawnPosition = GetActorLocation() + GetActorUpVector() * 90.0f;//GetActorUpVector() 단위벡터이기때문에1  , 90.0f;센치를 곱하면 90
	FRotator spawnRotation = FRotator(90.0f, 0, 0);
	FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride =ESpawnActorCollisionHandlingMethod::AlwaysSpawn ;//SpawnCollisionHandlingOverride 오브젝트가 생성됐는데, 생성되자마자 부디칠때 어떻게 설정해줄까할때하는 옵션
	GetWorld()->SpawnActor< ABullet > (bulletFactory, spawnPosition, spawnRotation, param);//GetWorld()->SpawnActor()현재월드에서 스폰엑터를 생성할꺼야

}
