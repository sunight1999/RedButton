// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoverComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REDBUTTON_API UMoverComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoverComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetShouldMove(bool bMove);

private:
	UPROPERTY(EditAnywhere)
	FVector MoveOffset = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
	float MoveTime = 3;
	
	FVector OriginLocation;

	UPROPERTY(EditAnywhere)
	bool bShouldMove = false;
};
