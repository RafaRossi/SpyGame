// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Components/ActorComponent.h"
#include "Waypoint.h"
#include "AIBehaviour.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPY_API UAIBehaviour : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAIBehaviour();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void PerformBehaviour();
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPY_API UAIFollowWaypointBehaviour : public UAIBehaviour
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLoopWander;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AWaypoint*> Waypoints;

	virtual void PerformBehaviour() override;
	
	UFUNCTION(BlueprintCallable)
	AWaypoint* GetNextWaypoint();
	
private:
	uint8 CurrentWaypointIndex;
};