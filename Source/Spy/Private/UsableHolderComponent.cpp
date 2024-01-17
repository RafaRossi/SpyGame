// Fill out your copyright notice in the Description page of Project Settings.


#include "UsableHolderComponent.h"

UUsableHolderComponent::UUsableHolderComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UUsableHolderComponent::BeginPlay()
{
	Super::BeginPlay();
}

