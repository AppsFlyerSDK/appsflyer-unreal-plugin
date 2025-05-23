#include "AppsFlyerSDKBlueprint.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Engine/GameEngine.h"
#include "AppsFlyerSDKSettings.h"
// #include "EngineMinimal.h"
#include "Logging/LogMacros.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "AppsFlyerConversionData.h"
#include "AppsFlyerSDKCallbacks.h"

#include "Interfaces/IPluginManager.h"
// Core
#include "Misc/EngineVersion.h"
#include "UObject/UObjectIterator.h"


#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#elif PLATFORM_IOS
#import <AppsFlyerLib/AppsFlyerLib.h>
#import <AppsFlyerLib/AppsFlyerLib-Swift.h>
#import "IOS/UE4AFSDKDelegate.h"
#include "IOSAppDelegate.h"
#import <objc/message.h>

// SKAdNewtork request configuration workaround
typedef void (*bypassDidFinishLaunchingWithOption)(id, SEL, NSInteger);

static inline BOOL AppsFlyerIsEmptyValue(id obj) {
    return obj == nil
    || (NSNull *)obj == [NSNull null]
    || ([obj respondsToSelector:@selector(length)] && [obj length] == 0)
    || ([obj respondsToSelector:@selector(count)] && [obj count] == 0);
}

#endif
DEFINE_LOG_CATEGORY(LogAppsFlyerSDKBlueprint);

#if PLATFORM_ANDROID
extern "C" {
    JNIEXPORT void JNICALL Java_com_appsflyer_AppsFlyer2dXConversionCallback_onInstallConversionDataLoadedNative
    (JNIEnv *env, jobject obj, jobject attributionObject) {
        TMap<FString, FString> map;
        FAppsFlyerConversionData conversionData;
        // Java map to UE4 map
        jclass clsHashMap = env->GetObjectClass(attributionObject);
        jmethodID midKeySet = env->GetMethodID(clsHashMap, "keySet", "()Ljava/util/Set;");
        jobject objKeySet = env->CallObjectMethod(attributionObject, midKeySet);
        jclass clsSet = env->GetObjectClass(objKeySet);
        jmethodID midToArray = env->GetMethodID(clsSet, "toArray", "()[Ljava/lang/Object;");
        jobjectArray arrayOfKeys = (jobjectArray) env->CallObjectMethod(objKeySet, midToArray);
        int arraySize = env->GetArrayLength(arrayOfKeys);
        for (int i = 0; i < arraySize; ++i) {
            jstring objKey = (jstring) env->GetObjectArrayElement(arrayOfKeys, i);
            const char* c_string_key = env->GetStringUTFChars(objKey, 0);
            // Get method
            jmethodID midGet = env->GetMethodID(clsHashMap, "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
            
            jclass strCls = env->FindClass("java/lang/String");
            jmethodID toStrMethod = env->GetStaticMethodID(strCls, "valueOf", "(Ljava/lang/Object;)Ljava/lang/String;");
            
            jobject objValue = env->CallObjectMethod(attributionObject, midGet, objKey);
            jstring strValue = (jstring)env->CallStaticObjectMethod(strCls, toStrMethod, objValue);
            
            const char* c_string_value = env->GetStringUTFChars(strValue, 0);
            map.Add(c_string_key, c_string_value);
            (env)->ReleaseStringUTFChars(objKey, c_string_key);
            (env)->ReleaseStringUTFChars(strValue, c_string_value);
        }
        // Java map to UE4 map
        conversionData.InstallData = map;
        DECLARE_CYCLE_STAT(TEXT("FSimpleDelegateGraphTask.InstallConversionDataLoaded"), STAT_FSimpleDelegateGraphTask_InstallConversionDataLoaded, STATGROUP_TaskGraphTasks);
        FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]() {
            for (TObjectIterator<UAppsFlyerSDKCallbacks> Itr; Itr; ++Itr) {
                if (IsValid(*Itr))
                {
                    Itr->OnConversionDataReceived.Broadcast(conversionData);
                }
            }
        }), GET_STATID(STAT_FSimpleDelegateGraphTask_InstallConversionDataLoaded), nullptr, ENamedThreads::GameThread);

    }
    JNIEXPORT void JNICALL Java_com_appsflyer_AppsFlyer2dXConversionCallback_onInstallConversionFailureNative
    (JNIEnv *env, jobject obj, jstring stringError) {
        jboolean isCopy;
        const char *convertedValue = (env)->GetStringUTFChars(stringError, &isCopy);
        FString Value(UTF8_TO_TCHAR(convertedValue));

        DECLARE_CYCLE_STAT(TEXT("FSimpleDelegateGraphTask.InstallConversionFailure"), STAT_FSimpleDelegateGraphTask_InstallConversionFailure, STATGROUP_TaskGraphTasks);
        FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]() {
            for (TObjectIterator<UAppsFlyerSDKCallbacks> Itr; Itr; ++Itr) {
                if (IsValid(*Itr))
                {
                    Itr->OnConversionDataRequestFailure.Broadcast(Value);
                }
            }
        }), GET_STATID(STAT_FSimpleDelegateGraphTask_InstallConversionFailure), nullptr, ENamedThreads::GameThread);

        (env)->ReleaseStringUTFChars(stringError, convertedValue);
    }
    JNIEXPORT void JNICALL Java_com_appsflyer_AppsFlyer2dXConversionCallback_onAppOpenAttributionNative
    (JNIEnv *env, jobject obj, jobject attributionObject) {}
    JNIEXPORT void JNICALL Java_com_appsflyer_AppsFlyer2dXConversionCallback_onAttributionFailureNative
    (JNIEnv *env, jobject obj, jobject stringError) {}
}
#elif PLATFORM_IOS
@protocol AppsFlyerLibDelegate;

