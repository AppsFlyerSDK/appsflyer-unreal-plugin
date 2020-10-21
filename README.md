<img src="https://www.appsflyer.com/wp-content/uploads/2016/11/logo-1.svg"  width="400">

# Unreal AppsFlyer Plugin

v6.0.50

🛠 In order for us to provide optimal support, we would kindly ask you to submit any issues to support@appsflyer.com

*When submitting an issue please specify your AppsFlyer sign-up (account) email , your app ID , reproduction steps, code snippets, logs, and any additional relevant information.*

## Table of content

- [SDK versions](#plugin-build-for)
- [Installation](#installation)
- [Guides](#guides)
- [Setup](#setup)
- [API](#api) 
- [Demo](#demo)  


### <a id="plugin-build-for"> This plugin is built for

- iOS AppsFlyerSDK **v6.0.5**
- Android AppsFlyerSDK **v5.4.5**


## <a id="installation">📲Installation

* In your game’s root directory, create a folder named Plugins
* Copy the AppsFlyer folder into it. You should have something like
```
  MyProject
  ├── Plugins
          └── AppsFlyerSDK
              └── AppsFlyerSDK.uplugin
```


## <a id="guides"> 📖 Guides

Great guides on how to use the plugin can be viewed [here](/docs/Guides.md).
- [Track In-App Event](/docs/Guides.md#inappevent)
- [Set a Custom User Id](/docs/Guides.md#customid)
- [Deeplinking](/docs/Guides.md#deeplinking)


## <a id="setup"> 🚀 Setup

First open Settings > Project Setting... and locate AppsFlyer under the Plugins section.

<img src="/docs/ScreenShots/ProjectSettings1.png"  width="700">


####  Set your App_ID (iOS only), Dev_Key and enable AppsFlyer to detect installations, sessions (app opens) and updates.  
> This is the minimum requirement to start tracking your app installs and is already implemented in this plugin. You **MUST** modify this call and provide:  
**AppsFlyer Dev Key** - Your application devKey provided by AppsFlyer.<br>
**Apple App ID**  - ***For iOS only.*** Your iTunes Application ID.<br>
**Is Debug** - When enabled the AppsFlyer SDK debug logs will be printed (development only!)

<img src="/docs/ScreenShots/ProjectSettings2.png"  width="1100">

Once your dev key and app_id is set you are ready to use AppsFlyer! 

You will also need to make sure your package name is set up with a AppsFlyer Dashboard.

<img src="/docs/ScreenShots/PackageName.png"  width="700">

## <a id="api"> 📑 API

See the full [API](/docs/API.md) available for this plugin.


## <a id="demo"> 📱 Demo

Check out the demo for this project [here](docs/Guides.md#demo).
