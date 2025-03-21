// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "FrozenCube.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SPY_API AFrozenCube : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AFrozenCube();

protected:
	virtual void BeginPlay() override;

public:
	
	UFUNCTION(Blueprintable)
	static AFrozenCube* CreateCube(const TSubclassOf<AFrozenCube>& FrozenCube, UWorld* World, const FVector& Location, const FRotator& Rotation, AActor* FrozenActor);
};

