//
//  IGIBidItem.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 14/06/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#import <igi_sdk/IGIItem.h>
#import <igi_sdk/IGIBid.h>

@class PusherChannel;

typedef NS_ENUM(NSInteger, IGI_AUCTION_TYPE) {
    IGI_AUCTION_TYPE_NORMAL,
    IGI_AUCTION_TYPE_SEALED_BID,
    IGI_AUCTION_TYPE_VOLUME_RSERVE,
    IGI_AUCTION_TYPE_YANKEE
};

@interface IGIBidItem : IGIItem

@property (nonatomic, strong) NSDate *startAt;
@property (nonatomic, strong) NSDate *updatedAt;

@property (nonatomic, assign) IGI_AUCTION_TYPE auctionType;

@property (nonatomic, assign) double startingPrice;
@property (nonatomic, assign) double reservePrice;
@property (nonatomic, assign) double bidDenomination;
@property (nonatomic, assign) BOOL fixedIncrement;
@property (nonatomic, assign) BOOL allowBuyNow;
@property (nonatomic, assign) BOOL maxBidEnabled;
@property (nonatomic, assign) double buyNowPrice;
@property (nonatomic, assign) double userBidValue; //price set by the user
@property (nonatomic, strong) NSString *maxBidUserId;
@property (nonatomic, assign) double maxBidValue;
@property (nonatomic, strong) IGIBid *currentBid;
@property (nonatomic, strong) NSString *channelName;
@property (nonatomic, strong) PusherChannel *pusherChannel;
@property (nonatomic, strong) NSString *bidBinding;
@property (nonatomic, strong) NSDictionary *lastBidInfo;


+ (id)bidItemWithDictionary:(NSDictionary *)dictionary;
+ (id)bidItemWithDictionary:(NSDictionary *)dictionary isRequestItem:(BOOL)isRequestItem;

- (double)bidIncrement;
- (double)currentBidAmount;
- (double)nextBidAmount;
- (double)previousBidAmount;
- (NSInteger)totalBidsCount;
- (BOOL)isEndingSoon;

- (BOOL)isCurrentUserHighestBidder;
- (BOOL)isCurrentUserMaxBidder;

- (NSString *)type;

@end
