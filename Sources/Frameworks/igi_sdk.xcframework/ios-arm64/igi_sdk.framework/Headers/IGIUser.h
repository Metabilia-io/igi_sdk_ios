//
//  IGIUser.h
//  Pods
//
//  Created by Hammad Mehmood on 01/06/2016.
//
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGIAddress.h>
#import <igi_sdk/IGIPhoto.h>

@interface IGIUser : NSObject


@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, assign) BOOL pushNotificationEnabled;
@property (nonatomic, assign) BOOL emailNotificationEnabled;
@property (nonatomic, assign) BOOL stripeConnectOnboarded;
@property (nonatomic, strong) IGIAddress *shippingAddress;
@property (nonatomic, strong) NSString *phoneNumber;
@property (nonatomic, strong) NSString *stripeCustomerId;
@property (nonatomic, strong) NSString *paymentMethodSourceId;
@property (nonatomic, strong) IGIPhoto *userPhoto;
@property (nonatomic, strong) NSDate *dob;
@property (nonatomic, strong) NSString *dobString;
@property (nonatomic, strong) NSMutableArray *favoriteSports;
@property (nonatomic, strong) NSMutableArray *favoriteTeams;
@property (nonatomic, strong) NSDictionary *loyaltyPoints;

+ (id)userWithDictionary:(NSDictionary *)dictionary;
- (id)initWithDictionary:(NSDictionary *)dictionary;

- (NSString *)getDobString;
- (NSInteger)totalLoyaltyPoints;
- (NSString *)partialEmail;

- (BOOL)isIGIUser;

@end
