// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPostion.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPostion::UWorldPostion()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPostion::BeginPlay()
{
	Super::BeginPlay();
    
	// FString Log = TEXT("Hello!");
    // FString *PrtLog = &Log;

	// Log.Len();
	// (*PrtLog).Len();
    //  PrtLog->Len();

	// UE_LOG(LogTemp,Warning,TEXT("%s"), **PrtLog);
	
	FString ObjectName = GetOwner()->GetName();
	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();
	UE_LOG(LogTemp,Warning,TEXT("%s position in world is: %s"),*ObjectName,*ObjectPosition);
	
}


// Called every frame
void UWorldPostion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

