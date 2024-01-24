//
//  IGIItem.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 14/06/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGIConstants.h>
#import <igi_sdk/IGISponsor.h>

@interface IGIItem : NSObject

@property (nonatomic, strong) NSNumber *ID;
@property (nonatomic, strong) NSNumber *itemId;
@property (nonatomic, strong) NSNumber *isFeatured;
@property (nonatomic, strong) NSNumber *isDigital;
@property (nonatomic, strong) NSNumber *isPackage;
@property (nonatomic, assign) BOOL isFreeShipping;
@property (nonatomic, assign) BOOL isCharityAuction;
@property (nonatomic, strong) NSNumber *contingetnRequirements;
@property (nonatomic, strong) NSString *status;
@property (nonatomic, strong) NSMutableArray * photos;
@property (nonatomic, strong) NSMutableArray * videos;
@property (nonatomic, strong) NSString * title;
@property (nonatomic, strong) NSString * itemDescription;
@property (nonatomic, strong) NSString * itemType;
@property (nonatomic, assign) NSInteger watchCount;
@property (nonatomic, assign) BOOL isStared;
@property (nonatomic, assign) BOOL isItemAddedtoWishList;
@property (nonatomic, strong) NSNumber *order;
@property (nonatomic, strong) NSArray *itemOptions;
@property (nonatomic, strong) NSString *skuPrefix;
@property (nonatomic, strong) NSString *skuId;
@property (nonatomic, strong) IGISponsor *sponsor;
@property (nonatomic, strong) NSNumber *isExperience;
@property (nonatomic, strong) NSDate *closesAt;
@property (nonatomic, assign) BOOL pickupAllowed;
@property (nonatomic, assign) BOOL isTradablePhysicalItem;
@property (nonatomic, assign) BOOL hasPhotoMatching;
@property (nonatomic, strong) IGIPhoto *photoMatchingImage;
@property (nonatomic, assign) BOOL isCertified;
@property (nonatomic, strong) NSString *certifier;
@property (nonatomic, strong) NSString *certificateNumber;
@property (nonatomic, strong) IGIPhoto *authenticityCertificate;
@property (nonatomic, strong) NSString *category;
@property (nonatomic, strong) NSString *player;
@property (nonatomic, assign) BOOL hasBonus;
@property (nonatomic, assign) NSInteger bounsPoints;

//digital item fields
@property (nonatomic, strong) NSString *digitalItemId;
@property (nonatomic, assign) double digitalCurrentPrice;
@property (nonatomic, assign) NSInteger masterDigitalQuantity;
@property (nonatomic, assign) NSInteger digitalAssetIndex;
@property (nonatomic, strong) NSString *actualAsseturl;
@property (nonatomic, strong) NSString *previewAssetUrl;
@property (nonatomic, strong) NSString *thumbnailUrl;
@property (nonatomic, strong) NSString *nftUrl;


+ (id)itemWithDictionary:(NSDictionary *)dictionary;
- (id)initWithDictionary:(NSDictionary *)dictionary;
- (id)init;

- (NSString *)itemTitleAndDescription;

- (BOOL)shouldHidePickupOptions;

- (BOOL)isTradable;

- (NSString *)itemInformationTitle;

- (NSString *)priceTitleString;
- (NSString *)priceString;

- (double)timeLeft;
- (NSString *)timeLeftTitleString;
- (NSString *)timeLeftAsString;

- (BOOL)shouldStartTimer;

- (BOOL)isPublished;
- (BOOL)isOpen;
- (BOOL)isClosed;
- (BOOL)isPaymentFailed;

- (NSComparisonResult)compareByOrder:(IGIItem *)otherItem;

@end
