// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Reswap.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UReswap : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReswap();

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate1 = nullptr;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
        
	    
        FVector startLoc = FVector(440.0f,0.0001f,66.99f);
        
		// UPROPERTY(EditAnywhere)
		// AActor* ActorR = nullptr;
    
};
