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
		bFasterWithoutUnity = true;

		PrivateIncludePaths.Add("AppsFlyerSDK/Private");

		PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject" });
		PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

		switch (Target.Platform)
		{
		case UnrealTargetPlatform.IOS:
			PublicAdditionalFrameworks.Add(
			    new UEBuildFramework(
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
				"SystemConfiguration"
			}
			);
			break;

		case UnrealTargetPlatform.Android:
			// Unreal Plugin Language
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", System.IO.Path.Combine(PluginPath, "AppsFlyer_UPL.xml"));
			// JNI
			PublicIncludePathModuleNames.Add("Launch");
			break;
		}
	}
}
}