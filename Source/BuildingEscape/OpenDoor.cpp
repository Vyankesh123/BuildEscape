// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"

#define OUT

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
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw = InitialYaw + TargetYaw;
    
	if(!PressurePlate)
	{
		UE_LOG(LogTemp,Error,TEXT("%s has the open door Component on it,But no pressurePlate set"),*GetOwner()->GetName());
	}
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
	if(TotalMassOfActors() > MassToOpenDoors)
	{
	   OpenDoor(DeltaTime);
	   DoorLastOpened = GetWorld()->GetTimeSeconds();
    }
	else
	{
		if(GetWorld()->GetTimeSeconds() - DoorLastOpened > DoorCloseDelay)
		{
		   CloseDoor(DeltaTime);
		}
	}	
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
    // UE_LOG(LogTemp,Warning ,TEXT("%s"),*GetOwner()->GetActorRotation().ToString());
    // UE_LOG(LogTemp,Warning ,TEXT("Yaw is: %f" ), GetOwner()->GetActorRotation().Yaw);
    CurrentYaw = FMath::Lerp(CurrentYaw,TargetYaw,DeltaTime * DoorOpenSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
    CurrentYaw = FMath::Lerp(CurrentYaw,InitialYaw,DeltaTime * DoorClosedSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}

float UOpenDoor::TotalMassOfActors() const
{
	float TotalMass = 0.f;
    
	TArray<AActor*> OverlappingActors;
	if(!PressurePlate){return TotalMass;}
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for(AActor* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	    UE_LOG(LogTemp,Warning,TEXT("%s is on the pressureplate"),*Actor->GetName());
	}

	return TotalMass;
}