//
//  UE4AFSDKDelegate.h
//  af_ue4_example_Index
//
//  Created by AndreyG-AF on 1/31/19.
//  Copyright © 2019 Epic Games, Inc. All rights reserved.
//

#ifndef PLATFORM_IOS 
#else
#if PLATFORM_IOS

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UE4AFSDKDelegate : NSObject

@property (nonatomic) void (*onConversionDataReceived)(NSDictionary *installData);
@property (nonatomic) void (*onAppOpenAttribution)(NSDictionary *attributionData);
@property (nonatomic) void (*onConversionDataRequestFailure)(NSString *error);
@property (nonatomic) void (*onAppOpenAttributionFailure)(NSString *error);

@end

NS_ASSUME_NONNULL_END

#endif
#endif