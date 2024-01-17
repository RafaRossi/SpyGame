// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PushPullInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UPushInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPY_API IPushInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, Category="Push")
	void StartPush();
	UFUNCTION(BlueprintNativeEvent, Category="Push")
	void EndPush();
};

UINTERFACE()
class UPullInterface : public UInterface
{
	GENERATED_BODY()
};

class SPY_API IPullInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, Category="Pull")
	void StartPull();
	UFUNCTION(BlueprintNativeEvent, Category="Pull")
	void EndPull();
};
