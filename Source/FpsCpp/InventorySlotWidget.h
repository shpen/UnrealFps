// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "PickupActor.h"
#include "InventorySlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class FPSCPP_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/*Holds a reference to the item texture*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APickupActor* mItem;

	/*Tells the player the equip the represented item from this widget*/
	UFUNCTION(BlueprintCallable, Category = UI)
	void setEquippedItem();

public:
	/*Sets the item*/
	UFUNCTION(BlueprintCallable, Category = UI)
	void setItem(APickupActor *item);

	
};
