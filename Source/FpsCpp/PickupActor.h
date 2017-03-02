// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

UCLASS()
class FPSCPP_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The Static Mesh of the pickup
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PickupSM;

	// The Texture of the item in case we want to add it in the secrets or inventory 
	UPROPERTY(EditAnywhere, Category = "PickupProperties")
	UTexture2D* PickupTexture;

	// The name of the item
	UPROPERTY(EditAnywhere, Category = "PickupProperties")
	FString ItemName;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Enables/Disables the glow effect on the pickup
	void SetGlowEffect(bool Status);

	// Returns the Texture of our Pickup
    UFUNCTION(BlueprintCallable)
	UTexture2D* GetPickupTexture() { return PickupTexture; }
	
};
