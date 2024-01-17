// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FrozenCube.h"
#include "FrozenInterface.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "UFrozenableComponent.generated.h"

UENUM(Blueprintable)
enum class EFrozenState : uint8
{
	Frozen		= 0b0000 UMETA(DisplayName="Frozen"),
	Unfrozen	= 0b0001 UMETA(DisplayName="Unfrozen")
};


UCLASS(Blueprintable)
class SPY_API UFrozenableComponent : public UActorComponent, public IFrozenInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UFrozenableComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Freeze_Implementation() override;
	
	virtual void Unfreeze_Implementation() override;
	

	UFUNCTION()
	virtual void ChangeFrozenState();

	UPROPERTY(BlueprintReadWrite, Category="Variables", VisibleAnywhere)
	EFrozenState FrozenState = EFrozenState::Unfrozen;

	UPROPERTY(BlueprintReadWrite, Category="Variables", EditAnywhere, Blueprintable)
	TSubclassOf<AFrozenCube> FrozenCube;
};