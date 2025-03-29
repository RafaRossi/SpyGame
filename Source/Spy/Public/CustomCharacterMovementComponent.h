// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveMode.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CustomCharacterMovementComponent.generated.h"

struct FMoveModeObject;

UENUM(Blueprintable)
enum class ECustomCharacterMovementMode : uint8
{
	Move_None UMETA(Hidden),
	Move_Ground UMETA(DisplayName = "Ground"),				//Padrão
	Move_Falling UMETA(DisplayName = "Falling"),			//Queda
	Move_Hanging UMETA(DisplayName = "Hanging"),			//Segurando na Beirada
	Move_SlopeSlide UMETA(DisplayName = "Slope Slide"),		//Escorregando
	Move_Rail UMETA(DisplayName = "Rail"),					//Seguindo Trilha
	Move_TightRope UMETA(DisplayName = "Tight Rope"),		//Corda Bamba
	Move_Climb UMETA(DisplayName = "Climb"),				//Escalando
	Move_Ladder UMETA(DisplayName = "Ladder"),				//Escada
	Move_WallSlide UMETA(DisplayName = "Wall Slide"),		//Deslizando na Parede
	Move_Death UMETA(DisplayName = "Death"),				//Morto
};

USTRUCT(BlueprintType)
struct FCoyoteTimeData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanJump;

	FCoyoteTimeData() : Duration(0.2f), MinSpeed(0.f), bCanJump(true) {}
};

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPY_API UCustomCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	ECustomCharacterMovementMode CurrentMovementMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FCoyoteTimeData CoyoteTimeData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	TMap<ECustomCharacterMovementMode, FMoveModeObject> MoveModes;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SetCustomCharacterMovementMode(ECustomCharacterMovementMode NewMode);

	UMoveMode* GetMoveMode(ECustomCharacterMovementMode CustomMovementMode);

protected:
	bool bWasAscending;
	bool bIsInitialized;
	float DefaultGravity = GravityScale;

	FTimerHandle DelayedTimeHandler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Jumping")
	float PreFallGravityMultiplier;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Jumping")
	float FallGravityMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Jumping")
	float TimeToFall;
	
	virtual void PhysCustom(float DeltaTime, int32 Iterations) override;
	virtual void PhysFalling(float deltaTime, int32 Iterations) override;

	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;
	
	virtual void OnReachedJumpApex();

	virtual void OnComponentCreated() override;
};

