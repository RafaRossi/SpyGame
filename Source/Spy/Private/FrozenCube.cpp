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

AFrozenCube* AFrozenCube::CreateCube(const TSubclassOf<AFrozenCube>& FrozenCube, UWorld* World, const FVector& Location, const FRotator& Rotation, AActor* FrozenActor)
{
	AFrozenCube* NewCube = nullptr;
	
	if (World)
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating APawn at Location: %s, Rotation: %s"), *Location.ToString(), *Rotation.ToString());

		NewCube = World->SpawnActor<AFrozenCube>(FrozenCube, Location, Rotation);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'World' pointer is null in Create"));

		if (UWorld* FallbackWorld = GEngine->GetWorldContexts()[0].World())
		{
			NewCube = FallbackWorld->SpawnActor<AFrozenCube>(FrozenCube, Location, Rotation);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to get fallback world"));
		}
	}

	if(FrozenActor && NewCube)
	{
		FrozenActor->AttachToActor(NewCube, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

		/*if(UPrimitiveComponent* PrimComp = Cast<UPrimitiveComponent>(NewCube->GetRootComponent()))
		{
			PrimComp->SetSimulatePhysics(true);
			PrimComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		}*/
	}

	return NewCube;
}
