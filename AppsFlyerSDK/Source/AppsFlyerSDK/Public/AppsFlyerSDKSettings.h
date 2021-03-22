// Fill out your copyright notice in the Description page of Project Settings.
//
//

#pragma once

#include "AppsFlyerSDKSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UAppsFlyerSDKSettings : public UObject
{
    GENERATED_BODY()

public:
    UAppsFlyerSDKSettings(const FObjectInitializer& ObjectInitializer);

    // AppsFlyer Dev Key
    UPROPERTY(Config, EditAnywhere, Category = "AppsFlyer", meta = (DisplayName = "AppsFlyer Dev Key"))
    FString appsFlyerDevKey;
    
    // Apple App ID
    UPROPERTY(Config, EditAnywhere, Category = "AppsFlyer", meta = (DisplayName = "Apple App ID"))
    FString appleAppID;

    // runs AppsFlyer SDK in the debug mode
	UPROPERTY(Config, EditAnywhere, config, Category = "AppsFlyer")
	bool bIsDebug;

    // AppsFlyer The currency code is a 3 letter code according to ISO standards
    UPROPERTY(Config, EditAnywhere, Category = "AppsFlyer", meta = (DisplayName = "Currency Code(Only iOS)"))
    FString currencyCode;

    // Disable SKAdNetwork
    UPROPERTY(Config, EditAnywhere, config, Category = "AppsFlyer", meta = (DisplayName = "Disable SKAdNetwork(Only iOS)"))
    bool bDisableSKAdNetwork;
};
