// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineComponent.h"
#include "GameplayTagsModule.h"


UStateMachineComponent::UStateMachineComponent()
{
	bCanTickState = true;
}

bool UStateMachineComponent::SwitchState(const FGameplayTag NewStateTag)
{
	if(!NewStateTag.MatchesTagExact(StateTag))
	{
		bCanTickState = false;

		EndState();

		StateTag = NewStateTag;

		InitState();

		bCanTickState = true;

		if(StateChangedDelegate.IsBound())
		{
			StateChangedDelegate.Broadcast(StateTag);
		}

		return true;
	}

	if(bDebug)
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't switch state for %s, because it is already in %s"), *GetOwner()->GetName(), *StateTag.ToString())
	}

	return false;
}

void UStateMachineComponent::InitState() const
{
	if(InitStateDelegate.IsBound())
	{
		InitStateDelegate.Broadcast(StateTag);
	}
}

void UStateMachineComponent::TickState(const float DeltaTime) const
{
	if(TickStateDelegate.IsBound())
	{
		TickStateDelegate.Broadcast(DeltaTime, StateTag);
	}
}

void UStateMachineComponent::EndState()
{
	if(StateHistory.Num() >= StateHistoryLenght)
	{
		StateHistory.RemoveAt(0);
	}
	StateHistory.Push(this->StateTag);
	
	if(EndStateDelegate.IsBound())
	{
		EndStateDelegate.Broadcast(StateTag);
	}
}

// Called when the game starts
void UStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	SwitchState(InitialStateTag);
	
}


// Called every frame
void UStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(bCanTickState)
	{
		TickState(DeltaTime);
	}
}