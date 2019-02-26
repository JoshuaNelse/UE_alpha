// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "UE_alpha_RepoTestingGameMode.h"
#include "UE_alpha_RepoTestingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_alpha_RepoTestingGameMode::AUE_alpha_RepoTestingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
