// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/**
 * @param CategoryName, category to declare(`LogAppsFlyerSDK`)
 * @param DefaultVerbosity, default run time verbosity(`Display)
 * @param CompileTimeVerbosity, maximum verbosity to compile into the code(`All`)
 */
DECLARE_LOG_CATEGORY_EXTERN(LogAppsFlyerSDK, Display, All);

class FAppsFlyerSDK : public IModuleInterface
{
public:
    
    /**
     * Singleton-like access to this module's interface.  This is just for convenience!
     * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
     *
     * @return Returns singleton instance, loading the module on demand if needed
     */
    static inline FAppsFlyerSDK& Get()
    {
        return FModuleManager::LoadModuleChecked<FAppsFlyerSDK>("AppsFlyerSDK");
    }
    
    /**
     * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
     *
     * @return True if the module is loaded and ready to use
     */
    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("AppsFlyerSDK");
    }

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
