// Copyright 2019-2020 AppsFlyer, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AppsFlyerSDKBlueprint.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAppsFlyerSDKBlueprint, Display, Display);

UCLASS()
class APPSFLYERSDK_API UAppsFlyerSDKBlueprint : public UBlueprintFunctionLibrary {
	GENERATED_UCLASS_BODY()
	/*!
	 * AppsFlyer configuration
	 */
	static void configure();
    
	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK track event via Blueprint Map Node")
	static void trackTMapEvent(FString eventName, TMap <FString, FString> values);
    
	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK track app launch")
	static void trackAppLaunch();
	/*!
	 * Personalize by user identifier
	 */
	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK to set customer user id")
	static void setCustomerUserId(FString customerUserId);
};
