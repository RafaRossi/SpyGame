// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "ATriggerButton.generated.h"

/**
 * 
 */
UCLASS()
class SPY_API ATriggerButton : public AStaticMeshActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	ATriggerButton();
};

UCLASS()
class APressureTriggerButton : public ATriggerButton
{
	GENERATED_BODY()

	APressureTriggerButton();
};

