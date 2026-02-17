//
//  IGIBid.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 14/06/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGIUser.h>
#import <igi_sdk/IGIRecommendedItem.h>

@interface IGIBid : NSObject

@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, assign) NSInteger currentBidNumber;
@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSString *itemID;
@property (nonatomic, assign) double price;
@property (nonatomic, strong) NSString *status;
@property (nonatomic, strong) IGIUser *user;
@property (nonatomic, strong) IGIUser *lastHighest; /*to control the outbid notification*/
@property (nonatomic, strong) IGIRecommendedItem *recommendedItem;
@property (nonatomic, assign) BOOL isCurrentUserLoser;
@property (nonatomic, strong) NSMutableArray *winnderIds;


+ (id)bidWithDictionary:(NSDictionary *)dictionary;
- (id)initWithDictionary:(NSDictionary *)dictionary;

- (BOOL)isCurrent;
- (BOOL)isWon;

- (NSComparisonResult)compareByPrice:(IGIBid *)bid;

@end
