---
title: API reference
category: 5f9705393c689a065c409b23
parentDoc: 651333ca92aa30003d84d423
order: 9
hidden: true
slug: ue-api
---

## Init SDK

<img src="[https://files.readme.io/70a3db6-ProjectSettings2.png](https://files.readme.io/70a3db6-ProjectSettings2.png)"  width="650"/>


- **AppsFlyer Dev Key** - Obtain the Dev Key from the AppsFlyer Dashboard in the App Settings section.
- **Apple App ID** - Obtain the app ID from the iTunes store (without the `id` prefix)
- **Is debug** - Once this is enabled the AppsFlyer SDK can log all Installs and Sessions.
- **Currency Code (only iOS)** - Set the app currency.
- **Disable SKAdNetwork (Only iOS)** - Disable SKAdNetwork sessions.
- **Automatically start the AppsFlyer SDK** - When set to `true`, the SDK sends the session automatically (before Blueprint events). When set to `false`, it's the developer's responsibility to call the start API from the Blueprint.

## Start

- Starts the SDK by sending the session to the server.
- By default, the `start` method is called automatically once the app is being launched.
- If needed, this setting can be disabled in the Plugin settings, and the developer can call the `start` method under the blueprint. When doing so, the SDK will send a session on every background-foreground transition.
    
<img src="[https://files.readme.io/6fe8c83-autoStartOff.png](https://files.readme.io/6fe8c83-autoStartOff.png)"  width="400"/>
    

## Log Event

The `logEvent` method allows you to send in-app events to AppsFlyer. 

<img src="[https://files.readme.io/26545c3-TrackEvent.png](https://files.readme.io/26545c3-TrackEvent.png)"  width="1100"/>

For more on in-app events check out the AppsFlyer **Knowledge base** [here](https://support.appsflyer.com/hc/en-us/articles/115005544169-AppsFlyer-Rich-In-App-Events-Android-and-iOS#Introduction).

## Get AppsFlyerUID

To receive unique AppsFlyer ID per app installation you can use this blueprint:

<img src="[https://files.readme.io/4bdabe0-GetAppsFlyerUID.png](https://files.readme.io/4bdabe0-GetAppsFlyerUID.png)" width="300"/>

## Set Custom User ID

Setting your own Custom ID enables you to cross-reference your own unique ID with AppsFlyer’s user ID and the other devices’ IDs. This ID is available in AppsFlyer CSV reports along with postback APIs for cross-referencing with your internal IDs.

<img src="[https://files.readme.io/88552e9-CustomUserId.png](https://files.readme.io/88552e9-CustomUserId.png)"  width="1100"/>

**IMPORTANT**: To set the user ID in the first SDK session, please perform the following:

1. Set the `Automatically start the AppsFlyer SDK` flag under the plugin setting to false.
    
    <img src="[https://files.readme.io/6fe8c83-autoStartOff.png](https://files.readme.io/6fe8c83-autoStartOff.png)"  width="500"/>
    
2. Call the `Set Custom User ID` API before the call to the `Start` API under the Blueprint:

## Uninstall

AppsFlyer uses silent push notifications, once a day, to verify if an app is still installed on a given device. If there is no response, an uninstall is recorded, and attributed to the media source that originally brought the user.

First, make sure to read the relevant information about the [uninstall feature in the AppsFlyer dashboard](https://support.appsflyer.com/hc/en-us/articles/210289286-Uninstall-measurement)

### iOS Uninstall

**Important!**

1. To support remote notifications in iOS follow the [official unreal docs](https://docs.unrealengine.com/4.27/en-US/SharingAndReleasing/Mobile/LocalNotifications).
    
    Don't forget to [download, compile, and run the Unreal Engine from the source](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/ProgrammingWithCPP/DownloadingSourceCode).
    
    <img src="[https://files.readme.io/88552e9-CustomUserId.png](https://files.readme.io/88552e9-CustomUserId.png)" width="1100"/>
    
2. After Unreal Engine is running, open the Unreal IDE, go to settings > platforms -> iOS, and check **Enable Remote Notification Support**.
    
    <img src="[https://files.readme.io/0f87999-iOSenableRemoteNotification.png](https://files.readme.io/0f87999-iOSenableRemoteNotification.png)" width="1100"/>
    
3. Under the setting -> Maps & Mods -> Game instance -> change the instance class to `PlatformGameInstance`
    
    <img src="[https://files.readme.io/ddfa068-gameInstance](https://files.readme.io/ddfa068-gameInstance)" width="1100"/>
    
4. Configure the nodes under the relevant blueprint:
    
    <img src="[https://files.readme.io/4a4549b-nodeEvents.png](https://files.readme.io/4a4549b-nodeEvents.png)"  width="1100"/>
    
    - **Register for remote notification** Will show a pop-up to the user from the OS, asking permission for remote notification
    - The a**pplication registered for remote notifications delegate** call AppsFlyer uninstall API from [iOS lifecycle](https://support.appsflyer.com/hc/en-us/articles/360017822118-Integrate-Android-uninstall-measurement-into-an-app)
    - **AppsFlyerSDK remote notification token** call AppsFlyer API for sending the token.
5. When debugging, enable AppsFlyer debug logs and check for the Register endpoint

<img src="[https://files.readme.io/0b3a257-iOSLogs.png](https://files.readme.io/0b3a257-iOSLogs.png)"  width="1100"/>

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
    
4. The same nodes as in iOS could be used for Android under the relevant blueprint. No API call is needed.
<img src="[https://files.readme.io/4a4549b-nodeEvents.png](https://files.readme.io/4a4549b-nodeEvents.png)" width="1100"/>

## Set Additional Data

Add custom key-value pairs to the payload of any in-app event, installs included. The values will appear in raw-data reports.

<img src="[https://files.readme.io/3ebf06f-setAdditionalData.png](https://files.readme.io/3ebf06f-setAdditionalData.png)"  width="500"/>

**IMPORTANT** To include the additional data in the first SDK session, peform the following:

1. Set the **Automatically start the AppsFlyer SDK** under the plugin setting to false.
    
    <img src="[https://files.readme.io/6fe8c83-autoStartOff.png](https://files.readme.io/6fe8c83-autoStartOff.png)"  width="500"/>
    
2. Call the `setAdditionalData` API before the call to the `Start` API:
    
    <img src="[https://files.readme.io/4d9cd34-setAdditionalDataBeforeStart.png](https://files.readme.io/4d9cd34-setAdditionalDataBeforeStart.png)"  width="500"/>