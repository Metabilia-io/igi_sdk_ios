//
//  IGIManager.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 30/05/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class IGIBaseVC;
@class IGIEvent;
@class IGIUser;
@class IGIAddress;
@class STPCustomerContext;
@protocol IGIAnalyticsListener;

/**
 *  SDK Modes
 *
 *  IGI_SDK_SANDBOX_MODE    SDK Sandbox mode
 *  IGI_SDK_PRODUCTION_MODE SDK Production mode
 */
extern NSString * const IGI_SDK_DEV_MODE;
extern NSString * const IGI_SDK_SANDBOX_MODE;
extern NSString * const IGI_SDK_PRODUCTION_MODE;

/**
 *  Keys of theme dictionary
 *
 *  IGI_KEY_PRIMARY_COLOR   key against which you should store the UIColor you want to set for the Navigation bar
 *  IGI_KEY_SECONDARY_COLOR key against which you should store the UIColor you want to set for the Secondary color
 *  IGI_KEY_TEXT_COLOR  key against which you should store the UIColor you want to set for Navigation bar title text color
 *  IGI_KEY_TEXT_FONT   key against which you should store the UIFont you want to set for Navigation bar title text font
 */
extern NSString * const IGI_KEY_PRIMARY_COLOR;
extern NSString * const IGI_KEY_SECONDARY_COLOR;
extern NSString * const IGI_KEY_TEXT_COLOR;
extern NSString * const IGI_KEY_TEXT_FONT;

typedef NS_ENUM(NSInteger, IGI_PRIVACY_STATUS) {
    IGI_PRIVACY_STATUS_OPT_OUT = 0,
    IGI_PRIVACY_STATUS_OPT_IN = 1
};

typedef void (^IGIManagerCallback)(id obj, NSError *error);



@interface IGIManager : NSObject

@property (readonly, strong) NSString *apiKey;
@property (readonly, strong) IGIUser *currentUser;
@property (readonly, strong) NSString *sdkMode;
@property (readonly, strong) NSString *subDomain;
@property (readonly, strong) NSString *companyName;
@property (readonly, strong) NSString *hereAPIKey;
@property (readonly, strong) STPCustomerContext *customerContext;
@property (nonatomic, strong) NSDictionary *themeDictionary;
@property (nonatomic, weak) id <IGIAnalyticsListener> analyticsDelegate;


@property (nonatomic, assign) BOOL isWhiteLabel;
@property (nonatomic, assign) BOOL showMissions;
@property (nonatomic, assign) BOOL showLatestPurchases;
@property (nonatomic, assign) BOOL showLeaderboard;
@property (nonatomic, assign) BOOL showMarketPlace;
@property (nonatomic, assign) BOOL showMyPortfolio;
@property (nonatomic, assign) BOOL showNotificationsSwitch;
@property (nonatomic, assign) BOOL showAds;

+ (instancetype) sharedManager;

+ (UIColor *)defaultPrimaryColor;

+ (UIColor *)defaultSecondaryColor;

- (UIColor *)primaryColor;

- (UIColor *)secondaryColor;

- (UIColor *)textColor;

- (UIFont *)textFont;

+ (UINavigationController *)navigationControllerForRootVC:(UIViewController *)vc;

/**
 *  Check if SDK is intialized
 *
 *  @return YES if intialized, No if not initialized
 */

- (BOOL)isInitialzied;

/**
 *  Check if SDK can try to login automatically
 *
 *  @return YES or NO
 */

- (BOOL)canLogin;

/**
 *  set user device token for Push Notifications.
 *
 *  @param deviceToken device token received in didRegisterForRemoteNotificationsWithDeviceToken in UIApplicationDelegate method
 */

- (void)setDeviceToken:(NSString *)deviceToken;

/**
 *  Sign up
 *
 *  @param fName        User first name
 *  @param lName        User last name
 *  @param email        User email
 *  @param password     User password
 *  @param callback     callback which will return and error object if initialization fails
 */

/**
 
 Safe method for getting current user Id
 */

- (NSString *)currentUserId;

- (void)signUpWithFirstName:(NSString *)fName
                   lastName:(NSString *)lName
                   password:(NSString *)password
                      email:(NSString *)email
                   birthday:(NSNumber *)birthday
               referralCode:(NSString *)referralCode
                   callback:(IGIManagerCallback)callback;


/**
 *  Login. Both parameters are required.
 *
 *  @param email        User email
 *  @param password     User password
 *  @param callback     callback which will return and error object if initialization fails
 */

