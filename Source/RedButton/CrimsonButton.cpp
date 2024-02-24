// Fill out your copyright notice in the Description page of Project Settings.


#include "CrimsonButton.h"

// Sets default values for this component's properties
UCrimsonButton::UCrimsonButton()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCrimsonButton::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCrimsonButton::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCrimsonButton::SetMover(UMoverComponent* TargetMover)
{
	Mover = TargetMover;
}

bool UCrimsonButton::TryActivateButton()
{
	Mover->SetShouldMove(true);
	return true;
}