// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\AFrozenable.h"

// Sets default values
AFrozenable::AFrozenable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void AFrozenable::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFrozenable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