static void OnOpenURL(UIApplication *application, NSURL *url, NSString *sourceApplication, id annotation)
{
    dispatch_async(dispatch_get_main_queue(), ^ {
        [[AppsFlyerLib shared] handleOpenURL:url sourceApplication:sourceApplication withAnnotation:annotation];
    });
}

static void onConversionDataSuccess(NSDictionary *installData) {
    TMap<FString, FString> map;
    FAppsFlyerConversionData conversionData;
    for (NSString * key in [installData allKeys]) {
        NSString *objcValue = [NSString stringWithFormat:@"%@", [installData objectForKey:key]];
        FString ueKey(key);
        FString ueValue(objcValue);
        map.Add(*ueKey, *ueValue);
    }
    conversionData.InstallData = map;
    [FIOSAsyncTask CreateTaskWithBlock : ^ bool(void)
    {
        for (TObjectIterator<UAppsFlyerSDKCallbacks> Itr; Itr; ++Itr) {
            if (IsValid(*Itr))
            {
                Itr->OnConversionDataReceived.Broadcast(conversionData);
            }
        }
        return true;
    }];
}
static void onConversionDataFail(NSString *error) {
    NSLog(@"%@", error);
}
static void onAppOpenAttribution(NSDictionary *attributionData) {
    TMap<FString, FString> map;
    FAppsFlyerConversionData conversionData;
    for (NSString * key in [attributionData allKeys]) {
        NSString *objcValue = [NSString stringWithFormat:@"%@", [attributionData objectForKey:key]];
        FString ueKey(key);
        FString ueValue(objcValue);
        map.Add(*ueKey, *ueValue);
    }
    conversionData.InstallData = map;
    [FIOSAsyncTask CreateTaskWithBlock : ^ bool(void)
    {
        for (TObjectIterator<UAppsFlyerSDKCallbacks> Itr; Itr; ++Itr) {
            if (IsValid(*Itr))
            {
                Itr->OnConversionDataReceived.Broadcast(conversionData);
            }
        }
        return true;
    }] ;
}
static void onAppOpenAttributionFailure(NSString *error) {
    NSLog(@"%@", error);
}
#endif
UAppsFlyerSDKBlueprint::UAppsFlyerSDKBlueprint(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer) {}

