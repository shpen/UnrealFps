// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "FpsCppHUD.generated.h"

UCLASS()
class AFpsCppHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFpsCppHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

