// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppsFlyerSDK/Public/AppsFlyerConversionData.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAppsFlyerConversionData() {}
// Cross Module References
	APPSFLYERSDK_API UScriptStruct* Z_Construct_UScriptStruct_FAppsFlyerConversionData();
	UPackage* Z_Construct_UPackage__Script_AppsFlyerSDK();
// End Cross Module References
class UScriptStruct* FAppsFlyerConversionData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern APPSFLYERSDK_API uint32 Get_Z_Construct_UScriptStruct_FAppsFlyerConversionData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAppsFlyerConversionData, Z_Construct_UPackage__Script_AppsFlyerSDK(), TEXT("AppsFlyerConversionData"), sizeof(FAppsFlyerConversionData), Get_Z_Construct_UScriptStruct_FAppsFlyerConversionData_Hash());
	}
	return Singleton;
}
template<> APPSFLYERSDK_API UScriptStruct* StaticStruct<FAppsFlyerConversionData>()
{
	return FAppsFlyerConversionData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAppsFlyerConversionData(FAppsFlyerConversionData::StaticStruct, TEXT("/Script/AppsFlyerSDK"), TEXT("AppsFlyerConversionData"), false, nullptr, nullptr);
static struct FScriptStruct_AppsFlyerSDK_StaticRegisterNativesFAppsFlyerConversionData
{
	FScriptStruct_AppsFlyerSDK_StaticRegisterNativesFAppsFlyerConversionData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AppsFlyerConversionData")),new UScriptStruct::TCppStructOps<FAppsFlyerConversionData>);
	}
} ScriptStruct_AppsFlyerSDK_StaticRegisterNativesFAppsFlyerConversionData;
	struct Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InstallData_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_InstallData;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InstallData_Key_KeyProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InstallData_ValueProp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AppsFlyerConversionData.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAppsFlyerConversionData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewProp_InstallData_MetaData[] = {
		{ "Category", "AppsFlyerSDK" },
		{ "ModuleRelativePath", "Public/AppsFlyerConversionData.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewProp_InstallData = { "InstallData", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAppsFlyerConversionData, InstallData), METADATA_PARAMS(Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewProp_InstallData_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewProp_InstallData_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewProp_InstallData_Key_KeyProp = { "InstallData_Key", nullptr, (EPropertyFlags)0x0000000000020001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewProp_InstallData_ValueProp = { "InstallData", nullptr, (EPropertyFlags)0x0000000000020001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewProp_InstallData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewProp_InstallData_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::NewProp_InstallData_ValueProp,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_AppsFlyerSDK,
		nullptr,
		&NewStructOps,
		"AppsFlyerConversionData",
		sizeof(FAppsFlyerConversionData),
		alignof(FAppsFlyerConversionData),
		Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAppsFlyerConversionData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAppsFlyerConversionData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_AppsFlyerSDK();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AppsFlyerConversionData"), sizeof(FAppsFlyerConversionData), Get_Z_Construct_UScriptStruct_FAppsFlyerConversionData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAppsFlyerConversionData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAppsFlyerConversionData_Hash() { return 381193212U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
