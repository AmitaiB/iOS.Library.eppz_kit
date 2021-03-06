//
//  EPPZAnalytics.h
//  eppz!kit
//
//  Created by Borbás Geri on 8/24/13.
//  Copyright (c) 2013 eppz! development, LLC.
//
//  donate! by following http://www.twitter.com/_eppz
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <Foundation/Foundation.h>

//For Google Analytics iOS SDK.
#import <CoreData/CoreData.h>
#import <AdSupport/AdSupport.h>

#import "EPPZSingletonSubclass.h"
#import "EPPZGoogleAnalyticsService.h"


//The big switch.
#define ANALYTICS_IS_ENABLED [ANALYTICS isEnabled]


#define ANALYTICS_ [EPPZAnalytics sharedAnalytics]


@interface EPPZAnalytics : EPPZSingleton

@property (nonatomic, readonly, getter=isEnabled) BOOL enabled;
@property (nonatomic, strong) NSString *UDID;

@property (nonatomic, strong) EPPZGoogleAnalyticsService *google;

+(EPPZAnalytics*)sharedAnalytics;

/*!
 
 Should be called at the top of `application:didFinishLaunchingWithOptions:`.
 Initializes engine, starts session, sets session dimensions implemented
 in subclass.
 
 */
-(void)takeOff;

/*! For subclass use */
-(void)takeOffWithPropertyList:(NSString*) propertyListName;

/*!
 
 Should be called at the bottom of  `application:didFinishLaunchingWithOptions:`.
 You probably use some kind of user object that has to be initialized at the time
 you call this method.
 
 */
-(void)setUserDimensions;

/*! To be called from `application:willEnterForeground:`. */
-(void)applicationWillEnterForeground;

/*! To be called from `application:didEnterBackground:`. */
-(void)applicationDidEnterBackground;

-(void)land;


#pragma mark - Dimensions

/*! Subclasses implements this, engine calls automatically when needed. */
-(void)registerCustomDimensions;

/*! To be used in the method implementation above. */
-(void)registerCustomDimension:(NSString*) dimension forIndex:(NSUInteger) index;

/*! Subclasses implements this, engine calls automatically when needed. */
-(void)setSessionDimensions;

/*! Subclasses implements this, engine calls automatically when needed. */
-(void)setHitDimensions;


#pragma mark - Hits (for client use)

-(void)page:(NSString*) pageName;
-(void)event:(NSString*) event;
-(void)event:(NSString*) event action:(NSString*) action;
-(void)event:(NSString*) event action:(NSString*) action label:(NSString*) label;
-(void)event:(NSString*) event action:(NSString*) action label:(NSString*) label value:(int) value;
-(void)setCustom:(NSInteger) index dimension:(NSString*) dimension;
-(void)setCustom:(NSInteger) index metric:(NSNumber*) metric;

-(void)startTimerForCategory:(NSString*) category name:(NSString*) name;
-(void)stopTimerForCategory:(NSString*) category name:(NSString*) name;
-(void)startTimerForCategory:(NSString*) category name:(NSString*) name label:(NSString*) label;
-(void)stopTimerForCategory:(NSString*) category name:(NSString*) name label:(NSString*) label;
-(void)removeEveryTimer;


@end
