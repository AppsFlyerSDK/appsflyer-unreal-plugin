# Unreal Engine 4 AppsFlyer Plugin Guides

<img src="https://massets.appsflyer.com/wp-content/uploads/2016/06/26122512/banner-img-ziv.png"  width="200">

## Table of content

- [Init SDK](#init-sdk)
- [Track Event](#inappevent)
- [Get AppsFlyerUID](#appsflyeruid)
- [Set Custom User Id](#customid)
- [DeepLinking](#deeplinking)
    - [Deferred Deep Linking (Get Conversion Data)](#deferred-deep-linking)
    - [Direct Deeplinking](#handle-deeplinking)
    - [Android Deeplink Setup](#android-deeplink)
    - [iOS Deeplink Setup](#ios-deeplink)
- [Demo](#demo)


##  <a id="init-sdk"> Init SDK
    
<img src="./ScreenShots/ProjectSettings2.png"  width="1100">

* **dev key** - Found under App Settings in your AppsFlyer Dashboard.
* **app id** - app id from the itunes store (without the 'id' prefix)
* **is debug** - Used to dub to AppsFlyer SDK. (Development Only!)

Once this is set up the AppsFlyer SDK can track all **Installs** and **Sessions**.
    
##  <a id="inappevent"> Track Event
    
    
- In-app events help you track how loyal users discover your app, and attribute them to specific 
campaigns/media-sources. Please take the time define the event/s you want to measure to allow you 
to track ROI (Return on Investment) and LTV (Lifetime Value).
- The `trackEvent` method allows you to send in-app events to AppsFlyer analytics. This method allows you to add events dynamically by adding them directly to the application code.
    
    
<img src="./ScreenShots/TrackEvent.png"  width="1100">

For more on in-app events check out the AppsFlyer **Knowledge base** [here](https://support.appsflyer.com/hc/en-us/articles/115005544169-AppsFlyer-Rich-In-App-Events-Android-and-iOS#Introduction).

##  <a id="appsflyeruid"> Get AppsFlyerUID

To receive unique AppsFlyer ID per app installation you can use this blueprint:


<img src="./ScreenShots/GetAppFlyerUID.png" width="300">

##  <a id="customid"> Set Custom User ID
    
Setting your own Custom ID enables you to cross-reference your own unique ID with AppsFlyer’s user ID and the other devices’ IDs. This ID is available in AppsFlyer CSV reports along with postbacks APIs for cross-referencing with you internal IDs.

**IMPORTANT**: If you want to have CUID in the install record, you need to set it before SDK send out first launch. If implemented as per screenshot above it will happen before the launch is sent. For more details please check out this articles: [iOS](https://support.appsflyer.com/hc/en-us/articles/207032066-iOS-SDK-integration-for-developers#additional-apis) and [Android](https://support.appsflyer.com/hc/en-us/articles/207032126-Android-SDK-integration-for-developers#additional-apis-set-customer-user-id).

<img src="./ScreenShots/CustomUserId.png"  width="1100">


##  <a id="deeplinking"> Deep Linking
    
![alt text](https://massets.appsflyer.com/wp-content/uploads/2018/03/21101417/app-installed-Recovered.png "")


#### The 2 Deep Linking Types:
Since users may or may not have the mobile app installed, there are 2 types of deep linking:

1. _Deferred Deep Linking_ - Serving personalized content to new or former users, directly after the installation. 
2. _Direct Deep Linking_ - Directly serving personalized content to existing users, which already have the mobile app installed.

For more info please check out the [OneLink™ Deep Linking Guide](https://support.appsflyer.com/hc/en-us/articles/208874366-OneLink-Deep-Linking-Guide#Intro).

The set up for _deferred deep linking_ and _direct deeplinking_ is the same for UE4:

1. Create a new _Actor_ object.
<img src="./ScreenShots/AddNewActor.png"  width="400">

2. Click _Add Component_ and and the **AppsFlyer SDKCallback** Component.
<img src="./ScreenShots/AddComponent.png"  width="400">

3. You can now add the required callbacks.
<img src="./ScreenShots/AddMethodsGCD.png"  width="900">


Now you are ready to implement Deeplinking!

###  <a id="deferred-deep-linking"> 1. Deferred Deep Linking (Get Conversion Data)

Check out the deferred deeplinkg guide from the AppFlyer knowledge base [here](https://support.appsflyer.com/hc/en-us/articles/207032096-Accessing-AppsFlyer-Attribution-Conversion-Data-from-the-SDK-Deferred-Deeplinking-#Introduction)

Code Sample to handle the conversion data:
<img src="./ScreenShots/GCDExample.png"  width="900">





###  <a id="handle-deeplinking"> 2. Direct Deeplinking
    
When a deeplink is clicked on the device the AppsFlyer SDK will return the link in the [onAppOpenAttribution](https://support.appsflyer.com/hc/en-us/articles/208874366-OneLink-Deep-Linking-Guide#deep-linking-data-the-onappopenattribution-method-) method.

<img src="./ScreenShots/OAOAExample.png"  width="900">



###  <a id="android-deeplink"> Android Deeplink Setup
    
    
    
#### URI Scheme
In your app’s manifest add the following intent-filter to your relevant activity:
```xml 
<intent-filter>
    <action android:name="android.intent.action.VIEW" />
    <category android:name="android.intent.category.DEFAULT" />
    <category android:name="android.intent.category.BROWSABLE" />
    <data android:scheme="your unique scheme" />
</intent-filter>
```


#### App Links
For more on App Links check out the guide [here](https://support.appsflyer.com/hc/en-us/articles/115005314223-Deep-Linking-Users-with-Android-App-Links#what-are-android-app-links).


###  <a id="ios-deeplink"> iOS Deeplink Setup
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




##  <a id="demo"> Demo
    
Coming Soon!
