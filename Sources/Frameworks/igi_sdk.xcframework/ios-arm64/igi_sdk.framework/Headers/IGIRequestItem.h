//
//  IGIRequestItem.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 02/07/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGIItem.h>
#import <igi_sdk/IGIUser.h>

@interface IGIRequestItem : NSObject

@property (nonatomic, strong) NSNumber *ID;
@property (nonatomic, strong) NSString *qrUrlString;
@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong) IGIItem *eventItem;
@property (nonatomic, strong) IGIUser *user;
@property (nonatomic, assign) BOOL pickupFromVenue;
@property (nonatomic, strong) NSString *status;
@property (nonatomic, strong) NSString *trackingNumber;
@property (nonatomic, strong) NSString *trackingUrl;
@property (nonatomic, strong) NSDictionary *totalPaymentAmount;
@property (nonatomic, strong) NSDictionary *shipTo;
@property (nonatomic, strong) NSDictionary *selectedSizeOption;
@property (nonatomic, assign) double currentPrice;
@property (nonatomic, assign) BOOL claimed;
@property (nonatomic, assign) BOOL resold;
@property (nonatomic, assign) BOOL transferred;
@property (nonatomic, assign) BOOL gifted;

+ (id)requestItemWithDictionary:(NSDictionary *)dict;
- (id)initWithDictionary:(NSDictionary *)dictionary;

- (BOOL)isPending;
- (BOOL)isPaymentFailed;

- (double)totalAmountPaid;
- (double)itemPrice;
- (double)creatorRoyalty;
- (double)creditAmount;
- (double)discount;
- (double)shipmentCost;
- (double)taxAmount;
- (double)shipmentTaxAmount;
- (double)ccProcessingFee;
- (double)marketplaceFee;
- (double)chargedAmount;



- (NSString *)shipmentAddressString;
- (NSString *)shipmentStatus;

- (NSString *)selectedSizeOptionTitle;

- (BOOL) isAvailable;
- (NSString *) label;

- (NSComparisonResult)compareByCreatedAt:(IGIRequestItem *)otherItem;

@end