- (void)loginWithEmail:(NSString *)email
              password:(NSString *)password
              callback:(IGIManagerCallback)callback;

/**
 *  Login. Both parameters are required.
 *
 *  @param token        firebase token
 *  @param callback     callback which will return and error object if login fails
 */
- (void)loginWithFirebaseToken:(NSString *)token
                      callback:(IGIManagerCallback)callback;

/**
 *  Login. Both parameters are required.
 *
 *  @param accountId        TicketMaster account id
 *  @param customerId     TicketMaster customer id
 *  @param callback     callback which will return and error object if login fails
 */

- (void)loginWithTicketMasterAccountId:(NSString *)accountId
                            customerId:(NSString *)customerId
                              callback:(IGIManagerCallback)callback;


- (void)deleteAccountWithCallback:(IGIManagerCallback )callback;
/**
 *  Initialize SDK. Both parameters are required.
 *
 *  @param apiKey              API key of SDK
 *  @param stripeKey        StripeKey (OPTIONAL)
 *  @param sdkMode          SDK mode. Check IGI_SDK_MODE for possible modes
 *  @param callback          callback which will return and error object if initialization fails
 */

- (void)initializeWithApiKey:(NSString *)apiKey
                     sdkMode:(NSString *)sdkMode
                     subDomain:(NSString *)subDomain
                    callback:(IGIManagerCallback)callback;

/**
 *  Start user session using email. User session required to participate in auctions or to buy items.
 *
 *  @param firstName        first name
 *  @param lastName         last name
 *  @param email                a valid email address
 *  @param callback             callback which will return an error object if session fails. or a user object if session is created successfully
 */


- (void)startUserSessionForFirstName:(NSString *)firstName
                            lastName:(NSString *)lastName
                               email:(NSString *)email
                                 dob:(NSDate *)dob
                         phoneNumber:(NSString *)phoneNumber
                            callback:(IGIManagerCallback)callback;

- (IGI_PRIVACY_STATUS)getPrivacyStatus;

- (void)setPrivacyStatus:(IGI_PRIVACY_STATUS)privacyStatus;

- (void)getAllCompaniesWithCallback:(IGIManagerCallback)callback;

- (void)getItemsForCompaniesWithAPIKey:(NSString *)apiKey
                          searchString:(NSString *)searchString
                              callback:(IGIManagerCallback)callback;

- (void)getCompanySettingsWithCallback:(IGIManagerCallback)callback;

- (void)addPhotoToItem:(NSString *)itemId
                 photo:(NSString *)photoUrl
                apiKey:(NSString *)apiKey
              callback:(IGIManagerCallback)callback;

/**
*  Get current user profile
*
*  @param callback     callback
*/
- (void)getUserProfileWithCallback:(IGIManagerCallback)callback;

- (void)getUserCreditBalanceWithCallback:(IGIManagerCallback )callback;

- (void)getUserLoyaltyPointsWithCallback:(IGIManagerCallback )callback;

- (void)getLeaderboardWithCallback:(IGIManagerCallback )callback;

+ (BOOL)shouldHandleRemodeMessage:(NSDictionary *)userInfo;

/**
 *  Convenience method for handling push notifications received by client application. Return true if handled.
 *
 *  @param userInfo notification user info
 */

- (BOOL)handleRemoteMessage:(NSDictionary *)userInfo;


- (BOOL)handleDeeplinkURL:(NSString *)deeplink;

/**
 *  Update attributes of user profile
 *
 *  @param photoUrl    url of photo for user
 *  @param firstname   user first name
 *  @param lastname    user last name
 *  @param dob         user date of birth
 *  @param phoneNumber user phone number
 *  @param callback    callback
 */
- (void)updateUserProfileWithPhotoURL:(NSString *)photoUrl
                             firsname:(NSString *)firstname
                             lastname:(NSString *)lastname
                                  dob:(NSDate *)dob
                          phoneNumber:(NSString *)phoneNumber
                             callback:(IGIManagerCallback )callback;

/**
 *  Get all event objects
 *
 *  @param callback callback which will return array of event objects or an error on failure
 */

