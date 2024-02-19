// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RedButton : ModuleRules
{
	public RedButton(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
