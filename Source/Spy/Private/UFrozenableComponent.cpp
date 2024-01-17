// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\UFrozenableComponent.h"

// Sets default values
UFrozenableComponent::UFrozenableComponent()
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
	UE_LOG(LogTemp, Warning, TEXT("Frozen"))

	AActor* Owner = GetOwner();
	AFrozenCube::CreateCube(FrozenCube, Owner->GetActorLocation(), FRotator::ZeroRotator, Owner);
}

void UFrozenableComponent::Unfreeze_Implementation()
{
	FrozenState = EFrozenState::Unfrozen;
	UE_LOG(LogTemp, Warning, TEXT("Unfrozen"))
}

void UFrozenableComponent::ChangeFrozenState()
{
	/*if(FrozenState == EFrozenState::Frozen)
	{
		Execute_Unfreeze(nullptr);
	}
	else
	{
		Execute_Freeze(nullptr);
	}*/
}

