// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"


UENUM(BlueprintType)
enum class EMovementState : uint8 {
	Mobility,
	Static
};

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	FString InstanceName = UObject::GetName();

	UPROPERTY(EditInstanceOnly)
	int EnemyNum = 0;

	UPROPERTY(EditInstanceOnly)
	bool isAlive = false;

	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();

	UPROPERTY(EditInstanceOnly)
	double Amplitude = 10.0;
		
	UPROPERTY(EditInstanceOnly)
	double Frequency = 10.0;

	UPROPERTY(EditInstanceOnly)
	FVector InitialLocation{10.0f, 10.0f, 10.0f};

	UFUNCTION(BlueprintCallable)
	void SinMovement();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

USTRUCT(BlueprintType)
struct FTransformStruct {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotator = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

