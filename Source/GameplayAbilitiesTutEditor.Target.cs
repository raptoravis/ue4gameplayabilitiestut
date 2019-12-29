// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GameplayAbilitiesTutEditorTarget : TargetRules
{
	public GameplayAbilitiesTutEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("GameplayAbilitiesTut");
	}
}