- (void)stripeSellerOnboardingWithFirstName:(NSString *)firstName
                                  lastName:(NSString *)lastName
                             streetAddress:(NSString *)streetAddress
                                      city:(NSString *)city
                                     state:(NSString *)state
                                postalCode:(NSString *)postalCode
                                   country:(NSString *)country
                               dateOfBirth:(NSString *)dateOfBirth
                               phoneNumber:(NSString *)phoneNumber
                                       ssn:(NSString *)ssn
                             routingNumber:(NSString *)routingNumber
                             accountNumber:(NSString *)accountNumber
                                   callback:(IGIManagerCallback )callback;

- (void)bidOnOnSiteItemForEventItemId:(NSNumber *)itemId
                             fullName:(NSString *)fullName
                                email:(NSString *)email
                          phoneNumber:(NSString *)phoneNumber
                            bidAmount:(NSString *)bidAmount
                             callback:(IGIManagerCallback)callback;

- (void)buyOnSiteItemForEventItemID:(NSNumber *)itemId
                           fullName:(NSString *)fullName
                              email:(NSString *)email
                        phoneNumber:(NSString *)phoneNumber
                           stripeId:(NSString *)stripeId
                           callback:(IGIManagerCallback )callback;

- (void)getOnSiteShipmentStatusForEventItemId:(NSNumber *)itemId
                                     callback:(IGIManagerCallback )callback;

- (void)markOnSiteItemDeliveredForRequestId:(NSNumber *)requestId
                                   callback:(IGIManagerCallback)callback;

- (void)markOnSiteItemPaidForRequestId:(NSNumber *)itemId
                                isCash:(BOOL)isCash
                              stripeId:(NSString *)stripeId
                              callback:(IGIManagerCallback)callback;

- (void)getAllEventsWithCallback:(IGIManagerCallback)callback;

- (void)getOnSiteItemsForEvent:(IGIEvent *)event
                      callback:(IGIManagerCallback)callback;

- (void)getRequestsForEventId:(NSString *)eventId
                       filter:(NSString *)filter
                     callback:(IGIManagerCallback )callback;

- (void)getOnSiteEventsWithCallback:(IGIManagerCallback)callback;

- (void)getBidsForEventItemId:(NSNumber *)itemId
                        limit:(NSString *)limit
                     callback:(IGIManagerCallback)callback;

- (void)getEventFiltersForEventId:(NSString *)eventId
                         callback:(IGIManagerCallback )callback;

- (void)getPointsBasedItemsWithCallback:(IGIManagerCallback )callback;

- (void)getLiveGiveawaysWithCallback:(IGIManagerCallback )callback;

- (void)getWonGiveawaysWithCallback:(IGIManagerCallback )callback;

- (UIViewController *)signUpScreenWithoutNavigation;

/**
 *  Events listing screen
 *
 *
 *  @return UINavigationController with Events listing screen set as RootViewController
 */

- (UINavigationController *)eventsScreen;

- (UINavigationController *)mainStoryboard;

- (UINavigationController *)eventsScreenForLeftMenuWithSelector:(SEL)menuSelector
                                                         target:(id)menuButtonTarget;

/**
 *  Item listing screen with items of provided IGIEvent
 *
 *  @param event     IGIEvent object
 *
 *  @return UINavigationController with Item listing screen set as RootViewController
 */

- (UINavigationController *)itemsScreenForEvent:(IGIEvent *)event;

/**
 *  Shipment Information screen
 *
 *
 *  @return UINavigationController with Shipment Information screen set as RootViewController
 */

- (UINavigationController *)shipmentInfoScreen;

/**
 *  My Items screen. This screen will have items that you won in an auction/bid or any item you purchased
 *
 *
 *  @return UINavigationController with My Items screen set as RootViewController
 */

- (UINavigationController *)myItemsScreen;

- (UIViewController *)myItemsScreenWithoutNavigation;

- (UINavigationController *)settingsScreen;

- (UIViewController *)settingsScreenWithoutNavigation;

- (UIViewController *)marketplaceScreenWithoutNavigation;

- (UIViewController *)myDigitalPortfolioScreenWithoutNavigation;

- (UIViewController *)recentTransactionsScreenWithoutNavigation;

- (UIViewController *)missionsScreenWithoutNavigation;

- (UINavigationController *)browserScreenWithTitle:(NSString *)title url:(NSURL *)url;

- (void)logOut;

- (void)requestPasswordResetForEmail:(NSString *)email
                            callback:(IGIManagerCallback)callback;

- (void)getCurrentUserFavoriteSportsWithCallback:(IGIManagerCallback)callback;

- (void)getCurrentUserFavoriteTeamsWithCallback:(IGIManagerCallback)callback;

