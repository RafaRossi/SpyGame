// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveMode.h"

#include "CustomCharacterMovementComponent.h"

void UMoveMode::EnterMode_Implementation(UCustomCharacterMovementComponent* CustomCharacterMovementComponent)
{
	MovementComponent = CustomCharacterMovementComponent;
}

void UMoveMode::ExitMode_Implementation()
{
}

void UMoveMode::Tick_Implementation(float DeltaTime)
{
}


void UMoveMode::PhysUpdate_Implementation(float DeltaTime)
{
}
