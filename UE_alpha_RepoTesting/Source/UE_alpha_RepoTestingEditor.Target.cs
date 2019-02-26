// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE_alpha_RepoTestingEditorTarget : TargetRules
{
	public UE_alpha_RepoTestingEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("UE_alpha_RepoTesting");
	}
}
