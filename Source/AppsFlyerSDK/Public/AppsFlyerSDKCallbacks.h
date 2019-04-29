//
//  AppsFlyerSDKCallback.hpp
//  af_ue4_example_Index
//
//  Created by AndreyG-AF on 1/31/19.
//  Copyright © 2019 Epic Games, Inc. All rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "AppsFlyerConversionData.h"

#include "AppsFlyerSDKCallbacks.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAppOpenAttribution, const FString&, attributionData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConversionDataReceived, const FAppsFlyerConversionData&, installData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAppOpenAttributionFailure, const FString&, error);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConversionDataRequestFailure, const FString&, error);

UCLASS(ClassGroup=(AppsFlyerSDK), meta=(BlueprintSpawnableComponent))
class APPSFLYERSDK_API UAppsFlyerSDKCallbacks : public UActorComponent
{
    GENERATED_BODY()
    
public:
    
    UAppsFlyerSDKCallbacks(const FObjectInitializer& ObjectInitializer);
    
    /**
     `installData` contains information about install. Organic/non-organic, etc.
     - (void)onConversionDataReceived:(NSDictionary *)installData;
    
     Any errors that occurred during the conversion request.
     - (void)onConversionDataRequestFailure:(NSError *)error;
    
     `attributionData` contains information about OneLink, deeplink.
     - (void)onAppOpenAttribution:(NSDictionary *)attributionData;
    
     Any errors that occurred during the attribution request.
     - (void)onAppOpenAttributionFailure:(NSError *)error;
     */
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AppsFlyerSDK")
    FOnAppOpenAttribution OnAppOpenAttribution;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AppsFlyerSDK")
    FOnConversionDataReceived OnConversionDataReceived;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AppsFlyerSDK")
    FOnAppOpenAttributionFailure OnAppOpenAttributionFailure;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "AppsFlyerSDK")
    FOnConversionDataRequestFailure OnConversionDataRequestFailure;
    
};
