// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_ALPHA_REPOTESTING_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

private:
	FRotator DefaultRotation;

	UPROPERTY(VisibleAnywhere)
	AActor* ComponentOwner;
	UPROPERTY(VisibleAnywhere)
	AActor* ActorToOpen;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void CloseDoor();

	void OpenDoor();

		
};
