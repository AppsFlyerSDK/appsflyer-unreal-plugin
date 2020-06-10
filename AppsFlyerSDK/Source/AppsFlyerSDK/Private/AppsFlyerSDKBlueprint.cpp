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
#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"
#elif PLATFORM_IOS
#import <AppsFlyerLib/AppsFlyerTracker.h>
#import "UE4AFSDKDelegate.h"
#include "IOSAppDelegate.h"
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
        }
        // Java map to UE4 map
        conversionData.InstallData = map;
        for (TObjectIterator<UAppsFlyerSDKCallbacks> Itr; Itr; ++Itr) {
            Itr->OnConversionDataReceived.Broadcast(conversionData);
        }
    }
    JNIEXPORT void JNICALL Java_com_appsflyer_AppsFlyer2dXConversionCallback_onInstallConversionFailureNative
    (JNIEnv *env, jobject obj, jstring stringError) {
        jboolean isCopy;
        const char *convertedValue = (env)->GetStringUTFChars(stringError, &isCopy);
        for (TObjectIterator<UAppsFlyerSDKCallbacks> Itr; Itr; ++Itr) {
            Itr->OnConversionDataRequestFailure.Broadcast(convertedValue);
        }
    }
    JNIEXPORT void JNICALL Java_com_appsflyer_AppsFlyer2dXConversionCallback_onAppOpenAttributionNative
    (JNIEnv *env, jobject obj, jobject attributionObject) {}
    JNIEXPORT void JNICALL Java_com_appsflyer_AppsFlyer2dXConversionCallback_onAttributionFailureNative
    (JNIEnv *env, jobject obj, jobject stringError) {}
}
#elif PLATFORM_IOS
@protocol AppsFlyerTrackerDelegate;

static void OnOpenURL(UIApplication *application, NSURL *url, NSString *sourceApplication, id annotation)
{
    dispatch_async(dispatch_get_main_queue(), ^ {
        [[AppsFlyerTracker sharedTracker] handleOpenURL:url sourceApplication:sourceApplication withAnnotation:annotation];
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
    for (TObjectIterator<UAppsFlyerSDKCallbacks> Itr; Itr; ++Itr) {
        Itr->OnConversionDataReceived.Broadcast(conversionData);
    }
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
    for (TObjectIterator<UAppsFlyerSDKCallbacks> Itr; Itr; ++Itr) {
        Itr->OnConversionDataReceived.Broadcast(conversionData);
    }
}
static void onAppOpenAttributionFailure(NSString *error) {
    NSLog(@"%@", error);
}
#endif
UAppsFlyerSDKBlueprint::UAppsFlyerSDKBlueprint(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer) {}

void UAppsFlyerSDKBlueprint::configure()
{
    const UAppsFlyerSDKSettings *defaultSettings = GetDefault<UAppsFlyerSDKSettings>();
    const bool isDebug = defaultSettings->bIsDebug; 
#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID appsflyer =
        FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "afStart", "(Ljava/lang/String;Z)V", false);
    jstring key = env->NewStringUTF(TCHAR_TO_UTF8(*defaultSettings->appsFlyerDevKey));

    

    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, appsflyer, key, isDebug);
#elif PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        if (!defaultSettings->appsFlyerDevKey.IsEmpty() && !defaultSettings->appleAppID.IsEmpty()) {
            [AppsFlyerTracker sharedTracker].appsFlyerDevKey = defaultSettings->appsFlyerDevKey.GetNSString();
            [AppsFlyerTracker sharedTracker].appleAppID = defaultSettings->appleAppID.GetNSString();
            [AppsFlyerTracker sharedTracker].isDebug = isDebug;
            FIOSCoreDelegates::OnOpenURL.AddStatic(&OnOpenURL);
            UE4AFSDKDelegate *delegate = [[UE4AFSDKDelegate alloc] init];
            delegate.onConversionDataSuccess = onConversionDataSuccess;
            delegate.onConversionDataFail = onConversionDataFail;
            delegate.onAppOpenAttribution = onAppOpenAttribution;
            delegate.onAppOpenAttributionFailure = onAppOpenAttributionFailure;
            [AppsFlyerTracker sharedTracker].delegate = (id<AppsFlyerTrackerDelegate>)delegate;
            UE_LOG(LogAppsFlyerSDKBlueprint, Display, TEXT("AppsFlyer: UE4 ready"));

            [[AppsFlyerTracker sharedTracker] trackAppLaunch];
            [[NSNotificationCenter defaultCenter] addObserverForName: UIApplicationWillEnterForegroundNotification
            object: nil
            queue: nil
            usingBlock: ^ (NSNotification * note) {
                UE_LOG(LogAppsFlyerSDKBlueprint, Display, TEXT("UIApplicationWillEnterForegroundNotification"));
                [[AppsFlyerTracker sharedTracker] trackAppLaunch];
            }];
        }
    });
#endif
}
void UAppsFlyerSDKBlueprint::trackAppLaunch() {
#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID trackAppLaunch = FJavaWrapper::FindMethod(env,
                               FJavaWrapper::GameActivityClassID,
                               "afTrackAppLaunch",
                               "()V", false);
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, trackAppLaunch);
#elif PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        [[AppsFlyerTracker sharedTracker] trackAppLaunch];
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
        [[AppsFlyerTracker sharedTracker] setCustomerUserID:customerUserId.GetNSString()];
    });
#endif
}
void UAppsFlyerSDKBlueprint::trackTMapEvent(FString eventName, TMap <FString, FString> values) {
#if PLATFORM_ANDROID
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID trackEvent = FJavaWrapper::FindMethod(env,
                           FJavaWrapper::GameActivityClassID,
                           "afTrackEvent",
                           "(Ljava/lang/String;Ljava/util/Map;)V", false);
    jstring jEventName = env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
    jclass mapClass = env->FindClass("java/util/HashMap");
    jmethodID mapConstructor = env->GetMethodID(mapClass, "<init>", "()V");
    jobject map = env->NewObject(mapClass, mapConstructor);
    jmethodID putMethod = env->GetMethodID(mapClass, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
    for (const TPair<FString, FString>& pair : values) {
        env->CallObjectMethod(map, putMethod, env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key)), env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value)));
    }
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, trackEvent, jEventName, map);
#elif PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^ {
        NSMutableDictionary *dictionary = [NSMutableDictionary dictionary];
        for (const TPair<FString, FString>& pair : values) {
            [dictionary setValue:pair.Value.GetNSString() forKey:pair.Key.GetNSString()];
        }
        [[AppsFlyerTracker sharedTracker] trackEvent:eventName.GetNSString() withValues:dictionary];
    });
#endif
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("trackEvent raised"));
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
    NSString *UID = [[AppsFlyerTracker sharedTracker] getAppsFlyerUID];
    FString ueUID(UID);
    return ueUID;
#else
    return FString(TEXT("Wrong platform!"));
#endif
}



