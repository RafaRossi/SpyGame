// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Interaction.h"

#include "Components/BoxComponent.h"


// Sets default values
AInteractableArea::AInteractableArea()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(FName("Root"));
	
	TriggerArea = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	TriggerArea->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AInteractableArea::BeginPlay()
{
	Super::BeginPlay(); 
	
}

UInteractionComponent::UInteractionComponent()
{
	
}





