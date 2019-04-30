// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppsFlyerSDK/Public/AppsFlyerSDKSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAppsFlyerSDKSettings() {}
// Cross Module References
	APPSFLYERSDK_API UClass* Z_Construct_UClass_UAppsFlyerSDKSettings_NoRegister();
	APPSFLYERSDK_API UClass* Z_Construct_UClass_UAppsFlyerSDKSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_AppsFlyerSDK();
// End Cross Module References
	void UAppsFlyerSDKSettings::StaticRegisterNativesUAppsFlyerSDKSettings()
	{
	}
	UClass* Z_Construct_UClass_UAppsFlyerSDKSettings_NoRegister()
	{
		return UAppsFlyerSDKSettings::StaticClass();
	}
	struct Z_Construct_UClass_UAppsFlyerSDKSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsDebug_MetaData[];
#endif
		static void NewProp_bIsDebug_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsDebug;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_appleAppID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_appleAppID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_appsFlyerDevKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_appsFlyerDevKey;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_AppsFlyerSDK,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AppsFlyerSDKSettings.h" },
		{ "ModuleRelativePath", "Public/AppsFlyerSDKSettings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_bIsDebug_MetaData[] = {
		{ "Category", "AppsFlyer" },
		{ "ModuleRelativePath", "Public/AppsFlyerSDKSettings.h" },
		{ "ToolTip", "runs AppsFlyer SDK in the debug mode" },
	};
#endif
	void Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_bIsDebug_SetBit(void* Obj)
	{
		((UAppsFlyerSDKSettings*)Obj)->bIsDebug = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_bIsDebug = { "bIsDebug", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UAppsFlyerSDKSettings), &Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_bIsDebug_SetBit, METADATA_PARAMS(Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_bIsDebug_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_bIsDebug_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appleAppID_MetaData[] = {
		{ "Category", "AppsFlyer" },
		{ "DisplayName", "Apple App ID" },
		{ "ModuleRelativePath", "Public/AppsFlyerSDKSettings.h" },
		{ "ToolTip", "Apple App ID" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appleAppID = { "appleAppID", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAppsFlyerSDKSettings, appleAppID), METADATA_PARAMS(Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appleAppID_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appleAppID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appsFlyerDevKey_MetaData[] = {
		{ "Category", "AppsFlyer" },
		{ "DisplayName", "AppsFlyer Dev Key" },
		{ "ModuleRelativePath", "Public/AppsFlyerSDKSettings.h" },
		{ "ToolTip", "AppsFlyer Dev Key" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appsFlyerDevKey = { "appsFlyerDevKey", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAppsFlyerSDKSettings, appsFlyerDevKey), METADATA_PARAMS(Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appsFlyerDevKey_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appsFlyerDevKey_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_bIsDebug,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appleAppID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::NewProp_appsFlyerDevKey,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAppsFlyerSDKSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::ClassParams = {
		&UAppsFlyerSDKSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::PropPointers),
		0,
		0x000000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAppsFlyerSDKSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAppsFlyerSDKSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAppsFlyerSDKSettings, 1115706919);
	template<> APPSFLYERSDK_API UClass* StaticClass<UAppsFlyerSDKSettings>()
	{
		return UAppsFlyerSDKSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAppsFlyerSDKSettings(Z_Construct_UClass_UAppsFlyerSDKSettings, &UAppsFlyerSDKSettings::StaticClass, TEXT("/Script/AppsFlyerSDK"), TEXT("UAppsFlyerSDKSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAppsFlyerSDKSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
