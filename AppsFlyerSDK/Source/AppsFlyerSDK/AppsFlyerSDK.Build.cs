// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using System.IO;
using System;

namespace UnrealBuildTool.Rules
{
public class AppsFlyerSDK : ModuleRules
{
	public AppsFlyerSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		MinFilesUsingPrecompiledHeaderOverride = 1;

		PrivateIncludePaths.Add("AppsFlyerSDK/Private");

		PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject", "Projects" });
		PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PublicAdditionalFrameworks.Add(
			    new Framework(
			        "AppsFlyerLib",
			        "../ThirdParty/iOS/AppsFlyerLib.embeddedframework.zip"
			    )
			);

			PublicFrameworks.AddRange(
			    new string[]
			{
				"AdSupport",
				"iAd",
				"CoreTelephony",
				"Security",
				"SystemConfiguration",
				"CFNetwork"
			}
			);
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			// Unreal Plugin Language
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", System.IO.Path.Combine(PluginPath, "AppsFlyer_UPL.xml"));
			// JNI
			PublicIncludePathModuleNames.Add("Launch");
		}
	}
}
}