// Fill out your copyright notice in the Description page of Project Settings.

#include "FpsCpp.h"
#include "InventorySlotWidget.h"

void UInventorySlotWidget::SetEquippedItem()
{
	//Empty for now
}

void UInventorySlotWidget::SetItemTexture(APickupActor* Item)
{
	//If the item is valid update the widget's texture.
	//If not, assign a null ptr to it so the widget won't broadcast wrong information to the player
	(Item) ? ItemTexture = Item->GetPickupTexture() : ItemTexture = nullptr;
}


