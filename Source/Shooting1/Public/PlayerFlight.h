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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = playersetting) //��������Ϳ��� �����ְ� ��������Ƽ�߰�
	class UBoxComponent* boxComp;                                             //�ܺ�Ŭ������ �����Ҷ��� ��������� ���漱���� ������Ѵ�.
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = playersetting)
	class UStaticMeshComponent* meshComp;                                     //�پ������ �������� TabŰ������ ���縵Ȯ��

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PlayerSettings)
	float moveSpeed=500.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerSettings)
	TSubclassOf<class ABullet> bulletFactory;  //��Ͼ����̾ƴѿܺο��� ���� ������ �Ҷ� TSubclassOf����ϸ�ȴ�.

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
	void FireBullet(); //FireŸ���� �Ű������� �����ش�.


// 	UFUNCTION(BlueprintCallable)
// 	void Horizontal(const FInputActionValue& Value);
// 	UFUNCTION(BlueprintCallable)
// 	void Vertical(float value);
// 	UFUNCTION(BlueprintCallable)
// 	void FireBullet(); //�Ű������� ����־��Ѵ�.

	float h;
	float v;
	FVector direction;


};
