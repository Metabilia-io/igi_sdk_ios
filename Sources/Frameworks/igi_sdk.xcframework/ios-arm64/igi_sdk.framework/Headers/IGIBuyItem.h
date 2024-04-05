//
//  IGIBuyItem.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 14/06/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#import <igi_sdk/IGIItem.h>


@class PusherChannel;

@interface IGIBuyItem : IGIItem

@property (nonatomic, assign) NSInteger quantity;
@property (nonatomic, assign) double price;
@property (nonatomic, strong) NSString *channelName;
@property (nonatomic, strong) PusherChannel *pusherChannel;
@property (nonatomic, strong) NSString *itemUpdateBinding;

@property (nonatomic, assign) int buyQuantity; //quantity set by the user

+ (id)buyItemWithDictionary:(NSDictionary *)dict;
+ (id)buyItemWithDictionary:(NSDictionary *)dict isRequestItem:(BOOL)isRequestItem;

@end
