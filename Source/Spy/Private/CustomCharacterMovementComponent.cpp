// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomCharacterMovementComponent.h"
#include "MoveMode.h"


void UCustomCharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	if(UMoveMode* MoveMode = GetMoveMode(CurrentMovementMode))
	{
		MoveMode->PhysUpdate(deltaTime);
	}
}

void UCustomCharacterMovementComponent::PhysFalling(float deltaTime, int32 Iterations)
{
	Super::PhysFalling(deltaTime, Iterations);

	if(Velocity.Z < 0.0f && bWasAscending)
	{
		OnReachedJumpApex();
		bWasAscending = false;
	}
	else if(Velocity.Z > 0.0f)
	{
		bWasAscending = true;
	}
}

void UCustomCharacterMovementComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);

	if(MovementMode == MOVE_Walking)
	{
		GravityScale = DefaultGravity;
	}
}

void UCustomCharacterMovementComponent::OnReachedJumpApex()
{
	GravityScale *= PreFallGravityMultiplier;

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(DelayedTimeHandler, [this]()
		{
			GravityScale = DefaultGravity * FallGravityMultiplier;
		}, TimeToFall, false);
	}
}

void UCustomCharacterMovementComponent::OnComponentCreated()
{
	Super::OnComponentCreated();
	
	DefaultGravity = GravityScale;
}

void UCustomCharacterMovementComponent::SetCustomCharacterMovementMode(ECustomCharacterMovementMode NewMode)
{
	if(NewMode == CurrentMovementMode) return;

	if(UMoveMode* MoveMode = GetMoveMode(CurrentMovementMode))
	{
		MoveMode->ExitMode();
	}
	
	CurrentMovementMode = NewMode;

	if(UMoveMode* MoveMode = GetMoveMode(CurrentMovementMode))
	{
		MoveMode->EnterMode(this);
	}

	SetMovementMode(MOVE_Custom, static_cast<uint8>(NewMode));
}

UMoveMode* UCustomCharacterMovementComponent::GetMoveMode(ECustomCharacterMovementMode DesiredMoveMode)
{
	if(MoveModes.Contains(DesiredMoveMode))
	{
		if(auto [MoveModeClass, MoveModeInstance] = MoveModes[DesiredMoveMode]; MoveModeInstance.IsValid())
		{
			return MoveModeInstance.Get();
		}
		else
		{
			MoveModes[DesiredMoveMode].MoveModeInstance = NewObject<UMoveMode>(this, MoveModeClass.Get());
			return MoveModes[DesiredMoveMode].MoveModeInstance.Get();
		}
	}
	
	return nullptr;
}
