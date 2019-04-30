// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAppsFlyerConversionData;
#ifdef APPSFLYERSDK_AppsFlyerSDKCallbacks_generated_h
#error "AppsFlyerSDKCallbacks.generated.h already included, missing '#pragma once' in AppsFlyerSDKCallbacks.h"
#endif
#define APPSFLYERSDK_AppsFlyerSDKCallbacks_generated_h

#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_21_DELEGATE \
struct _Script_AppsFlyerSDK_eventOnConversionDataRequestFailure_Parms \
{ \
	FString error; \
}; \
static inline void FOnConversionDataRequestFailure_DelegateWrapper(const FMulticastScriptDelegate& OnConversionDataRequestFailure, const FString& error) \
{ \
	_Script_AppsFlyerSDK_eventOnConversionDataRequestFailure_Parms Parms; \
	Parms.error=error; \
	OnConversionDataRequestFailure.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_20_DELEGATE \
struct _Script_AppsFlyerSDK_eventOnAppOpenAttributionFailure_Parms \
{ \
	FString error; \
}; \
static inline void FOnAppOpenAttributionFailure_DelegateWrapper(const FMulticastScriptDelegate& OnAppOpenAttributionFailure, const FString& error) \
{ \
	_Script_AppsFlyerSDK_eventOnAppOpenAttributionFailure_Parms Parms; \
	Parms.error=error; \
	OnAppOpenAttributionFailure.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_19_DELEGATE \
struct _Script_AppsFlyerSDK_eventOnConversionDataReceived_Parms \
{ \
	FAppsFlyerConversionData installData; \
}; \
static inline void FOnConversionDataReceived_DelegateWrapper(const FMulticastScriptDelegate& OnConversionDataReceived, FAppsFlyerConversionData const& installData) \
{ \
	_Script_AppsFlyerSDK_eventOnConversionDataReceived_Parms Parms; \
	Parms.installData=installData; \
	OnConversionDataReceived.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_18_DELEGATE \
struct _Script_AppsFlyerSDK_eventOnAppOpenAttribution_Parms \
{ \
	FString attributionData; \
}; \
static inline void FOnAppOpenAttribution_DelegateWrapper(const FMulticastScriptDelegate& OnAppOpenAttribution, const FString& attributionData) \
{ \
	_Script_AppsFlyerSDK_eventOnAppOpenAttribution_Parms Parms; \
	Parms.attributionData=attributionData; \
	OnAppOpenAttribution.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_RPC_WRAPPERS
#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_RPC_WRAPPERS_NO_PURE_DECLS
#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAppsFlyerSDKCallbacks(); \
	friend struct Z_Construct_UClass_UAppsFlyerSDKCallbacks_Statics; \
public: \
	DECLARE_CLASS(UAppsFlyerSDKCallbacks, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AppsFlyerSDK"), NO_API) \
	DECLARE_SERIALIZER(UAppsFlyerSDKCallbacks)


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_INCLASS \
private: \
	static void StaticRegisterNativesUAppsFlyerSDKCallbacks(); \
	friend struct Z_Construct_UClass_UAppsFlyerSDKCallbacks_Statics; \
public: \
	DECLARE_CLASS(UAppsFlyerSDKCallbacks, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AppsFlyerSDK"), NO_API) \
	DECLARE_SERIALIZER(UAppsFlyerSDKCallbacks)


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAppsFlyerSDKCallbacks(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAppsFlyerSDKCallbacks) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAppsFlyerSDKCallbacks); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAppsFlyerSDKCallbacks); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAppsFlyerSDKCallbacks(UAppsFlyerSDKCallbacks&&); \
	NO_API UAppsFlyerSDKCallbacks(const UAppsFlyerSDKCallbacks&); \
public:


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAppsFlyerSDKCallbacks(UAppsFlyerSDKCallbacks&&); \
	NO_API UAppsFlyerSDKCallbacks(const UAppsFlyerSDKCallbacks&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAppsFlyerSDKCallbacks); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAppsFlyerSDKCallbacks); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAppsFlyerSDKCallbacks)


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_PRIVATE_PROPERTY_OFFSET
#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_23_PROLOG
#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_PRIVATE_PROPERTY_OFFSET \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_RPC_WRAPPERS \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_INCLASS \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_PRIVATE_PROPERTY_OFFSET \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_INCLASS_NO_PURE_DECLS \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> APPSFLYERSDK_API UClass* StaticClass<class UAppsFlyerSDKCallbacks>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKCallbacks_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
