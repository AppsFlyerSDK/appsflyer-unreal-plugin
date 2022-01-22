// Fill out your copyright notice in the Description page of Project Settings.
//
//

#include "AppsFlyerSDKSettings.h"

UAppsFlyerSDKSettings::UAppsFlyerSDKSettings(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , appsFlyerDevKey("")
    , appsFlyerDevKeyIOS("")
    , appleAppID("")
    , bIsDebug(false)
    , currencyCode("")
    , bDisableSKAdNetwork(false)
    , bEnableAutoStart(true)
{
}
