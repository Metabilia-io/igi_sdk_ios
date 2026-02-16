//
//  IGIBaseVC.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 14/06/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IGIBaseVC : UIViewController

//@property (nonatomic, strong)  NSString * _Nullable eventName;

@property (nonatomic, strong) NSMutableArray * _Nullable _notificationsHandlers;
@property (nonatomic, assign) BOOL isModel;

- (UIImage * _Nullable)screenshot;

- (void)showAlertWithTitle:(NSString * _Nullable)title
                   message:(NSString * _Nullable)message;

- (void)showAlertWithTitle:(NSString * _Nullable)title
                   message:(NSString * _Nullable)message
                  okAction:(void (^ __nullable)(UIAlertAction * _Nullable action))handler;

- (void)showAlertWithTitle:(NSString * _Nullable)title
                   message:(NSString * _Nullable)message
                showCancel:(BOOL)showCancel
                  okAction:(void (^ __nullable)(UIAlertAction * _Nullable action))handler;

- (void)showAlertWithTitle:(NSString *_Nullable)title
                   message:(NSString *_Nullable)message
                 uiControl:(UIControl *_Nullable)uiControl
                 actionOne:(UIAlertAction *_Nullable)actionOne
                 actionTwo:(UIAlertAction *_Nullable)actionTwo;

- (IBAction)backBtnPressed:(id _Nullable)sender;
- (IBAction)closeBtnPressed:(id _Nullable)sender;

-(void)setupGUI;
-(void)updateGUI;

-(void)setupTransitionAnimations;

- (BOOL)handleNoEmailError:(NSError * _Nonnull)error;
- (void)showLoginSignUpPrompt;
- (void)showForgotPasswordPrompt;

@end
