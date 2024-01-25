//
//  IGISVProgressHUD.h
//
//  Copyright 2011-2014 Sam Vermette. All rights reserved.
//
//  https://github.com/samvermette/SVProgressHUD
//

#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>

extern NSString * const IGISVProgressHUDDidReceiveTouchEventNotification;
extern NSString * const IGISVProgressHUDDidTouchDownInsideNotification;
extern NSString * const IGISVProgressHUDWillDisappearNotification;
extern NSString * const IGISVProgressHUDDidDisappearNotification;
extern NSString * const IGISVProgressHUDWillAppearNotification;
extern NSString * const IGISVProgressHUDDidAppearNotification;

extern NSString * const IGISVProgressHUDStatusUserInfoKey;

typedef NS_ENUM(NSUInteger, IGISVProgressHUDMaskType) {
    IGISVProgressHUDMaskTypeNone = 1,  // allow user interactions while HUD is displayed
    IGISVProgressHUDMaskTypeClear,     // don't allow user interactions
    IGISVProgressHUDMaskTypeBlack,     // don't allow user interactions and dim the UI in the back of the HUD
    IGISVProgressHUDMaskTypeGradient   // don't allow user interactions and dim the UI with a a-la-alert-view background gradient
};

@interface IGISVProgressHUD : UIView

#pragma mark - Customization

+ (void)setBackgroundColor:(UIColor*)color;                 // default is [UIColor whiteColor]
+ (void)setForegroundColor:(UIColor*)color;                 // default is [UIColor blackColor]
+ (void)setRingThickness:(CGFloat)width;                    // default is 4 pt
+ (void)setFont:(UIFont*)font;                              // default is [UIFont preferredFontForTextStyle:UIFontTextStyleSubheadline]
+ (void)setInfoImage:(UIImage*)image;                       // default is the bundled info image provided by Freepik
+ (void)setSuccessImage:(UIImage*)image;                    // default is the bundled success image provided by Freepik
+ (void)setErrorImage:(UIImage*)image;                      // default is the bundled error image provided by Freepik
+ (void)setDefaultMaskType:(IGISVProgressHUDMaskType)maskType; // default is IGISVProgressHUDMaskTypeNone
+ (void)setViewForExtension:(UIView*)view;                  // default is nil, only used if #define SV_APP_EXTENSIONS is set

#pragma mark - Show Methods

+ (void)show;
+ (void)showWithMaskType:(IGISVProgressHUDMaskType)maskType;
+ (void)showWithStatus:(NSString*)status;
+ (void)showWithStatus:(NSString*)status maskType:(IGISVProgressHUDMaskType)maskType;

+ (void)showProgress:(float)progress;
+ (void)showProgress:(float)progress maskType:(IGISVProgressHUDMaskType)maskType;
+ (void)showProgress:(float)progress status:(NSString*)status;
+ (void)showProgress:(float)progress status:(NSString*)status maskType:(IGISVProgressHUDMaskType)maskType;

+ (void)setStatus:(NSString*)string; // change the HUD loading status while it's showing

// stops the activity indicator, shows a glyph + status, and dismisses HUD a little bit later
+ (void)showInfoWithStatus:(NSString *)string;
+ (void)showInfoWithStatus:(NSString *)string maskType:(IGISVProgressHUDMaskType)maskType;

+ (void)showSuccessWithStatus:(NSString*)string;
+ (void)showSuccessWithStatus:(NSString*)string maskType:(IGISVProgressHUDMaskType)maskType;

+ (void)showErrorWithStatus:(NSString *)string;
+ (void)showErrorWithStatus:(NSString *)string maskType:(IGISVProgressHUDMaskType)maskType;

// use 28x28 white pngs
+ (void)showImage:(UIImage*)image status:(NSString*)status;
+ (void)showImage:(UIImage*)image status:(NSString*)status maskType:(IGISVProgressHUDMaskType)maskType;

+ (void)setOffsetFromCenter:(UIOffset)offset;
+ (void)resetOffsetFromCenter;

+ (void)popActivity; // decrease activity count, if activity count == 0 the HUD is dismissed
+ (void)dismiss;

+ (BOOL)isVisible;

@end

