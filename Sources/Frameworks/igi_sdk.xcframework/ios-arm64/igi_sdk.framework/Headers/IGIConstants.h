//
//  IGIConstants.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 14/06/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#ifndef IGIConstants_h
#define IGIConstants_h

#define IGI_SDK_VERSION @"3.0.15+24012501"; //build number format YYMMDD[SERIAL Number e.g 01]

#define IGI_BLUE_COLOR [UIColor colorWithRed:40/255.0f green:143/255.0f blue:211/255.0f alpha:1.0]
#define IGI_GREY_COLOR [UIColor colorWithRed:170/255.0f green:172/255.0f blue:171/255.0f alpha:1.0]

#define IGI_DEV_BASE_URL @"igitestadmin.com"
#define IGI_DEV_PUSHER_APP_KEY @"15bfbc9c5419559d8576"

#define IGI_STAGING_BASE_URL @"igotitstageadmin.com"
#define IGI_STAGING_PUSHER_APP_KEY @"aa4dbc858ae90efa7e2c"

#define IGI_PRODUCTION_BASE_URL @"igotitadmin.com"
#define IGI_PRODUCTION_PUSHER_APP_KEY @"24a35107d85ae8c52008"

//Notifications
#define kRefreshItemsList @"IGI_RefreshItemsList"
#define kNewBidPlaced @"IGI_NewBidPlaced"
#define kNewRafflePlaced @"IGI_NewRafflePlaced"
#define kNewAuctionCreated @"IGI_NewAuctionCreated"
#define kItemBought @"IGI_ItemBought"
#define kBuyItemUpdated @"IGI_BuyItemUpdated"
#define kItemUpdated @"IGI_ItemUpdated"
#define kShareItemClicked @"IGI_ShareItemClicked"
#define kAllSportItemsLoaded @"IGI_AllSportItemsLoaded"
#define kAllTeamItemsLoaded @"IGI_AllTeamItemsLoaded"
#define kCreditCardChanged @"IGI_CreditCardChanged"

//Item types String
#define kItemTypeBuyOnly @"Buy Only" //1
#define kItemTypeBidOnly @"Bid Only" //2
#define KItemTypeAuction @"Auction"  //5
#define KItemTypeRaffle @"Raffle" //6
#define kItemTypeDiscount @"Discount" //7
#define kItemTypeGift @"Gift" //8

//Item types Int
#define kItemTypeBuyOnlyInt @"1"
#define kItemTypeBidOnlyInt @"2"
#define KItemTypeAuctionInt @"5"
#define KItemTypeRaffleInt @"6"
#define kItemTypeDiscountInt @"7"
#define kItemTypeGiftInt @"8"

//Auction types String
#define kAuctionTypeNormal @"Normal"
#define kAuctionTypeSealedBid @"Sealed Bid Auction"
#define kAuctionTypeVolumeReserve @"Volume Reserve Auction"
#define kAuctionTypeYankee @"Yankee"

//Flash Auction types String
#define kFlashAuctionTypeNormal @"Normal"
#define kFlashAuctionTypeDutch @"Dutch Auction"

typedef NS_ENUM(NSInteger, IGI_DRAWER_CONTENT_TYPE) {
    IGI_DRAWER_CONTENT_TYPE_PURCHASES,
    IGI_DRAWER_CONTENT_TYPE_MY_BIDS,
    IGI_DRAWER_CONTENT_TYPE_WISH_LIST,
    IGI_DRAWER_CONTENT_TYPE_SALES
};

#define kEndingSoonTime 2*3600.0f

#ifdef __OBJC__
static inline BOOL isEmpty(id thing) {
    return thing == nil
    || ([thing respondsToSelector:@selector(length)]
        && [(NSData *)thing length] == 0)
    || ([thing respondsToSelector:@selector(count)]
        && [(NSArray *)thing count] == 0)
    || ([thing respondsToSelector:@selector(count)]
        && [(NSDictionary *)thing count] == 0)
    || ([thing isKindOfClass:[NSString class]] && [(NSString *)thing isEqualToString:@"<null>"]);
}
#endif

#endif /* IGIConstants_h */