void UAppsFlyerSDKBlueprint::configure()
{
    // Get Plugin VersionName
    FString VersionName = TEXT("Unknown");
    const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("AppsFlyerSDK"));
    if (Plugin.IsValid())
    {
        VersionName = Plugin->GetDescriptor().VersionName;
    }

    FString EngineVersion = FEngineVersion::Current().ToString();
    UE_LOG(LogAppsFlyerSDKBlueprint, Display, TEXT("FEngineVersion: %s"), *FString(EngineVersion));
    UE_LOG(LogAppsFlyerSDKBlueprint, Display, TEXT("AppsFlyerSDK Plugin VersionName: %s"), *FString(VersionName));

    const UAppsFlyerSDKSettings *defaultSettings = GetDefault<UAppsFlyerSDKSettings>();
    const bool isDebug = defaultSettings->bIsDebug; 
    const bool isAutoStart = defaultSettings->bEnableAutoStart; 
    const bool isTCFDataCollectionEnabled = defaultSettings->bEnableTCFDataCollection;   

#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    
    jmethodID PluginMethodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "afSetPluginInfo", "(Ljava/lang/String;Ljava/lang/String;)V", false);
    jstring jVersionName = env->NewStringUTF(TCHAR_TO_UTF8(*VersionName));
    jstring jEngineVersion = env->NewStringUTF(TCHAR_TO_UTF8(*EngineVersion));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, PluginMethodID, jVersionName, jEngineVersion);
    env->DeleteLocalRef(jVersionName);
    env->DeleteLocalRef(jEngineVersion);
    
    if (isAutoStart)
    {
        jmethodID appsflyer = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "afStart", "(Ljava/lang/String;Z)V", false);
        jstring key = env->NewStringUTF(TCHAR_TO_UTF8(*defaultSettings->appsFlyerDevKey));

        FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, appsflyer, key, isDebug);
    }

    if (isTCFDataCollectionEnabled)
    {
        jmethodID UPLMethod = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "afEnableTCFDataCollection", "(Z)V", false);
        FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, UPLMethod, true);
    }


#elif PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        if ((!defaultSettings->appsFlyerDevKeyIOS.IsEmpty() || !defaultSettings->appsFlyerDevKey.IsEmpty()) && !defaultSettings->appleAppID.IsEmpty()) {
            [AppsFlyerLib shared].disableSKAdNetwork = defaultSettings->bDisableSKAdNetwork;
            
            // Set Plugin Version
            [[AppsFlyerLib shared] setPluginInfoWith:AFSDKPluginUnreal 
                                       pluginVersion:VersionName.GetNSString() 
                                    additionalParams:@{@"engine_version":EngineVersion.GetNSString()}];

            [AppsFlyerLib shared].appsFlyerDevKey = defaultSettings->appsFlyerDevKeyIOS.IsEmpty() ?
                defaultSettings->appsFlyerDevKey.GetNSString() : defaultSettings->appsFlyerDevKeyIOS.GetNSString();
            
            [AppsFlyerLib shared].appleAppID = defaultSettings->appleAppID.GetNSString();
            [AppsFlyerLib shared].isDebug = isDebug;
            // Set currency code if value not `empty`
            NSString *currencyCode = defaultSettings->currencyCode.GetNSString();
            if (!AppsFlyerIsEmptyValue(currencyCode)) {
                [AppsFlyerLib shared].currencyCode = currencyCode;   
            }

            if (isTCFDataCollectionEnabled) {
                [[AppsFlyerLib shared] enableTCFDataCollection:YES];
            }

            FIOSCoreDelegates::OnOpenURL.AddStatic(&OnOpenURL);
            UE4AFSDKDelegate *delegate = [[UE4AFSDKDelegate alloc] init];
            delegate.onConversionDataSuccess = onConversionDataSuccess;
            delegate.onConversionDataFail = onConversionDataFail;
            delegate.onAppOpenAttribution = onAppOpenAttribution;
            delegate.onAppOpenAttributionFailure = onAppOpenAttributionFailure;
            [AppsFlyerLib shared].delegate = (id<AppsFlyerLibDelegate>)delegate;

            // SKAdNewtork request configuration workaround
            SEL SKSel = NSSelectorFromString(@"__willResolveSKRules:");
            id AppsFlyer = [AppsFlyerLib shared];
            if ([AppsFlyer respondsToSelector:SKSel]) {
                bypassDidFinishLaunchingWithOption msgSend = (bypassDidFinishLaunchingWithOption)objc_msgSend;
                msgSend(AppsFlyer, SKSel, 2);
            }

            UE_LOG(LogAppsFlyerSDKBlueprint, Display, TEXT("AppsFlyer: UE4 ready"));
            if(isAutoStart){
                [[AppsFlyerLib shared] start];
                [[NSNotificationCenter defaultCenter] addObserverForName: UIApplicationWillEnterForegroundNotification
                object: nil
                queue: nil
                usingBlock: ^ (NSNotification * note) {
                    UE_LOG(LogAppsFlyerSDKBlueprint, Display, TEXT("UIApplicationWillEnterForegroundNotification"));
                    [[AppsFlyerLib shared] start];
                }];
            }
        }
    });
