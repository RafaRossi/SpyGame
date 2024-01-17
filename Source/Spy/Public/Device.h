// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipable.h"
#include "Engine/StaticMeshActor.h"
#include "Device.generated.h"

UCLASS()
class SPY_API ADevice : public AActor, public IEquipable, public IUsable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADevice();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite, Category="Variables", VisibleAnywhere)
	FName SocketName = "hand_lSocket";
};
