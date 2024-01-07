// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "AFrozenable.generated.h"

UCLASS()
class SPY_API AFrozenable : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFrozenable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};

UCLASS()
class ASmallFrozenObject : public AFrozenable
{
	GENERATED_BODY()

public:
	
};

UCLASS()
class ALargeFrozenObject : public AFrozenable
{
	GENERATED_BODY()

public:
	
};