#endif
}

void UAppsFlyerSDKBlueprint::start() {
    const UAppsFlyerSDKSettings *defaultSettings = GetDefault<UAppsFlyerSDKSettings>();
    const bool isDebug = defaultSettings->bIsDebug; 
#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID start =
        FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "afStart", "(Ljava/lang/String;Z)V", false);
    jstring key = env->NewStringUTF(TCHAR_TO_UTF8(*defaultSettings->appsFlyerDevKey));

    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, start, key, isDebug);
#elif PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        static id observer;
        [[AppsFlyerLib shared] start];
        if (!observer) {
            observer = [[NSNotificationCenter defaultCenter] addObserverForName:UIApplicationWillEnterForegroundNotification object:nil queue:nil usingBlock:^(NSNotification * _Nonnull note) {
                UE_LOG(LogAppsFlyerSDKBlueprint, Display, TEXT("UIApplicationWillEnterForegroundNotification"));
                [[AppsFlyerLib shared] start];
            }];
        }
    });
#endif
}
void UAppsFlyerSDKBlueprint::setCustomerUserId(FString customerUserId) {
#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID setCustomerUserId = FJavaWrapper::FindMethod(env,
                                  FJavaWrapper::GameActivityClassID,
                                  "afSetCustomerUserId",
                                  "(Ljava/lang/String;)V", false);
    jstring jCustomerUserId = env->NewStringUTF(TCHAR_TO_UTF8(*customerUserId));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, setCustomerUserId, jCustomerUserId);
#elif PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        [[AppsFlyerLib shared] setCustomerUserID:customerUserId.GetNSString()];
    });