- (void)getAllSportsWithCallback:(IGIManagerCallback)callback;

- (void)getAllTeamsForSport:(NSString *)sportId
                   callback:(IGIManagerCallback)callback;

- (void)getAllTeamsWithCallback:(IGIManagerCallback)callback;

- (void)markSportAsFavoriteWithSportId:(NSString *)sportId
                                  callback:(IGIManagerCallback)callback;

- (void)unmarkSportAsFavoriteWithSportId:(NSString *)sportId
                                    callback:(IGIManagerCallback)callback;

- (void)markTeamAsFavoriteWithTeamId:(NSString *)teamId
                                 callback:(IGIManagerCallback)callback;

- (void)unmarkTeamAsFavoriteWithTeamId:(NSString *)teamId
                                   callback:(IGIManagerCallback)callback;

- (NSString *)getDevicePhysicalAddress;

- (NSString *)host;

- (NSString *)baseURL;

- (void)addStripeCardWithAccessToken:(NSString *)accessToken
                         stripeToken:(NSString *)stripeToken
                            callback:(IGIManagerCallback)callback;

- (void)enablePushNotificationsWithEnabled:(BOOL)enabled
                                  callback:(IGIManagerCallback)callback;

- (void)enableEmailNotificationsWithEnabled:(BOOL)enabled
                                   callback:(IGIManagerCallback)callback;

- (void)getMarketplaceItemsWithCallback:(IGIManagerCallback)callback;

- (void)getRecentTransactionsWithCallback:(IGIManagerCallback)callback;

- (void)getTransactionHistoryWithItemId:(NSString *)itemId
                           digitalItemId:(NSString *)digitalItemId
                                  skuId:(NSString *)skuId
                                  limit:(long)limit
                                callback:(IGIManagerCallback)callback;

- (void)offerItemForTradeWithEventItemdId:(NSString *)eventItemId
                                itemType:(NSString *)itemType
                                    skuId:(NSString *)skuId
                            offeredPrice:(NSString *)offeredPrice
                                 startAt:(NSDate *)startAt
                                closesAt:(NSDate *)closesAt
                                 callback:(IGIManagerCallback)callback;

- (void)getMyDigitalItemsWithCallback:(IGIManagerCallback)callback;

- (void)isOwnerOfDigitalAssetWithSkuId:(NSString *)skuId
                              callback:(IGIManagerCallback)callback;

- (NSURL *)quantumLedgerExplorerUrl:(NSString *)transactionId;

- (void)getQuestItemsWithCallback:(IGIManagerCallback)callback;

- (void)claimUtilityWithEventItemdId:(NSString *)eventItemId
                               skuId:(NSString *)skuId
                            callback:(IGIManagerCallback)callback;

- (void)getAccountHistoryWithCallback:(IGIManagerCallback)callback;

- (void)getUserOffersWithCallback:(IGIManagerCallback)callback;

- (void)reportIssueWithSource:(NSString *)source
                     sourceId:(NSNumber *)sourceId
                    issueType:(NSString *)issueType
                  description:(NSString *)description
                     callback:(IGIManagerCallback)callback;

- (void)shipMysteryBoxWithRequestId:(NSNumber *)requestId
                           callback:(IGIManagerCallback )callback;

- (void)revealMysteryBoxWithRequestId:(NSNumber *)requestId
                             callback:(IGIManagerCallback )callback;

- (void)buyBackMysteryBoxWithRequestId:(NSNumber *)requestId
                              callback:(IGIManagerCallback )callback;

- (void)getAdsWithCallback:(IGIManagerCallback)callback;

- (void)verifyAuthenticity:(NSString *)code
                  callback:(IGIManagerCallback)callback;

- (void)calculateTaxForEventItemsWithData:(NSString *)data
                                  orderId:(NSString *)orderId
                                 callback:(IGIManagerCallback)callback;

- (void)markOrderPaidWithOrderId:(NSString *)orderId
                          isCash:(BOOL)isCash
                   markDelivered:(BOOL)markDelivered
                 paymentIntentId:(NSString *)paymentIntentId
                        callback:(IGIManagerCallback)callback;

- (void)markOrderDeliveredWithOrderId:(NSString *)orderId
                               callback:(IGIManagerCallback)callback;

- (void)sendInvoiceToEmail:(NSString *)email
                   orderId:(NSString *)orderId
                  callback:(IGIManagerCallback)callback;

@end
