// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FpsCpp.h"
#include "FpsCppGameMode.h"
#include "FpsCppHUD.h"
#include "FpsCppCharacter.h"

AFpsCppGameMode::AFpsCppGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFpsCppHUD::StaticClass();
}
