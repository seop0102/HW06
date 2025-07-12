// Copyright Epic Games, Inc. All Rights Reserved.

#include "HW06GameMode.h"
#include "HW06Character.h"
#include "UObject/ConstructorHelpers.h"

AHW06GameMode::AHW06GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
