// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "af_ue4_exampleGameMode.h"
#include "af_ue4_exampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aaf_ue4_exampleGameMode::Aaf_ue4_exampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
