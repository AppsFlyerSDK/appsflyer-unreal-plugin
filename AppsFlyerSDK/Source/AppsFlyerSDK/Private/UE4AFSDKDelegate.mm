//
//  UE4AFSDKDelegate.m
//  af_ue4_example_Index
//
//  Created by AndreyG-AF on 1/31/19.
//  Copyright © 2019 Epic Games, Inc. All rights reserved.
//

#if PLATFORM_IOS
#import "UE4AFSDKDelegate.h"



@implementation UE4AFSDKDelegate

- (instancetype)init {
    self = [super init];
    if (self) {
        
    }
    return self;
}

- (void)dealloc {
    [super dealloc];
}

/**
 `installData` contains information about install.
 Organic/non-organic, etc.
 */
- (void)onConversionDataReceived:(NSDictionary *)installData {
    _onConversionDataReceived(installData);
}

/**
 Any errors that occurred during the conversion request.
 */
- (void)onConversionDataRequestFailure:(NSError *)error {
    _onConversionDataRequestFailure(error.localizedDescription);
}

/**
 `attributionData` contains information about OneLink, deeplink.
 */
- (void)onAppOpenAttribution:(NSDictionary *)attributionData {
    _onAppOpenAttribution(attributionData);
}

/**
 Any errors that occurred during the attribution request.
 */
- (void)onAppOpenAttributionFailure:(NSError *)error {
    _onAppOpenAttributionFailure(error.localizedDescription);
}

@end
#elif PLATFORM_ANDROID
    
    
    
#endif
