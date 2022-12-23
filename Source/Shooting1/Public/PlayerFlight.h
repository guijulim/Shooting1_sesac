// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "PlayerFlight.generated.h"


UCLASS()
class SHOOTING1_API APlayerFlight : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerFlight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = playersetting) //블루프린터에서 볼수있게 유프로퍼티추가
	class UBoxComponent* boxComp;                                             //외부클래스를 인지할때는 헤더에서는 전방선언을 해줘야한다.
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = playersetting)
	class UStaticMeshComponent* meshComp;                                     //다쓰더라고 마지막에 Tab키눌러서 스펠링확인

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PlayerSettings)
	float moveSpeed=500.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerSettings)
	TSubclassOf<class ABullet> bulletFactory;  //언니얼엔진이아닌외부에서 만든 파일을 할때 TSubclassOf사용하면된다.

	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
	class UInputAction* ia_horizontal;

	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
	class UInputAction* ia_vertical;


	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
	class UInputAction* ia_Fire;

	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)

	class UInputMappingContext* IMC_myMapping;

private:
// 	UFUNCTION(BlueprintCallable)
// 	void Horizontal(float value);

	UFUNCTION(BlueprintCallable)
	void Horizontal(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable)
	void Vertical(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable)
	void FireBullet(); //Fire타입은 매개변수는 없애준다.


// 	UFUNCTION(BlueprintCallable)
// 	void Horizontal(const FInputActionValue& Value);
// 	UFUNCTION(BlueprintCallable)
// 	void Vertical(float value);
// 	UFUNCTION(BlueprintCallable)
// 	void FireBullet(); //매개변수를 비워둬야한다.

	float h;
	float v;
	FVector direction;


};
