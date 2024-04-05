//
//  IGIRaffleItem.h
//  igi_sdk
//
//  Created by Muhammad Abdullah on 17/07/2019.
//  Copyright © 2019 I Got It. All rights reserved.
//

#import <igi_sdk/IGIItem.h>

@class PusherChannel;


NS_ASSUME_NONNULL_BEGIN

@interface IGIRaffleItem : IGIItem


@property (nonatomic, strong) NSDate *startAt;
@property (nonatomic, strong) NSDate *updatedAt;
@property (nonatomic, assign) double price;
@property (nonatomic, strong) NSString *channelName;
@property (nonatomic, strong) NSString *winnerUserId; // to check if the winner is current user
@property (nonatomic, strong) NSNumber *joinedrafflesCount;
@property (nonatomic, strong) NSNumber *quantity;
@property (nonatomic, strong) NSArray *packageOptions;
@property (nonatomic, strong) NSDictionary * _Nullable selectedOffer;
@property (nonatomic, assign) BOOL referralCodeMandatory;
@property (nonatomic, assign) BOOL shippingAndCCDisabled;
@property (nonatomic, strong) NSArray * _Nullable winners;

@property (nonatomic, strong) PusherChannel *pusherChannel;
@property (nonatomic, strong) NSString *bidBinding;


+ (id)raffleItemWithDictionary:(NSDictionary *)dictionary;
+ (id)raffleItemWithDictionary:(NSDictionary *)dictionary isRequestItem:(BOOL)isRequestItem;

- (BOOL)isEndingSoon;

- (BOOL)hasOffers;

- (BOOL)isSold;

@end

NS_ASSUME_NONNULL_END
