//
//  IGIAnalyticsListener.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 30/08/2022.
//  Copyright © 2022 I Got It. All rights reserved.
//

@protocol IGIAnalyticsListener <NSObject>

@required

/**
 * Buy
 */
- (void)trackPurchaseWithTransactionId:(NSString *)transactionId
                                userId:(NSString *)userId
                                itemId:(NSString *)itemId
                              itemName:(NSString *)itemName
                          itemCategory:(NSString *)itemCategory
                                 price:(double)price
                              quantity:(NSInteger)quantity
                                 total:(double)total
                          currencyCode:(NSString *)currencyCode;

/**
 * Dutch/sealed bid/flash/traditional/reserve
 * bidType = dutch/sealed_bid/flash/traditional/reserve
 */
- (void)trackBidWithTransactionId:(NSString *)transactionId
                           userId:(NSString *)userId
                           itemId:(NSString *)itemId
                         itemName:(NSString *)itemName
                     itemCategory:(NSString *)itemCategory
                            price:(double)price
                         quantity:(NSInteger)quantity
                            total:(double)total
                     currencyCode:(NSString *)currencyCode
                          bidType:(NSString *)bidType;

/**
 * Free sweepstakes/Multiple winner giveaway
 */
- (void)trackPromotionWithTransactionId:(NSString *)transactionId
                                 userId:(NSString *)userId
                                 itemId:(NSString *)itemId
                               itemName:(NSString *)itemName
                           itemCategory:(NSString *)itemCategory
                                  price:(double)price
                               quantity:(NSInteger)quantity
                                  total:(double)total
                           currencyCode:(NSString *)currencyCode;

/**
 * This event signifies a user has submitted their payment information
 */
- (void)trackAddPaymentWithUserId:(NSString *)userId;

/**
 * This event signifies a user has submitted their shipping information
 */
- (void)trackAddShippingWithUserId:(NSString *)userId;

/***
 * Log this event when the user has been presented with a list of items of a certain category.
 */
- (void)trackItemListSelectionWithItemId:(NSString *)itemId
                                itemName:(NSString *)itemName
                            itemCategory:(NSString *)itemCategory;
/***
 * This event signifies that some content was shown to the user. Use this event to discover the most popular items viewed.
 */
- (void)trackItemSelectionWithItemId:(NSString *)itemId
                            itemName:(NSString *)itemName
                        itemCategory:(NSString *)itemCategory
                               price:(double)price;
@end
