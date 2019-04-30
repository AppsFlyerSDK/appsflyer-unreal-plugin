// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
#ifdef APPSFLYERSDK_AppsFlyerSDKBlueprint_generated_h
#error "AppsFlyerSDKBlueprint.generated.h already included, missing '#pragma once' in AppsFlyerSDKBlueprint.h"
#endif
#define APPSFLYERSDK_AppsFlyerSDKBlueprint_generated_h

#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execsetCustomerUserId) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_customerUserId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAppsFlyerSDKBlueprint::setCustomerUserId(Z_Param_customerUserId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(exectrackAppLaunch) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAppsFlyerSDKBlueprint::trackAppLaunch(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(exectrackTMapEvent) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_eventName); \
		P_GET_TMAP(FString,FString,Z_Param_values); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAppsFlyerSDKBlueprint::trackTMapEvent(Z_Param_eventName,Z_Param_values); \
		P_NATIVE_END; \
	}


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execsetCustomerUserId) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_customerUserId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAppsFlyerSDKBlueprint::setCustomerUserId(Z_Param_customerUserId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(exectrackAppLaunch) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAppsFlyerSDKBlueprint::trackAppLaunch(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(exectrackTMapEvent) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_eventName); \
		P_GET_TMAP(FString,FString,Z_Param_values); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAppsFlyerSDKBlueprint::trackTMapEvent(Z_Param_eventName,Z_Param_values); \
		P_NATIVE_END; \
	}


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAppsFlyerSDKBlueprint(); \
	friend struct Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics; \
public: \
	DECLARE_CLASS(UAppsFlyerSDKBlueprint, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AppsFlyerSDK"), NO_API) \
	DECLARE_SERIALIZER(UAppsFlyerSDKBlueprint)


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_INCLASS \
private: \
	static void StaticRegisterNativesUAppsFlyerSDKBlueprint(); \
	friend struct Z_Construct_UClass_UAppsFlyerSDKBlueprint_Statics; \
public: \
	DECLARE_CLASS(UAppsFlyerSDKBlueprint, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AppsFlyerSDK"), NO_API) \
	DECLARE_SERIALIZER(UAppsFlyerSDKBlueprint)


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAppsFlyerSDKBlueprint(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAppsFlyerSDKBlueprint) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAppsFlyerSDKBlueprint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAppsFlyerSDKBlueprint); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAppsFlyerSDKBlueprint(UAppsFlyerSDKBlueprint&&); \
	NO_API UAppsFlyerSDKBlueprint(const UAppsFlyerSDKBlueprint&); \
public:


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAppsFlyerSDKBlueprint(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAppsFlyerSDKBlueprint(UAppsFlyerSDKBlueprint&&); \
	NO_API UAppsFlyerSDKBlueprint(const UAppsFlyerSDKBlueprint&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAppsFlyerSDKBlueprint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAppsFlyerSDKBlueprint); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAppsFlyerSDKBlueprint)


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_PRIVATE_PROPERTY_OFFSET
#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_8_PROLOG
#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_PRIVATE_PROPERTY_OFFSET \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_RPC_WRAPPERS \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_INCLASS \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_PRIVATE_PROPERTY_OFFSET \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_INCLASS_NO_PURE_DECLS \
	AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h_10_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class AppsFlyerSDKBlueprint."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> APPSFLYERSDK_API UClass* StaticClass<class UAppsFlyerSDKBlueprint>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AndroidProject_Plugins_AppsFlyerSDK_Source_AppsFlyerSDK_Public_AppsFlyerSDKBlueprint_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
