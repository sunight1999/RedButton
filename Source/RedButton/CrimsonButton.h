// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoverComponent.h"

#include "CrimsonButton.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REDBUTTON_API UCrimsonButton : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCrimsonButton();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetMover(UMoverComponent* TargetMover);

	UFUNCTION(BlueprintCallable)
	void SetTunnelEffect(AActor* TargetTunnel);

	UFUNCTION(BlueprintCallable)
	void SetRoom(TArray<AActor*> TargetRoom);

	bool TryActivateButton();

private:
	UMoverComponent* Mover = nullptr;
	AActor* Tunnel = nullptr;
	TArray<AActor*> Room;
};
