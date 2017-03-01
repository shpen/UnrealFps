// Fill out your copyright notice in the Description page of Project Settings.

#include "FpsCpp.h"
#include "MyPlayerController.h"
#include "FpsCppCharacter.h"

void AMyPlayerController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	if (InventoryWidgetBP)
	{
		//Create the Inventory Widget based on the Blueprint reference we will input from within the Editor
		InventoryWidgetRef = CreateWidget<UInventoryWidget>(this, InventoryWidgetBP);

	}

	//Initial value
	bIsInventoryOpen = false;
}

void AMyPlayerController::HandleInventoryInput()
{
	AFpsCppCharacter* Char = Cast<AFpsCppCharacter>(GetPawn());
	if (InventoryWidgetRef)
	{
		if (bIsInventoryOpen)
		{
			//Mark the inventory as closed
			bIsInventoryOpen = false;

			//Remove it from the viewport
			InventoryWidgetRef->RemoveFromViewport();
		}
		else
		{
			//Mark the inventory as open
			bIsInventoryOpen = true;

			//Re-populate the ItemsArray
			InventoryWidgetRef->ItemsArray = Char->Inventory;

			//Show the inventory
			InventoryWidgetRef->Show();
		}

	}
}


