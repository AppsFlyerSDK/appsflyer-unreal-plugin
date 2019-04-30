// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "AppsFlyerSDK.h"
#include "AppsFlyerSDKSettings.h"
#include "AppsFlyerSDKBlueprint.h"
// #include "Core.h"
// #include "Modules/ModuleManager.h"
// #include "Interfaces/IPluginManager.h"
// #include "UE4AppsFlyerLibrary/ExampleLibrary.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogAppsFlyerSDK);

#define LOCTEXT_NAMESPACE "AppsFlyerSDK"

// Change the macro calls to IMPLEMENT_MODULE to reference your new plugin name
IMPLEMENT_MODULE(FAppsFlyerSDK, AppsFlyerSDK)

// Startup Module
void FAppsFlyerSDK::StartupModule()
{
    // Register settings
    if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        settingsModule->RegisterSettings("Project", "Plugins", "AppsFlyer SDK",
                                         LOCTEXT("RuntimeSettingsName", "AppsFlyer SDK"),
                                         LOCTEXT("RuntimeSettingsDescription", "Configure the AppsFlyer SDK bundle(plugin)"),
                                         GetMutableDefault<UAppsFlyerSDKSettings>()
                                         );
    }

#if PLATFORM_ANDROID || PLATFORM_IOS
    UAppsFlyerSDKBlueprint::configure();
#endif
}

// Shutdown Module
void FAppsFlyerSDK::ShutdownModule()
{
}


#undef LOCTEXT_NAMESPACE
