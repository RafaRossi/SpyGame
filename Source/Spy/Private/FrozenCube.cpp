// Fill out your copyright notice in the Description page of Project Settings.


#include "FrozenCube.h"

AFrozenCube::AFrozenCube()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AFrozenCube::BeginPlay()
{
	Super::BeginPlay();
}

void AFrozenCube::CreateCube(const TSubclassOf<AFrozenCube>& FrozenCube, UWorld* World, const FVector& Location, const FRotator& Rotation, AActor* FrozenActor)
{
	if (World)
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating APawn at Location: %s, Rotation: %s"), *Location.ToString(), *Rotation.ToString());

		AFrozenCube* NewCube = World->SpawnActor<AFrozenCube>(FrozenCube, Location, Rotation);

		if(FrozenActor) FrozenActor->AttachToActor(NewCube, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'World' pointer is null in Create"));
		
		AFrozenCube* NewCube = GEngine->GetWorldContexts()[0].World()->SpawnActor<AFrozenCube>(FrozenCube, Location, Rotation);

		if(FrozenActor) FrozenActor->AttachToActor(NewCube, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
}