#endif
}
void UAppsFlyerSDKBlueprint::logEvent(FString eventName, TMap <FString, FString> values) {
#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID logEvent = FJavaWrapper::FindMethod(env,
                           FJavaWrapper::GameActivityClassID,
                           "afLogEvent",
                           "(Ljava/lang/String;Ljava/util/Map;)V", false);
    jstring jEventName = env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
    jclass mapClass = env->FindClass("java/util/HashMap");
    jmethodID mapConstructor = env->GetMethodID(mapClass, "<init>", "()V");
    jobject map = env->NewObject(mapClass, mapConstructor);
    jmethodID putMethod = env->GetMethodID(mapClass, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
    for (const TPair<FString, FString>& pair : values) {
        env->CallObjectMethod(map, putMethod, env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key)), env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value)));
    }
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, logEvent, jEventName, map);
#elif PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        NSMutableDictionary *dictionary = [NSMutableDictionary dictionary];
        for (const TPair<FString, FString>& pair : values) {
            [dictionary setValue:pair.Value.GetNSString() forKey:pair.Key.GetNSString()];
        }

        // Transform `af_revenue` value to NSNumber in case if value of NSString type
        id revenueString = dictionary[@"af_revenue"];
        if (revenueString && [revenueString isKindOfClass:[NSString class]]) {
            NSLocale *locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"];
            NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
            formatter.numberStyle = NSNumberFormatterDecimalStyle;
            formatter.locale = locale;
            NSNumber *revenueNumber = [formatter numberFromString:revenueString];
            dictionary[@"af_revenue"] = revenueNumber;
        }

        [[AppsFlyerLib shared] logEvent:eventName.GetNSString() withValues:dictionary];
    });
#endif
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("logEvent raised"));
}

FString UAppsFlyerSDKBlueprint::getAppsFlyerUID() {
#if PLATFORM_ANDROID
    FString ResultStr = "Undefined";
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        jmethodID MethodId = FJavaWrapper::FindMethod(Env,
                                FJavaWrapper::GameActivityClassID,
                                "afGetAppsFlyerUID",
                                "()Ljava/lang/String;", false);
        jstring AppsFlyerUID = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, MethodId);
        const char* cAppsFlyerUID = Env->GetStringUTFChars(AppsFlyerUID, 0);

        ResultStr = FString(cAppsFlyerUID);
        Env->ReleaseStringUTFChars(AppsFlyerUID, cAppsFlyerUID);
        Env->DeleteLocalRef(AppsFlyerUID);
    }
    return ResultStr;
#elif PLATFORM_IOS
    NSString *UID = [[AppsFlyerLib shared] getAppsFlyerUID];
    FString ueUID(UID);
    return ueUID;
#else
    return FString(TEXT("Wrong platform!"));
#endif
}

FString UAppsFlyerSDKBlueprint::advertisingIdentifier() {
#if PLATFORM_ANDROID
    return FString(TEXT(""));
#elif PLATFORM_IOS
    NSString *IDFA = [[AppsFlyerLib shared] advertisingIdentifier];
    FString ueIDFA(IDFA);
    return ueIDFA;
#else
    return FString(TEXT("Wrong platform!"));
#endif
}

void UAppsFlyerSDKBlueprint::waitForATTUserAuthorizationWithTimeoutInterval(int timeoutInterval) {
#if PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        [[AppsFlyerLib shared] waitForATTUserAuthorizationWithTimeoutInterval:timeoutInterval];
    });
#endif
}
    
void UAppsFlyerSDKBlueprint::setRemoteNotificationsToken(const TArray<uint8>& token) {
#if PLATFORM_ANDROID
    return;
#elif PLATFORM_IOS
    const uint8* tokenRef = token.GetData();
    NSData *tokenData = [NSData dataWithBytes:tokenRef length:token.Num()];
    
    dispatch_async(dispatch_get_main_queue(), ^ {
        [[AppsFlyerLib shared] registerUninstall:tokenData];
    });
#else
    return;
#endif
}

void UAppsFlyerSDKBlueprint::setAdditionalData(TMap <FString, FString> customData) {

#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID setAdditionalData = FJavaWrapper::FindMethod(env,
                                    FJavaWrapper::GameActivityClassID,
                                    "afSetAdditionalData",
                                    "(Ljava/util/Map;)V", false);
    jclass mapClass = env->FindClass("java/util/HashMap");
    jmethodID mapConstructor = env->GetMethodID(mapClass, "<init>", "()V");
    jobject map = env->NewObject(mapClass, mapConstructor);
    jmethodID putMethod = env->GetMethodID(mapClass, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
    for (const TPair<FString, FString>& pair : customData) {
        env->CallObjectMethod(map, putMethod, env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key)), env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value)));
    }
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, setAdditionalData, map);
    return;
