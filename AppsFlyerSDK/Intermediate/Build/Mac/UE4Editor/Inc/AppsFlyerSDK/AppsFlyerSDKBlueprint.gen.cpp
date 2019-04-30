// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppsFlyerSDK/Public/AppsFlyerSDKBlueprint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAppsFlyerSDKBlueprint() {}
// Cross Module References
	APPSFLYERSDK_API UClass* Z_Construct_UClass_UAppsFlyerSDKBlueprint_NoRegister();
	APPSFLYERSDK_API UClass* Z_Construct_UClass_UAppsFlyerSDKBlueprint();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AppsFlyerSDK();
	APPSFLYERSDK_API UFunction* Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId();
	APPSFLYERSDK_API UFunction* Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackAppLaunch();
	APPSFLYERSDK_API UFunction* Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent();
// End Cross Module References
	void UAppsFlyerSDKBlueprint::StaticRegisterNativesUAppsFlyerSDKBlueprint()
	{
		UClass* Class = UAppsFlyerSDKBlueprint::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "setCustomerUserId", &UAppsFlyerSDKBlueprint::execsetCustomerUserId },
			{ "trackAppLaunch", &UAppsFlyerSDKBlueprint::exectrackAppLaunch },
			{ "trackTMapEvent", &UAppsFlyerSDKBlueprint::exectrackTMapEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics
	{
		struct AppsFlyerSDKBlueprint_eventsetCustomerUserId_Parms
		{
			FString customerUserId;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_customerUserId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::NewProp_customerUserId = { "customerUserId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AppsFlyerSDKBlueprint_eventsetCustomerUserId_Parms, customerUserId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::NewProp_customerUserId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::Function_MetaDataParams[] = {
		{ "Category", "AppsFlyerSDK" },
		{ "DisplayName", "AppsFlyerSDK to set customer user id" },
		{ "ModuleRelativePath", "Public/AppsFlyerSDKBlueprint.h" },
		{ "ToolTip", "!\n        * Personalize by user identifier" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAppsFlyerSDKBlueprint, nullptr, "setCustomerUserId", sizeof(AppsFlyerSDKBlueprint_eventsetCustomerUserId_Parms), Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackAppLaunch_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackAppLaunch_Statics::Function_MetaDataParams[] = {
		{ "Category", "AppsFlyerSDK" },
		{ "DisplayName", "AppsFlyerSDK track app launch" },
		{ "ModuleRelativePath", "Public/AppsFlyerSDKBlueprint.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackAppLaunch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAppsFlyerSDKBlueprint, nullptr, "trackAppLaunch", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackAppLaunch_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackAppLaunch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackAppLaunch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackAppLaunch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics
	{
		struct AppsFlyerSDKBlueprint_eventtrackTMapEvent_Parms
		{
			FString eventName;
			TMap<FString,FString> values;
		};
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_values;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_values_Key_KeyProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_values_ValueProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_eventName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::NewProp_values = { "values", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AppsFlyerSDKBlueprint_eventtrackTMapEvent_Parms, values), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::NewProp_values_Key_KeyProp = { "values_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::NewProp_values_ValueProp = { "values", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::NewProp_eventName = { "eventName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AppsFlyerSDKBlueprint_eventtrackTMapEvent_Parms, eventName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::NewProp_values,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::NewProp_values_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::NewProp_values_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::NewProp_eventName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "AppsFlyerSDK" },
		{ "DisplayName", "AppsFlyerSDK track event via Blueprint Map Node" },
		{ "ModuleRelativePath", "Public/AppsFlyerSDKBlueprint.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAppsFlyerSDKBlueprint, nullptr, "trackTMapEvent", sizeof(AppsFlyerSDKBlueprint_eventtrackTMapEvent_Parms), Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAppsFlyerSDKBlueprint_NoRegister()
	{
		return UAppsFlyerSDKBlueprint::StaticClass();
	}
	struct Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AppsFlyerSDK,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAppsFlyerSDKBlueprint_setCustomerUserId, "setCustomerUserId" }, // 212592862
		{ &Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackAppLaunch, "trackAppLaunch" }, // 3409583818
		{ &Z_Construct_UFunction_UAppsFlyerSDKBlueprint_trackTMapEvent, "trackTMapEvent" }, // 3597501851
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AppsFlyerSDKBlueprint.h" },
		{ "ModuleRelativePath", "Public/AppsFlyerSDKBlueprint.h" },
		{ "ToolTip", "DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam\nDECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAppOpenAttributionDelegate, TMap<FString, FString>&, attributionData);" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAppsFlyerSDKBlueprint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics::ClassParams = {
		&UAppsFlyerSDKBlueprint::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAppsFlyerSDKBlueprint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAppsFlyerSDKBlueprint, 3308123163);
	template<> APPSFLYERSDK_API UClass* StaticClass<UAppsFlyerSDKBlueprint>()
	{
		return UAppsFlyerSDKBlueprint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAppsFlyerSDKBlueprint(Z_Construct_UClass_UAppsFlyerSDKBlueprint, &UAppsFlyerSDKBlueprint::StaticClass, TEXT("/Script/AppsFlyerSDK"), TEXT("UAppsFlyerSDKBlueprint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAppsFlyerSDKBlueprint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
