//
//  IGIAnalyticsEvents.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 27/05/2025.
//  Copyright © 2025 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const IGIEventSDKIntialized;
extern NSString * const IGIEventCompanySettingsFetched;
extern NSString * const IGIEventOpen;
extern NSString * const IGIEventExit;

extern NSString * const IGIEventUserSignUpWithEmail;
extern NSString * const IGIEventUserLoginWithEmail;
extern NSString * const IGIEventUserLoginWithGoogle;
extern NSString * const IGIEventUserLoginWithApple;
extern NSString * const IGIEventUserLoginWithTicketmaster;
extern NSString * const IGIEventUserSessionWithEmail;
extern NSString * const IGIEventUserAccountDeleted;
extern NSString * const IGIEventUserDeviceTokenAdded;
extern NSString * const IGIEventUserProfileFetched;
extern NSString * const IGIEventUserProfileUpdated;
extern NSString * const IGIEventUserStripeSellerOnboardingDone;
extern NSString * const IGIEventUserLogOut;
extern NSString * const IGIEventUserPasswordResetRequested;

extern NSString * const IGIEventPushNotificationsEnabled;
extern NSString * const IGIEventPushNotificationsDisabled;
extern NSString * const IGIEventPushNotificationTapped;
extern NSString * const IGIEventOpenedFromPushNotification;

extern NSString * const IGIEventEmailNotificationsEnabled;
extern NSString * const IGIEventEmailNotificationsDisabled;

extern NSString * const IGIEventDeeplinkTapped;
extern NSString * const IGIEventOpenedFromDeeplink;

extern NSString * const IGIEventItemOfferedForSale;
extern NSString * const IGIEventItemTradableClaimed;
extern NSString * const IGIEventItemPurchased;
extern NSString * const IGIEventItemBidPlaced;
extern NSString * const IGIEventGiveawauViewed;
extern NSString * const IGIEventPaymentMethodAdded;
extern NSString * const IGIEventShippingInfoAdded;
extern NSString * const IGIEventItemListOpened;
extern NSString * const IGIEventItemTapped;
extern NSString * const IGIEventItemIssueReported;
extern NSString * const IGIEventMysteryBoxShipped;
extern NSString * const IGIEventMysteryBoxRevealed;
extern NSString * const IGIEventMysteryBoxRedeemedForCredit;
extern NSString * const IGIEventMysteryBoxComponentsViewed;

extern NSString * const IGIEventMiniTileBuyNowSpecialsTapped;
extern NSString * const IGIEventMiniTilePartnerCollectionTapped;
extern NSString * const IGIEventMiniTileFreeGiveawaysTapped;
extern NSString * const IGIEventMiniTileRedeemPointsTapped;

extern NSString * const IGIEventInterstitialAdViewed;
extern NSString * const IGIEventInterstitialAdClosed;
extern NSString * const IGIEventListAdViewed;

NS_ASSUME_NONNULL_END
