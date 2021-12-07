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
    
	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK log event via Blueprint Map Node")
	static void logEvent(FString eventName, TMap <FString, FString> values);
    
	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK start")
	static void start();
	/*!
	 * Personalize by user identifier
	 */
	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK to set customer user id")
	static void setCustomerUserId(FString customerUserId);

	/*!
	 * This method returns AppsFlyer's internal id(unique for app install)
	 */
	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK unique id")
	static FString getAppsFlyerUID();

	/*!
	 * The object that contains the advertising identifier
	 */
	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK advertising identifier")
	static FString advertisingIdentifier();

	/*!
	 * This method set a timeout till getting user consent
	 */
	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK wait for user authorization")
	static void waitForATTUserAuthorizationWithTimeoutInterval(int timeoutInterval);


    UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "Set AppsFlyerSDK Remote Notifications Token")
    static void setRemoteNotificationsToken(const TArray<uint8>& token);


	UFUNCTION(BlueprintCallable, Category = AppsFlyerSDK, DisplayName = "AppsFlyerSDK add custom data to events in the payload")
    static void setAdditionalData(TMap <FString, FString> customData);

};
