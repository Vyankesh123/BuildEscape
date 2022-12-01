// Fill out your copyright notice in the Description page of Project Settings.


#include "Reswap.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UReswap::UReswap()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UReswap::BeginPlay()
{
	Super::BeginPlay();

	// ActorR = GetWorld()->GetFirstPlayerController()->GetPawn();

	
	
}


// Called every frame
void UReswap::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
	if(PressurePlate1 && PressurePlate1->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn()))
	{
        GetOwner()->SetActorLocation(startLoc,false);
	
	}
	
}

