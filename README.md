---
title: Unreal mobile plugin
category: 6446526dddf659006c7ea807
order: 8
hidden: true
slug: unreal-plugin
---

> Link to repository
> [GitHub](https://github.com/AppsFlyerSDK/appsflyer-unreal-plugin)

<img src="https://files.readme.io/fe4e906-small-ue_logo.png"  width="400">

# Unreal AppsFlyer plugin

v6.10.1

🛠 In order for us to provide optimal support, please submit any issues to support@appsflyer.com. When submitting an issue please specify your AppsFlyer sign-up (account) email , your app ID , reproduction steps, code snippets, logs, and any additional relevant information.

## Table of contents

- [SDK versions](#plugin-built-for)
- [Installation](#installation)
- [Setup](#setup)
- [Guides & API](/docs/Guides.md)
  - [Init SDK](/docs/Guides.md#init-sdk)
  - [Start](/docs/Guides.md#start)
  - [Log Event](/docs/Guides.md#inappevent)
  - [Get AppsFlyerUID](/docs/Guides.md#appsflyeruid)
  - [Set Custom User Id](/docs/Guides.md#customid)
  - [Uninstall tracking](/docs/Guides.md#uninstall)
  - [Set Additional Data](/docs/Guides.md#setAdditionalData)
  - [DeepLinking](/docs/Guides.md#deeplinking)
- [Demo](#demo)

### <a id="plugin-built-for"> This plugin is built for</a>

- iOS AppsFlyerSDK **v6.10.1**
- Android AppsFlyerSDK **v6.9.1**

## <a id="installation">📲 Installation</a>

- In your game’s root directory, create a folder named Plugins
- Copy the AppsFlyer folder into it. You should have something like

```
  MyProject
  ├── Plugins
          └── AppsFlyerSDK
              └── AppsFlyerSDK.uplugin
```

## <a id="setup"> 🚀 Setup</a>

First open Settings > Project Setting... and locate AppsFlyer under the Plugins section.

<img src="https://files.readme.io/68c6fc7-small-ProjectSettings1.png"  width="700">

#### Set your App_ID (iOS only), Dev_Key and enable AppsFlyer to detect installations, sessions (app opens) and updates.

> This is the minimum requirement to start tracking your app installs and is already implemented in this plugin. You **MUST** modify this call and provide:  
> **AppsFlyer Dev Key** - Your application devKey provided by AppsFlyer.<br>
> **Apple App ID** - **_For iOS only._** Your iTunes Application ID.<br>
> **Is Debug** - When enabled the AppsFlyer SDK debug logs will be printed (development only!)

<img src="https://files.readme.io/5a806fc-small-ProjectSettings2.png"  width="1100">

Once your dev key and app_id is set you are ready to use AppsFlyer!

You will also need to make sure your package name is set up with an AppsFlyer dashboard.

<img src="https://files.readme.io/cb4b8dc-small-PackageName.png"  width="700">

## <a id="demo">📱 Demo</a>

Check out the demo for this project [here](https://github.com/AppsFlyerSDK/appsflyer-unreal-plugin/tree/master/Demo).
