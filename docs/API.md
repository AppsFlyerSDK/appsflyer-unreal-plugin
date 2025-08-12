---
title: API reference
category: 5f9705393c689a065c409b23
parentDoc: 651333ca92aa30003d84d423
order: 9
hidden: true
slug: ue-api
---
## Table of contents

- [Configure](#configure)
- [Start](#start)
- [Log Event](#log-event)
- [Get AppsFlyerUID](#get-appsflyeruid)
- [WaitForAttUserAutorization (iOS only)](#waitForATTUserAuthorizationWithTimeoutInterval)
- [Set Customer User Id](#set-customer-user-id)
- [Set Consent Data](#set-consent-data)
- [Uninstall Measurement](#uninstall-measurement)
    - [iOS Uninstall](#ios-uninstall)
    - [Android Uninstall](#android-uninstall)
- [Set Additional Data](#set-additional-data)


## Configure

Perform internal setup: inject plugin & engine version, read developer keys from **Project Settings**.
See [here](docs/BasicIntegration#setup) for configuration details.

### C++

```c++
static void configure();
```


## Start

- Starts the SDK and sends the session to the server.
- By default, the `start` method is called automatically once the app is being launched.
- This setting can be disabled in the Plugin settings, to let the app developer manually control when the SDK starts. See [here](docs/BasicIntegration#automatically-starting-the-sdk) for more details.
- If the Plugin is configured for a manual start, the developer should call the `start` method under the blueprint, and configure it to be called every foreground-background transition.

### Blueprint:
<img src="https://files.readme.io/4134798fbbda92d0d6ba026f086b140b3abba27f0d827a9cf2e3fe1bf253a3dc-6-AppsFlyer-SDK-start-example.png"  width="710"/>

### C++

```c++
static void start();
```


## Log Event

The `logEvent` method allows you to send in-app events to AppsFlyer. 
For more information about defining in-app events,  see [here](https://support.appsflyer.com/hc/en-us/articles/115005544169-AppsFlyer-Rich-In-App-Events-Android-and-iOS#Introduction).

### Blueprint:

<img src="https://files.readme.io/26545c3-TrackEvent.png"  width="1100"/>

### C++

```c++
static void logEvent(FString eventName,
                     TMap<FString,FString> values);
```

-   **eventName** – canonical AppsFlyer event code, e.g. `"af_purchase"`.
    
-   **values** – key/values payload (UTF‑8).  
    Special handling: on iOS the helper converts `"af_revenue"` string to `NSNumber` so you may pass `"4.99"` without casting.


## Get AppsFlyerUID

To receive unique AppsFlyer ID per app installation you can use this blueprint:

### Blueprint

![](https://files.readme.io/4bdabe0-GetAppsFlyerUID.png)


### C++

```c++
static FString getAppsFlyerUID();
```


## waitForATTUserAuthorizationWithTimeoutInterval

iOS 14+ utility that defers `start()` until user responds to the ATT prompt or the timeout elapses. 
See more information about this API [here](https://dev.appsflyer.com/hc/docs/integrate-ios-sdk#enabling-app-tracking-transparency-att-support).

**IMPORTANT**: When using this API, please perform the following:
1.  Set the  `Automatically start the AppsFlyer SDK`  flag under the plugin setting to `false`.
2.  Call the  `Set Custom User ID`  API before the call to the  `Start`  API.


### Blueprint:

<img src="https://files.readme.io/d7ed853b30ed4d2159220fc40444e827656490cf09d00ea2c3624e319995bfd3-5-Wait-for-att-example.png" width="1100"/>


### C++

```c++
static void waitForATTUserAuthorizationWithTimeoutInterval(int timeoutSeconds);
```


## Set Customer User ID

Setting your own Custom ID enables you to cross-reference your own unique ID with AppsFlyer’s user ID and the other devices IDs. This ID is available in AppsFlyer CSV reports along with postback APIs for cross-referencing with your internal IDs.

**IMPORTANT**: To set the user ID in the first SDK session, please perform the following:
1. Set the `Automatically start the AppsFlyer SDK` flag under the plugin setting to false.
2. Call the `Set Custom User ID` API before the call to the `Start` API.

### Blueprint:

<img src="https://files.readme.io/88552e9-CustomUserId.png"  width="1100"/>

### C++

```c++
static void setCustomerUserId(FString customerUserId);
```

## Set Consent Data

As part of the EU  [Digital Marketing Act](https://commission.europa.eu/strategy-and-policy/priorities-2019-2024/europe-fit-digital-age/digital-markets-act-ensuring-fair-and-open-digital-markets_en)  (DMA) legislation, big tech companies must get consent from European end users before using personal data from third-party services for advertising.

To comply with the legislation, Google requires AppsFlyer customers to include specific consent fields when sending events originating from EU end-users to Google.

If the app collects consent information from users manually, and not via a CMP, it should use the `SetConsentData` API and pass the following parameters:

-   `isUserSubjectToGDPR`  - Indicates whether GDPR applies to the user.
-   `hasConsentForDataUsage` - Indicates whether the user has consented to use their data for advertising purposes.
-   `hasConsentForAdsPersonalization` - Indicates whether the user has consented to use their data for personalized advertising.
-   `hasConsentForAdStorage`  - indicates whether the user has consented to store or access information on a device.

These parameters can either be preset by the developer or be set as parameters based on the end user's response. 

### Blueprint:

<img src="https://files.readme.io/5ee996e24da01d8f664eefa745bee2fa9129a656d624e5040808615df91e4629-3-Set-Consent-Data.png" width="822"/>


### C++

```c++
// Option 1 - Use `ValueUnset` to omit a flag
static void SetConsentData(
    EAFBooleanState IsUserSubjectToGDPR,
    EAFBooleanState HasConsentForDataUsage,
    EAFBooleanState HasConsentForAdsPersonalization,
    EAFBooleanState HasConsentForAdStorage);

// Option 2 - C++ only
static void SetConsentDataTOptional(
    TOptional<bool> IsUserSubjectToGDPR,
    TOptional<bool> HasConsentForDataUsage,
    TOptional<bool> HasConsentForAdsPersonalization,
    TOptional<bool> HasConsentForAdStorage);
```

## Uninstall Measurement

AppsFlyer uses silent push notifications, once a day, to verify if an app is still installed on a given device. If there is no response, an uninstall is recorded, and attributed to the media source that originally brought the user.

First, please make sure to read the relevant information about the [uninstall feature in the AppsFlyer dashboard](https://support.appsflyer.com/hc/en-us/articles/210289286-Uninstall-measurement)

### iOS Uninstall

**Important!**
To support remote notifications in iOS follow the [official unreal docs](https://docs.unrealengine.com/4.27/en-US/SharingAndReleasing/Mobile/LocalNotifications). Don't forget to [download, compile, and run the Unreal Engine from the source](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/ProgrammingWithCPP/DownloadingSourceCode).

#### Blueprint: 

1. After Unreal Engine is running, open the Unreal IDE, go to Settings > Platforms -> iOS, and check **Enable Remote Notification Support**.

   <img src="https://files.readme.io/0f87999-iOSenableRemoteNotification.png" width="1100"/>

3. Under the setting -> Maps & Mods -> Game instance -> change the instance class to `PlatformGameInstance`

   <img src="https://files.readme.io/cd6e6b92cfb199645dafda15b68012e9a6ead8670b9e58553aa918c59f72712e-9-Uninstall-game-instance.png" width="1100"/>

4. Configure the nodes under the relevant blueprint:

   <img src="https://files.readme.io/4a4549b-nodeEvents.png"  width="1100"/>

   - **Register for remote notification** Will show a pop-up to the user from the OS, asking permission for remote notification
   - The application registered for remote notifications delegate** call AppsFlyer uninstall API from [iOS lifecycle](https://support.appsflyer.com/hc/en-us/articles/360017822118-Integrate-Android-uninstall-measurement-into-an-app)
   - **AppsFlyerSDK remote notification token** call AppsFlyer API for sending the token.

#### C++

```c++
static void setRemoteNotificationsToken(const TArray<uint8>& token);
```
Registers the device push‑token with AppsFlyer to enable uninstall measurement.

#### Debugging

When debugging, enable AppsFlyer debug logs and check for the Register endpoint

   <img src="https://files.readme.io/0b3a257-iOSLogs.png" width="1100"/>

### Android Uninstall

Complete the steps in the [following article](https://support.appsflyer.com/hc/en-us/articles/360017822118-Integrate-Android-uninstall-measurement-into-an-app)

1. Configure [Firebase cloud messaging](https://support.appsflyer.com/hc/en-us/articles/360017822118-Integrate-Android-uninstall-measurement-into-an-app#http-v1)
2. Follow the app integration steps in [this article](https://support.appsflyer.com/hc/en-us/articles/360017822118-Integrate-Android-uninstall-measurement-into-an-app#integrate-fcm-into-the-app).
3. Use the `appsFlyer.FirebaseMessagingServiceListener` service, embedded in the SDK. This  service extends the `FirebaseFirebaseMessagingService` class, used for receiving the FCM Device Token:

   ```xml
   <application
      <!-- ... -->
         <service
           android:name="com.appsflyer.FirebaseMessagingServiceListener">
           <intent-filter>
             <action android:name="com.google.firebase.MESSAGING_EVENT"/>
           </intent-filter>
         </service>
      <!-- ... -->
   </application>

   ```

### Blueprint: 

The same nodes as in iOS could be used for Android under the relevant blueprint. No API call is needed.

   <img src="https://files.readme.io/4a4549b-nodeEvents.png" width="1100"/>



## Set Additional Data

Add custom key-value pairs to the payload of the install event and any in-app event. The values will appear in raw-data reports.

**IMPORTANT** To include the additional data in the first SDK session, perform the following:

1. Set the **Automatically start the AppsFlyer SDK** under the plugin setting to false.
2. Call the `setAdditionalData` API before the call to the `start` API


### Blueprint:

<img src="https://files.readme.io/3ebf06f-setAdditionalData.png"  width="1100"/>

### C++

```c++
static void setAdditionalData(TMap<FString,FString> customData);
```