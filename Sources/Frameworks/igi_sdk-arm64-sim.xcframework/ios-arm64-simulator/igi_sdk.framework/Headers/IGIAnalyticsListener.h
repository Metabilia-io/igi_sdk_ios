//
//  IGIAnalyticsListener.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 30/08/2022.
//  Copyright © 2022 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IGIAnalyticsListener <NSObject>
@required
- (void)trackPurchaseWithTransactionId:(NSString *)transactionId
                                userId:(NSString *)userId
                                itemId:(NSString *)itemId
                              itemName:(NSString *)itemName
                          itemCategory:(NSString *)itemCategory
                                 price:(double)price
                              quantity:(NSInteger)quantity
                                 total:(double)total
                          currencyCode:(NSString *)currencyCode;

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

- (void)trackPromotionWithTransactionId:(NSString *)transactionId
                                 userId:(NSString *)userId
                                 itemId:(NSString *)itemId
                               itemName:(NSString *)itemName
                           itemCategory:(NSString *)itemCategory
                                  price:(double)price
                               quantity:(NSInteger)quantity
                                  total:(double)total
                           currencyCode:(NSString *)currencyCode;

- (void)trackAddPaymentWithUserId:(NSString *)userId;
- (void)trackAddShippingWithUserId:(NSString *)userId;

- (void)trackItemListSelectionWithItemId:(NSString *)itemId
                                itemName:(NSString *)itemName
                            itemCategory:(NSString *)itemCategory;

- (void)trackItemSelectionWithItemId:(NSString *)itemId
                            itemName:(NSString *)itemName
                        itemCategory:(NSString *)itemCategory
                               price:(double)price;
@optional

- (void)trackEvent:(NSString *)eventName
        attributes:(NSDictionary<NSString *, id> *)attributes;

@end
