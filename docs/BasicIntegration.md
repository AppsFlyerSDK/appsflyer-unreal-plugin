---
title: Integration
category: 5f9705393c689a065c409b23
parentDoc: 651333ca92aa30003d84d423
order: 2
hidden: true
slug: ue-integration
---

# Setup

Follow these steps to integrate the AppsFlyer Unreal Engine plugin into your app:

1. Open **Settings** > **Project Settings...** and locate **AppsFlyer** under the **Plugins** section.

<img src="https://files.readme.io/bd168b6d3995208a72a0e3845b7e640d7cef8c6ba946c12952b73b9ca02b631a-1-Locate-AppsFlyer-SDK.png"  width="559"/>

2. Setup the plugin:
-   **AppsFlyer Dev Key** - Obtain the Devkey from the AppsFlyer Dashboard in the App Settings section.
-   **Apple App ID** - Obtain the app ID from the iTunes store (without the `id` prefix)
-   **Is debug** - Once enabled, the AppsFlyer SDK will print detailed information to the log. Please make sure this is turned off before publishing the app to production. 
-   **Currency Code (only iOS)** - Set the app currency.
-   **Disable SKAdNetwork (Only iOS)** - Disable SKAdNetwork activity in the SDK.
-   **Automatically start the AppsFlyer SDK** - When set to `true`, the SDK start() API is triggered immediately after init and the session is reported automatically (before Blueprint events). When set to `false`, it's the developer's responsibility to call the start API from the Blueprint. See [here](#automatically-starting-the-sdk) for more details. 
-   **Instruct the SDK to collect the TCF data from the device** - When set to `true`, the SDK will attempt to fetch the TCF string from the device. This should typically be set if the app is integrating a CMP and would like the SDK to collect the user’s consent information from the CMP automatically.

<img src="https://files.readme.io/168b339eda296f1c0601deca373eb3ebab02ac82c4f91dbba6156094f26fe7f2-2-Plugin-settings.png" width="869"/>


## Automatically Starting the SDK

The **Automatically start the AppsFlyer SDK** setting determines whether the AppsFlyer SDK should **automatically start sending data** when the application launches.

-   **If AutoStart is enabled (true):**
    -   The SDK’s start method is invoked as soon as the app starts
    -   On iOS, it also starts AppsFlyer tracking whenever the app returns to the foreground
-   **If isAutoStart is disabled (false):**
    -   The SDK does **not** start automatically
    -   You must manually call the SDK’s **start** method at the appropriate time in the app logic. The SDK will **not** send a session on every background-foreground transition.

#### When should this be toggled off?

- When the app needs to perform some actions before starting the AppsFlyer the SDK, the feature should be toggled off. 
- Examples: 
	- Displaying the App Tracking Transparency prompt to the user on iOS and instructing the SDK to wait with sending the install request using the `waitForATTUserAuthorizationWithTimeoutInterval` API. 
	- Collecting consent from the user and setting it into the SDK using `SetConsentData` .
	- Collecting the Customer User ID and sending it with the install request using the `setCustomerUserId` API.

