// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipable.h"
#include "GameFramework/Actor.h"
#include "Interaction.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPY_API AInteractableArea : public AActor, public IUsable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractableArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* TriggerArea;

	UPROPERTY(EditAnywhere)
	class UInteractionComponent* CurrentInteraction;
};

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractionComponent();
};
