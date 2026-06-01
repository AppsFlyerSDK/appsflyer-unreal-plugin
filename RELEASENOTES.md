# Release Notes

### 6.18.0
Release date **May 20, 2026**
Release type: **Minor**

**Overview and Highlights:**

- **Version Update**: Updated iOS framework to v6.18.0, Android framework to v6.18.0
- **Plugin Update**: Updated plugin to version 6.18.0 to match iOS framework version

### 6.17.9
Release date **May 20, 2026**
Release type: **Minor**

**Overview and Highlights:**

- **New API**: Added `logAdRevenue` method for logging ad revenue from mediation networks (Android and iOS)

**New APIs:**
- `logAdRevenue()` - Logs ad revenue events with mediation network, monetization network, currency, and revenue amount. Supports 14 mediation networks (GoogleAdMob, IronSource, ApplovinMax, Fyber, Appodeal, Admost, Topon, Tradplus, Yandex, ChartBoost, Unity, ToponPte, Custom, DirectMonetization)

### 6.17.8
Release date **January 7, 2026**
Release type: **Minor**

**Overview and Highlights:**

- **Version Update**: Updated iOS framework to v6.17.8, Android framework to v6.17.5
- **Plugin Update**: Updated plugin to version 6.17.8 to match iOS framework version
- **New API**: Added `ValidateAndLogInAppPurchase` method for validating and logging in-app purchases using the VAL V2 flow (iOS only)

**New APIs:**
- `ValidateAndLogInAppPurchase()` - Validates and logs in-app purchases using the updated VAL V2 flow (iOS only)

### 6.17.7
Release date **October 22, 2025**
Release type: **Minor**

**Overview and Highlights:**

- **Version Update**: Updated iOS framework to v6.17.7
- **Plugin Update**: Updated plugin to version 6.17.7 to match iOS framework version

### 6.17.5
Release date **September 4, 2025**
Release type: **Minor**

**Overview and Highlights:**

- **Version Update**: Updated SDK version on Android to v6.17.3 and iOS to v6.17.5
- **New Android API**: Added `disableAppSetId()` method to disable AppSetId collection on Android platforms

**New APIs:**
- `disableAppSetId()` - Disables AppSetId collection on Android (Android only)

### 1.0.0
Release date **May 2019**
Release type: **Major** / Minor / Hotfix

**Overview and Highlights:**

- Plugin Created!

- API
  * void afStart(String key, boolean isDebug)
  * void afSetCustomerUserId(String id)
  * void void afLogEvent(String eventName, Map<String, Object> eventValues)
  
- Android SDK to v6.4.3

- iOS SDK to v6.4.4

