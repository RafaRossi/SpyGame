// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Equipable.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UEquipable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPY_API IEquipable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Equip")
	void Equip();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Equip")
	void Unequip();
};



UINTERFACE(Blueprintable)
class UUsable : public UInterface
{
	GENERATED_BODY()
};

class SPY_API IUsable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Usable")
	void Use();
};