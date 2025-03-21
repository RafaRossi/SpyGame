// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Engine/StaticMeshActor.h"
#include "ClimbEdge.generated.h"

class AClimbEdge;

UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class UClimbHandlerPoint : public USceneComponent
{
	GENERATED_BODY()

public:
	UClimbHandlerPoint();
	
	UPROPERTY(BlueprintReadWrite)
	UClimbHandlerPoint* PreviousClimbHandlerPoint;

	UPROPERTY(BlueprintReadWrite)
	UClimbHandlerPoint* NextClimbHandlerPoint;
};

UCLASS(Blueprintable)
class UEdgeDetectionComponent : public UCapsuleComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AClimbEdge* CurrentClimbEdge;
};

UCLASS()
class SPY_API AClimbEdge : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AClimbEdge();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UClimbHandlerPoint*> ClimbHandlerPoints;

	UFUNCTION(BlueprintCallable)
	void GetNearestClimbPoint(UEdgeDetectionComponent* EdgeDetectionComponent, UClimbHandlerPoint*& NearestClimbHandlerPoint);

protected:
	virtual void BeginPlay() override;
};