#elif PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        NSMutableDictionary *dictionary = [NSMutableDictionary dictionary];
        for (const TPair<FString, FString>& pair : customData) {
            [dictionary setValue:pair.Value.GetNSString() forKey:pair.Key.GetNSString()];
        }
        [[AppsFlyerLib shared] setAdditionalData:dictionary];
    });
#else
    return;
#endif
}

void UAppsFlyerSDKBlueprint::SetConsentForNonGDPRUser() 
{
#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID UPLMethod1 = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "afSetConsentData", "(ZZZ)V", false);
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, UPLMethod1, false, false, false);
#elif PLATFORM_IOS
    AppsFlyerConsent *consent = [[AppsFlyerConsent alloc] initWithNonGDPRUser];
    [[AppsFlyerLib shared] setConsentData:consent];
#else
    return;
#endif
}

void UAppsFlyerSDKBlueprint::SetConsentForGDPRUser(bool hasConsentForDataUsage, bool hasConsentForAdsPersonalization)
{
#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv(); 
    jmethodID UPLMethod = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "afSetConsentData", "(ZZZ)V", false);
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, UPLMethod, true, hasConsentForDataUsage, hasConsentForAdsPersonalization);
#elif PLATFORM_IOS
    AppsFlyerConsent *consent = [[AppsFlyerConsent alloc] initForGDPRUserWithHasConsentForDataUsage:hasConsentForDataUsage
                                                                    hasConsentForAdsPersonalization:hasConsentForAdsPersonalization];
    [[AppsFlyerLib shared] setConsentData:consent];
#else
    return;
#endif
}

