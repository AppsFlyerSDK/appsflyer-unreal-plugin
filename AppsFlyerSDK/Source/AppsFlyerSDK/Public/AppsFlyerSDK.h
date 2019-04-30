// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

/**
 * @param CategoryName, category to declare(`LogAppsFlyerSDK`)
 * @param DefaultVerbosity, default run time verbosity(`Display)
 * @param CompileTimeVerbosity, maximum verbosity to compile into the code(`All`)
 **/
DECLARE_LOG_CATEGORY_EXTERN(LogAppsFlyerSDK, Display, All);

class FAppsFlyerSDK : public IModuleInterface
{
public:
    static inline FAppsFlyerSDK& Get()
    {
        return FModuleManager::LoadModuleChecked<FAppsFlyerSDK>("AppsFlyerSDK");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("AppsFlyerSDK");
    }

    void StartupModule();
    void ShutdownModule();
};
