//
//  IGIUtils.h
//  iGotIt
//
//  Created by Ten5Studio on 27/09/2014.
//  Copyright (c) 2014 Ten5 Studios. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IGIUtils : NSObject

+ (NSString *)sdkVersion;

+ (void)showAlertWithTitle:(NSString *)title
                   message:(NSString *)message
                     owner:(UIViewController *)owner;
+ (NSDate *)dateFromTimeInterval:(long)timeInterval;
+ (NSDate *)dateFromString:(NSString *)dateString;
+ (NSString *)stringFromDateForEventLive:(NSDate *)date;
+ (NSString *)stringFromDateForProfile:(NSDate *)date;
+ (NSString *)hourAndMinutesStringFromInterval:(NSTimeInterval )interval;
+ (NSString *)saveImageDataAndGetFilepath:(NSData *)imageData;
+ (NSString *)saveImageAndGetFilepath:(UIImage *)image;
+ (NSBundle *)resourceBundle;

+ (BOOL)isDeviceIPhoneX;

+ (BOOL)isDateFutureDate:(NSDate *)date;

+ (NSDictionary<NSString *, NSString *> *)queryParametersFromURL:(NSURL *)url;

+ (NSDictionary *)dictionaryFromJsonString:(NSString *)dataString;

@end
