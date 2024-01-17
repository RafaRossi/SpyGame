// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipable.h"
#include "PickableObjectInterface.h"
#include "PushPullInterface.h"
#include "Engine/StaticMeshActor.h"
#include "FrozenCube.generated.h"

/**
 * 
 */
UCLASS()
class SPY_API AFrozenCube : public AActor
{
	GENERATED_BODY()
public:
	AFrozenCube();

protected:
	virtual void BeginPlay() override;

public:
	
	UFUNCTION(Blueprintable)
	static void CreateCube(const TSubclassOf<AFrozenCube>& FrozenCube, const FVector& Location, const FRotator& Rotation, AActor* FrozenActor);
};

UCLASS()
class AFrozenCubeSmall : public AFrozenCube, public IPickableObjectInterface, public IUsable
{
	GENERATED_BODY()

public:
	AFrozenCubeSmall();
};

UCLASS()
class AFrozenCubeLarge : public AFrozenCube, public IPushInterface, public IPullInterface, public IUsable
{
	GENERATED_BODY()

public:
	AFrozenCubeLarge();

	
};

