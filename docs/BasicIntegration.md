---
title: Integration
category: 5f9705393c689a065c409b23
parentDoc: 651333ca92aa30003d84d423
order: 2
hidden: true
slug: ue-integration
---

# Setup

First open Settings > Project Setting... and locate AppsFlyer under the Plugins section.

<img src="https://files.readme.io/bacb543-ProjectSettings1.png"  width="700"/>

## Setup parameters  

Set your App_ID (iOS only), Dev_Key and enable AppsFlyer to detect installations, sessions (app opens) and updates.  
> This is the minimum requirement to start tracking your app installs and is already implemented in this plugin. You **MUST** modify this call and provide:  
**AppsFlyer Dev Key** - Your application devKey provided by AppsFlyer.<br>
**Apple App ID**  - ***For iOS only.*** Your iTunes Application ID.<br>
**Is Debug** - When enabled the AppsFlyer SDK debug logs will be printed (development only!)

<img src="https://files.readme.io/70a3db6-ProjectSettings2.png"  width="1100"/>

Once your dev key and app_id is set you are ready to use AppsFlyer.

You will also need to make sure your package name is set up with a AppsFlyer Dashboard.

<img src="https://files.readme.io/bacb543-ProjectSettings1.png"  width="700"/>
