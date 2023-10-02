---
title: API reference
category: 5f9705393c689a065c409b23
parentDoc: 651333ca92aa30003d84d423
order: 9
hidden: true
slug: ue-api
---

## Table of content

- [Init SDK](#init-sdk)
- [Start](#start)
- [Log Event](#log-event)
- [Get AppsFlyerUID](#get-appsflyeruid)
- [Set Custom User Id](#set-custom-user-id)
- [Uninstall tracking](#uninstall)
  - [iOS Uninstall](#ios-uninstall)
  - [Android Uninstall](#android-uninstall)
- [Set Additional Data](#set-additional-data)

## Init SDK

<img src="https://files.readme.io/70a3db6-ProjectSettings2.png"  width="650"/>

- **Dev key** - Found under App Settings in your AppsFlyer Dashboard.
- **App id** - app id from the itunes store (without the 'id' prefix)
- **Is debug** - Used to dub to AppsFlyer SDK. (Development Only!). Once this is set up the AppsFlyer SDK can log all Installs and Sessions.

- **Currency Code (only iOS)** - Defines the app currency method

- **Disable SKAdNetwork(Only iOS)** - Disable SKAdNetwork sessions

- **Automatically start the AppsFlyer SDK** - When set to true, the SDK will be sending a session automatically (before Blueprint events). If set to false, it's the developer responsability to call the start API from the Blueprint.

## Start

- Starts the SDK by sending the session to the server.

- As a default, the start method is being called automatically once the app is being launch.

- If needed, this setting can be disabled in the Plugin settings, and the developer can call the start method under the blueprint. When doing so, the SDK will send a session on every background-foreground transition.
<img src="https://files.readme.io/6fe8c83-autoStartOff.png"  width="400"/>

## Log Event

- In-app events help you track how loyal users discover your app, and attribute them to specific
campaigns/media-sources. Please take the time define the event/s you want to measure to allow you
to track ROI (Return on Investment) and LTV (Lifetime Value).
- The `logEvent` method allows you to send in-app events to AppsFlyer analytics. This method allows you to add events dynamically by adding them directly to the application code.

<img src="https://files.readme.io/26545c3-TrackEvent.png"  width="1100"/>

For more on in-app events check out the AppsFlyer **Knowledge base** [here](https://support.appsflyer.com/hc/en-us/articles/115005544169-AppsFlyer-Rich-In-App-Events-Android-and-iOS#Introduction).

## Get AppsFlyerUID

To receive unique AppsFlyer ID per app installation you can use this blueprint:

<img src="https://files.readme.io/4bdabe0-GetAppsFlyerUID.png" width="300"/>

## Set Custom User ID

Setting your own Custom ID enables you to cross-reference your own unique ID with AppsFlyer’s user ID and the other devices’ IDs. This ID is available in AppsFlyer CSV reports along with postbacks APIs for cross-referencing with you internal IDs.

<img src="https://files.readme.io/88552e9-CustomUserId.png"  width="1100"/>

**IMPORTANT**: In order for the user ID to be define in the first SDK session, please follow these steps:

1. Set the `Automatically start the AppsFlyer SDK` flag under the plugin setting to false.
<img src="https://files.readme.io/6fe8c83-autoStartOff.png"  width="500"/>

2. Call the `Set Custom User ID` API before the call to the `Start` API under the Blueprint:

## Uninstall

AppsFlyer uses silent push notifications, once a day, to verify if an app is still installed on a given device. If there is no response, an uninstall is recorded, and it's attributed to the media source that originally brought the user.

First, make sure to read the relevant information regarding [uninstall feature in the AppsFlyer dashboard](https://support.appsflyer.com/hc/en-us/articles/210289286-Uninstall-measurement)

### iOS Uninstall

**Important!**

1. To support remote notification in IOS follow the [official unreal docs](https://docs.unrealengine.com/4.27/en-US/SharingAndReleasing/Mobile/LocalNotifications).

Don't forget to [download, compile and run Unreal Engine from the source](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/ProgrammingWithCPP/DownloadingSourceCode) .
<img src="https://files.readme.io/88552e9-CustomUserId.png" width="1100"/>

2. After the Unreal engine is running, open the Unreal IDE and go to settings > platforms -> iOS -> enable the remote notification support checkbox.
<img src="https://files.readme.io/0f87999-iOSenableRemoteNotification.png" width="1100"/>

3. Under the setting -> Maps & Mods -> Game instance -> change the instance class to PlatformGameInstance
<img src="https://files.readme.io/ddfa068-gameInstance" width="1100"/>

4. Configure the nodes under the relevant blueprint:
<img src="https://files.readme.io/4a4549b-nodeEvents.png"  width="1100"/>

- **Register for remote notification** Will show a pop-up to the user from the OS, asking permission for remote notification

- **Application registered for remote notifications delegate** call AppsFlyer uninstall API from [iOS lifecycle](https://support.appsflyer.com/hc/en-us/articles/360017822118-Integrate-Android-uninstall-measurement-into-an-app)

- **AppsFlyerSDK remote notification token**  call AppsFlyer API for sending the token.

5. To debug enable AppsFlyer debug logs and check for the Register endpoint

<img src="https://files.readme.io/0b3a257-iOSLogs.png"  width="1100"/>

### Android Uninstall

For Android make sure to complete the steps in the [following article](https://support.appsflyer.com/hc/en-us/articles/360017822118-Integrate-Android-uninstall-measurement-into-an-app)

1. Configure [Firebase cloud messaging](https://support.appsflyer.com/hc/en-us/articles/360017822118-Integrate-Android-uninstall-measurement-into-an-app#http-v1)

2. Follow the steps to [integrate into the app](https://support.appsflyer.com/hc/en-us/articles/360017822118-Integrate-Android-uninstall-measurement-into-an-app#integrate-fcm-into-the-app)

3. Make sure to use appsFlyer.FirebaseMessagingServiceListener service, embedded in the SDK. This extends the FirebaseFirebaseMessagingService class, used to receive the FCM Device Token:

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

4. Same nodes could be used (as in iOS) for Android under the relevant blueprint (no API call needed).
<img src="https://files.readme.io/4a4549b-nodeEvents.png"  width="1100"/>

## Set Additional Data

Use to add custom key-value pairs to the payload of each event, including installs. These values will appear in raw-data reports.

<img src="https://files.readme.io/3ebf06f-setAdditionalData.png"  width="500"/>

**IMPORTANT** In order for the additional data to be included in the first SDK session, please follow these steps:

1. Set the `Automatically start the AppsFlyer SDK` under the plugin setting to false.
<img src="https://files.readme.io/6fe8c83-autoStartOff.png"  width="500"/>

2. Call the `setAdditionalData` API before the call to the `Start` API:
<img src="https://files.readme.io/4d9cd34-setAdditionalDataBeforeStart.png"  width="500"/>
