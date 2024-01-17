// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Device.h"
#include "Components/ActorComponent.h"
#include "UsableHolderComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPY_API UUsableHolderComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUsableHolderComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnEquipDevice(TSubclassOf<ADevice> Device);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnequipDevice();

	
};
