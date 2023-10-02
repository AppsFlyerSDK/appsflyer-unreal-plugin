---
title: Deep Linking
category: 5f9705393c689a065c409b23
parentDoc: 651333ca92aa30003d84d423
order: 3
hidden: true
slug: ue-deep-linking
---

## Deep Linking

![alt text](https://massets.appsflyer.com/wp-content/uploads/2018/03/21101417/app-installed-Recovered.png "")

## Deep Linking Types

Since users may or may not have the mobile app installed, there are 2 types of deep linking:

1. _Deferred Deep Linking_ - Serving personalized content to new or former users, directly after the installation. 
2. _Direct Deep Linking_ - Directly serving personalized content to existing users, which already have the mobile app installed.

For more info please check out the [OneLink™ Deep Linking Guide](https://support.appsflyer.com/hc/en-us/articles/208874366-OneLink-Deep-Linking-Guide#Intro).

The set up for _deferred deep linking_ and _direct deeplinking_ is the same for UE4:

1. Create a new _Actor_ object.
<img src="https://files.readme.io/83370fb-AddNewActor.png"  width="400"/>

2. Click _Add Component_ and and the **AppsFlyer SDKCallback** Component.
<img src="https://files.readme.io/698d455-AddComponent.png"  width="400"/>

3. You can now add the required callbacks.
<img src="https://files.readme.io/e0f07bc-AddMethodsGCD.png"  width="900"/>

Now you are ready to implement Deeplinking!

### Deferred Deep Linking

Check out the deferred deeplinkg guide from the AppFlyer knowledge base [here](https://support.appsflyer.com/hc/en-us/articles/207032096-Accessing-AppsFlyer-Attribution-Conversion-Data-from-the-SDK-Deferred-Deeplinking-#Introduction)

Code Sample to handle the conversion data:
<img src="https://files.readme.io/59611f1-GCDExample.png"  width="900"/>

### Direct Deeplinking

When a deeplink is clicked on the device the AppsFlyer SDK will return the link in the [onAppOpenAttribution](https://support.appsflyer.com/hc/en-us/articles/208874366-OneLink-Deep-Linking-Guide#deep-linking-data-the-onappopenattribution-method-) method.

<img src="https://files.readme.io/28f1512-OAOAExample.png"  width="900"/>

## Android Deeplink Setup

### URI Scheme

In your app’s manifest add the following intent-filter to your relevant activity:

```xml
<intent-filter>
    <action android:name="android.intent.action.VIEW" />
    <category android:name="android.intent.category.DEFAULT" />
    <category android:name="android.intent.category.BROWSABLE" />
    <data android:scheme="your unique scheme" />
</intent-filter>
```

### App Links

For more on App Links check out the guide [here](https://support.appsflyer.com/hc/en-us/articles/115005314223-Deep-Linking-Users-with-Android-App-Links#what-are-android-app-links).

## iOS Deeplink Setup

For more on Universal Links check out the guide [here](https://support.appsflyer.com/hc/en-us/articles/208874366-OneLink-Deep-Linking-Guide#setups-universal-links).

Essentially, the Universal Links method links between an iOS mobile app and an associate website/domain, such as AppsFlyer’s OneLink domain (xxx.onelink.me). To do so, it is required to:

1. Configure OneLink sub-domain and link to mobile app (by hosting the ‘apple-app-site-association’ file - AppsFlyer takes care of this part in the onelink setup on your dashboard)
2. Configure the mobile app to register approved domains:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
    <dict>
        <key>com.apple.developer.associated-domains</key>
        <array>
            <string>applinks:test.onelink.me</string>
        </array>
    </dict>
</plist>
```
