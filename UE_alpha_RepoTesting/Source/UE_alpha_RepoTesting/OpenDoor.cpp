// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	this->ActorToOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	this->ComponentOwner = GetOwner();
	this->DefaultRotation = ComponentOwner->GetActorRotation();
	this->MaxYawRotation = DefaultRotation.Yaw + 80;
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	(this->PressurePlate->IsOverlappingActor(this->ActorToOpen)) ? OpenDoor() : CloseDoor();

}

void UOpenDoor::OpenDoor()
{
	FRotator CurrentRotation = this->ComponentOwner->GetActorRotation();
	if (CurrentRotation.Yaw != this->MaxYawRotation)
	{
		(CurrentRotation.Yaw < this->MaxYawRotation)
			? CurrentRotation.Yaw += this->DoorOpenRate
			: CurrentRotation.Yaw = this->MaxYawRotation;
		this->ComponentOwner->SetActorRotation(CurrentRotation);
	}
}

void UOpenDoor::CloseDoor()
{
	FRotator CurrentRotation = this->ComponentOwner->GetActorRotation();
	if (CurrentRotation != this->DefaultRotation)
	{
		(CurrentRotation.Yaw > this->DefaultRotation.Yaw)
			? CurrentRotation.Yaw -= this->DoorCloseRate
			: CurrentRotation.Yaw = this->DefaultRotation.Yaw;
		this->ComponentOwner->SetActorRotation(CurrentRotation);
	}
}

