// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\FrozenableComponent.h"

// Sets default values
UFrozenableComponent::UFrozenableComponent(): FrozenCubeInstance(nullptr)
{
}

// Called when the game starts or when spawned
void UFrozenableComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UFrozenableComponent::Freeze_Implementation()
{
	FrozenState = EFrozenState::Frozen;

	AActor* Owner = GetOwner();
	FrozenCubeInstance = AFrozenCube::CreateCube(FrozenCube, GetWorld(), Owner->GetActorLocation(), FRotator::ZeroRotator, Owner);
	
}

void UFrozenableComponent::Unfreeze_Implementation()
{
	FrozenState = EFrozenState::Unfrozen;

	if (const AActor* Owner = GetOwner(); Owner && FrozenCubeInstance)
	{
		FrozenCubeInstance->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	}
	
	if(FrozenCubeInstance)
	{
		FrozenCubeInstance->Destroy();
		FrozenCubeInstance = nullptr;
	}
}

void UFrozenableComponent::ChangeFrozenState()
{
	if(FrozenState == EFrozenState::Frozen)
	{
		Frozen();
	}
	else
	{
		Unfrozen();
	}
}

void UFrozenableComponent::Frozen()
{
	if(FrozenState != EFrozenState::Frozen)
	{
		Execute_Freeze(this);
	}
}

void UFrozenableComponent::Unfrozen()
{
	if(FrozenState == EFrozenState::Frozen)
	{
		Execute_Unfreeze(this);
	}
}



