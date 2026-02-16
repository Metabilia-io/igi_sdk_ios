//
//  IGIRecommendedItem.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 02/03/2020.
//  Copyright © 2020 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IGIRecommendedItem : NSObject

@property (nonatomic, strong) NSNumber * ID;
@property (nonatomic, strong) NSString * title;
@property (nonatomic, assign) double price;
@property (nonatomic, strong) NSString * photo;

+ (id)recommendedItemWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
