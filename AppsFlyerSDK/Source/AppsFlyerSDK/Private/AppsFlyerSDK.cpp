// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "AppsFlyerSDK.h"
#include "AppsFlyerSDKSettings.h"
#include "AppsFlyerSDKBlueprint.h"

#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogAppsFlyerSDK);

// Define the namespace to use with LOCTEXT
#define LOCTEXT_NAMESPACE "AppsFlyerSDK"

/**
 * Module implementation boilerplate for regular modules.
 *
 * This macro is used to expose a module's main class to the rest of the engine.
 * You must use this macro in one of your modules C++ modules, in order for the 'InitializeModule'
 * function to be declared in such a way that the engine can find it. Also, this macro will handle
 * the case where a module is statically linked with the engine instead of dynamically loaded.
 *
 * This macro is intended for modules that do NOT contain gameplay code.
 * If your module does contain game classes, use IMPLEMENT_GAME_MODULE instead.
 *
 * Usage:   IMPLEMENT_MODULE(<My Module Class>, <Module name string>)
 */
IMPLEMENT_MODULE(FAppsFlyerSDK, AppsFlyerSDK)

void FAppsFlyerSDK::StartupModule()
{
    // Register settings: `Settings -> Project Settings -> Plugins -> AppsFlyer SDK`
    if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        settingsModule->RegisterSettings("Project", "Plugins", "AppsFlyer SDK",
                                 LOCTEXT("RuntimeSettingsName", "AppsFlyer SDK"),
                                 LOCTEXT("RuntimeSettingsDescription", "Configure bundle(plugin)"),
                        GetMutableDefault<UAppsFlyerSDKSettings>());
        UE_LOG(LogAppsFlyerSDK, Display, TEXT("[StartupModule][RegisterSettings] Done"));
    }

#if PLATFORM_ANDROID || PLATFORM_IOS
    UAppsFlyerSDKBlueprint::configure();
#endif
}

void FAppsFlyerSDK::ShutdownModule()
{
    UE_LOG(LogAppsFlyerSDK, Warning, TEXT("AppsFlyerSDK stopped"));
}

#undef LOCTEXT_NAMESPACE
