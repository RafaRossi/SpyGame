﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBehaviours/AIBehaviour.h"

#include "AIController.h"
#include "Algo/Reverse.h"


// Sets default values for this component's properties
UAIBehaviour::UAIBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UAIBehaviour::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UAIBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AWaypoint* UAIFollowWaypointBehaviour::GetNextWaypoint()
{
	CurrentWaypointIndex++;

	if(CurrentWaypointIndex >= Waypoints.Num() && bLoopWander)
	{
		Algo::Reverse(Waypoints);
	}

	CurrentWaypointIndex = CurrentWaypointIndex % Waypoints.Num();
	
	return Waypoints[CurrentWaypointIndex];
}

void UAIBehaviour::PerformBehaviour()
{
	
}

void UAIFollowWaypointBehaviour::PerformBehaviour()
{
	//Cast<AAIController>(Cast<APawn>(GetOwner())->GetController())->MoveToLocation(GetNextWaypoint()->GetActorLocation(), 0.3f);
}