void UAppsFlyerSDKBlueprint::SetConsentData(
    EAFBooleanState IsUserSubjectToGDPR,
    EAFBooleanState HasConsentForDataUsage,
    EAFBooleanState HasConsentForAdsPersonalization,
    EAFBooleanState HasConsentForAdStorage)
{
#if WITH_EDITOR
    auto EnumToString = [](EAFBooleanState State) -> FString
    {
        switch (State)
        {
            case EAFBooleanState::ValueTrue:  return TEXT("True");
            case EAFBooleanState::ValueFalse: return TEXT("False");
            case EAFBooleanState::ValueUnset:
            default:                          return TEXT("Unset");
        }
    };

    UE_LOG(LogAppsFlyerSDKBlueprint, Display, TEXT("SetConsentData (Editor Test): GDPR=%s, DataUsage=%s, AdsPersonalization=%s, AdStorage=%s"),
        *EnumToString(IsUserSubjectToGDPR),
        *EnumToString(HasConsentForDataUsage),
        *EnumToString(HasConsentForAdsPersonalization),
        *EnumToString(HasConsentForAdStorage));
#endif

#if PLATFORM_ANDROID
    JNIEnv* Env = FAndroidApplication::GetJavaEnv();

    jmethodID UPLMethod = FJavaWrapper::FindMethod(
        Env,
        FJavaWrapper::GameActivityClassID,
        "appsflyer_set_consent_v2",
        "(Ljava/lang/Boolean;Ljava/lang/Boolean;Ljava/lang/Boolean;Ljava/lang/Boolean;)V",
        false
    );

    if (UPLMethod == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to find method appsflyer_set_consent_v2"));
        return;
    }

    jclass BooleanClass = Env->FindClass("java/lang/Boolean");
    jmethodID BooleanConstructor = Env->GetMethodID(BooleanClass, "<init>", "(Z)V");

    auto MakeJavaBoolean = [&](EAFBooleanState State) -> jobject
    {
        switch (State)
        {
            case EAFBooleanState::ValueTrue:
                return Env->NewObject(BooleanClass, BooleanConstructor, JNI_TRUE);
            case EAFBooleanState::ValueFalse:
                return Env->NewObject(BooleanClass, BooleanConstructor, JNI_FALSE);
            case EAFBooleanState::ValueUnset:
            default:
                return nullptr;
        }
    };

    jobject Arg1 = MakeJavaBoolean(IsUserSubjectToGDPR);
    jobject Arg2 = MakeJavaBoolean(HasConsentForDataUsage);
    jobject Arg3 = MakeJavaBoolean(HasConsentForAdsPersonalization);
    jobject Arg4 = MakeJavaBoolean(HasConsentForAdStorage);

    Env->CallVoidMethod(FJavaWrapper::GameActivityThis, UPLMethod, Arg1, Arg2, Arg3, Arg4);

    if (Arg1) Env->DeleteLocalRef(Arg1);
    if (Arg2) Env->DeleteLocalRef(Arg2);
    if (Arg3) Env->DeleteLocalRef(Arg3);
    if (Arg4) Env->DeleteLocalRef(Arg4);
    Env->DeleteLocalRef(BooleanClass);
#elif PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        NSNumber *isUserSubjectToGDPR;
        if (IsUserSubjectToGDPR == EAFBooleanState::ValueUnset) {
            isUserSubjectToGDPR = nil;
        } else if (IsUserSubjectToGDPR == EAFBooleanState::ValueTrue) {
            isUserSubjectToGDPR = @1;
        } else {
            isUserSubjectToGDPR = @0;
        }

        NSNumber *hasConsentForDataUsage;
        if (HasConsentForDataUsage == EAFBooleanState::ValueUnset) {
            hasConsentForDataUsage = nil;
        } else if (HasConsentForDataUsage == EAFBooleanState::ValueTrue) {
            hasConsentForDataUsage = @1;
        } else {
            hasConsentForDataUsage = @0;
        }

        NSNumber *hasConsentForAdsPersonalization;
        if (HasConsentForAdsPersonalization == EAFBooleanState::ValueUnset) {
            hasConsentForAdsPersonalization = nil;
        } else if (HasConsentForAdsPersonalization == EAFBooleanState::ValueTrue) {
            hasConsentForAdsPersonalization = @1;
        } else {
            hasConsentForAdsPersonalization = @0;
        }

        NSNumber *hasConsentForAdStorage;
        if (HasConsentForAdStorage == EAFBooleanState::ValueUnset) {
            hasConsentForAdStorage = nil;
        } else if (HasConsentForAdStorage == EAFBooleanState::ValueTrue) {
            hasConsentForAdStorage = @1;
        } else {
            hasConsentForAdStorage = @0;
        }

        AppsFlyerConsent *consent = [[AppsFlyerConsent alloc] initWithIsUserSubjectToGDPR:isUserSubjectToGDPR
                                                                   hasConsentForDataUsage:hasConsentForDataUsage
                                                          hasConsentForAdsPersonalization:hasConsentForAdsPersonalization
                                                                   hasConsentForAdStorage:hasConsentForAdStorage];
        [[AppsFlyerLib shared] setConsentData:consent];
    });
#endif
}

void UAppsFlyerSDKBlueprint::SetConsentDataTOptional(
	TOptional<bool> IsUserSubjectToGDPR,
	TOptional<bool> HasConsentForDataUsage,
	TOptional<bool> HasConsentForAdsPersonalization,
	TOptional<bool> HasConsentForAdStorage)
{
	auto Convert = [](TOptional<bool> OptionalFlag) -> EAFBooleanState
	{
		if (!OptionalFlag.IsSet())
		{
			return EAFBooleanState::ValueUnset;
		}
		return OptionalFlag.GetValue() ? EAFBooleanState::ValueTrue : EAFBooleanState::ValueFalse;
	};

	SetConsentData(
		Convert(IsUserSubjectToGDPR),
		Convert(HasConsentForDataUsage),
		Convert(HasConsentForAdsPersonalization),
		Convert(HasConsentForAdStorage)
	);
}
