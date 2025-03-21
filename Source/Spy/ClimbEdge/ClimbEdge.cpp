// Fill out your copyright notice in the Description page of Project Settings.


#include "ClimbEdge.h"


UClimbHandlerPoint::UClimbHandlerPoint()
{
}


AClimbEdge::AClimbEdge()
{
}


void AClimbEdge::GetNearestClimbPoint(UEdgeDetectionComponent* EdgeDetectionComponent, UClimbHandlerPoint*& NearestClimbHandlerPoint)
{
	const FVector BasePosition = EdgeDetectionComponent->GetOwner()->GetActorLocation();

	float NearestDistanceSquared = TNumericLimits<float>::Max();
	
	for(UClimbHandlerPoint* ClimbHandlerPoint : ClimbHandlerPoints)
	{
		if(ClimbHandlerPoint)
		{
			FVector PointPosition = ClimbHandlerPoint->GetComponentLocation();

			if(const float DistanceSquared = FVector::DistSquared(PointPosition, BasePosition); DistanceSquared < NearestDistanceSquared)
			{
				NearestDistanceSquared = DistanceSquared;
				NearestClimbHandlerPoint = ClimbHandlerPoint;
			}
		}
	}
}

// Called when the game starts or when spawned
void AClimbEdge::BeginPlay()
{
	Super::BeginPlay();
}



