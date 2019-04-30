// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAppsFlyerSDK_init() {}
	APPSFLYERSDK_API UFunction* Z_Construct_UDelegateFunction_AppsFlyerSDK_OnAppOpenAttribution__DelegateSignature();
	APPSFLYERSDK_API UFunction* Z_Construct_UDelegateFunction_AppsFlyerSDK_OnConversionDataReceived__DelegateSignature();
	APPSFLYERSDK_API UFunction* Z_Construct_UDelegateFunction_AppsFlyerSDK_OnAppOpenAttributionFailure__DelegateSignature();
	APPSFLYERSDK_API UFunction* Z_Construct_UDelegateFunction_AppsFlyerSDK_OnConversionDataRequestFailure__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_AppsFlyerSDK()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_AppsFlyerSDK_OnAppOpenAttribution__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_AppsFlyerSDK_OnConversionDataReceived__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_AppsFlyerSDK_OnAppOpenAttributionFailure__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_AppsFlyerSDK_OnConversionDataRequestFailure__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/AppsFlyerSDK",
				SingletonFuncArray,
				ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x8C3ABE73,
				0xEC44C79A,
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
