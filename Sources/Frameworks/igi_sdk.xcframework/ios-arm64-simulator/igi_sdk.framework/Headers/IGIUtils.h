//
//  IGIUtils.h
//  iGotIt
//
//  Created by Ten5Studio on 27/09/2014.
//  Copyright (c) 2014 Ten5 Studios. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface IGIUtils : NSObject

+ (nonnull NSString *)sdkVersion;

+ (void)showAlertWithTitle:(nullable NSString *)title
                   message:(nullable NSString *)message
                     owner:(nullable UIViewController *)owner;
+ (nonnull NSDate *)dateFromTimeInterval:(long)timeInterval;
+ (nullable NSDate *)dateFromString:(nonnull NSString *)dateString;
+ (nonnull NSString *)stringFromDateForEventLive:(nonnull NSDate *)date;
+ (nonnull NSString *)stringFromDateForProfile:(nonnull NSDate *)date;
+ (nonnull NSString *)hourAndMinutesStringFromInterval:(NSTimeInterval)interval;
+ (nullable NSString *)saveImageDataAndGetFilepath:(nullable NSData *)imageData;
+ (nullable NSString *)saveImageAndGetFilepath:(nullable UIImage *)image;
+ (nullable NSBundle *)resourceBundle;

+ (BOOL)isDeviceIPhoneX;

+ (BOOL)isDateFutureDate:(nonnull NSDate *)date;

+ (nonnull NSDictionary<NSString *, NSString *> *)queryParametersFromURL:(nonnull NSURL *)url;

+ (nullable NSDictionary *)dictionaryFromJsonString:(nullable NSString *)dataString;

/// Returns the key window from the foreground-active UIWindowScene, or the first window if no key window is found. May return nil if no window is available.
+ (nullable UIWindow *)activeKeyWindow;

/// Returns a suitable root view controller from the active window scene, if available.
+ (nullable UIViewController *)activeRootViewController;

NS_ASSUME_NONNULL_END
@end

