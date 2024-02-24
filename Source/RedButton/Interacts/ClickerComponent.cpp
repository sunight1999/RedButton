// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickerComponent.h"
#include "../CrimsonButton.h"

// Sets default values for this component's properties
UClickerComponent::UClickerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UClickerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UClickerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UClickerComponent::Click()
{
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxClickDistance;
	FCollisionShape CollisionSphere = FCollisionShape::MakeSphere(ClickRadius);

	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start, End,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		CollisionSphere
	);

	if (HasHit)
	{
		AActor* HitActor = HitResult.GetActor();
		if (!HitActor->ActorHasTag("CrimsonButton"))
			return;

		UCrimsonButton* CrimsonButton = HitActor->GetComponentByClass<UCrimsonButton>();
		if (!CrimsonButton)
			return;

		if (CrimsonButton->TryActivateButton())
		{
			UE_LOG(LogTemp, Display, TEXT("SUCCESS"));
		}
	}
}