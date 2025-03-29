// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveMode.generated.h"

class UMoveMode;
class UCustomCharacterMovementComponent;

USTRUCT(BlueprintType)
struct FMoveSettings
{
	GENERATED_BODY()

	
};

USTRUCT(BlueprintType)
struct FMoveModeObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<UMoveMode> MoveModeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<UMoveMode> MoveModeInstance;
};

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class SPY_API UMoveMode : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UCustomCharacterMovementComponent* MovementComponent;

public:
	UFUNCTION(BlueprintNativeEvent)
	void EnterMode(UCustomCharacterMovementComponent* CustomCharacterMovementComponent);
	virtual void EnterMode_Implementation(UCustomCharacterMovementComponent* CustomCharacterMovementComponent);

	UFUNCTION(BlueprintNativeEvent)
	void ExitMode();
	virtual void ExitMode_Implementation();
	
	UFUNCTION(BlueprintNativeEvent)
	void Tick(float DeltaTime);
	virtual void Tick_Implementation(float DeltaTime);

	UFUNCTION(BlueprintNativeEvent)
	void PhysUpdate(float DeltaTime);
	virtual void PhysUpdate_Implementation(float DeltaTime);
};