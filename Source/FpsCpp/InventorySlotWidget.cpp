// Fill out your copyright notice in the Description page of Project Settings.

#include "FpsCpp.h"
#include "InventorySlotWidget.h"
#include "FpsCppCharacter.h"

void UInventorySlotWidget::setEquippedItem()
{
    AFpsCppCharacter* Char = Cast<AFpsCppCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (Char)
    {
        Char->setEquippedItem(mItem);
    }
}

void UInventorySlotWidget::setItem(APickupActor *item)
{
	//If the item is valid update the widget's texture.
	//If not, assign a null ptr to it so the widget won't broadcast wrong information to the player
	mItem = item ? item : nullptr;
}


