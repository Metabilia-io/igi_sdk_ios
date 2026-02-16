//
//  IGIBuyItemDiscount.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 17/10/2025.
//  Copyright © 2025 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IGIBuyItemDiscount : NSObject

@property (nonatomic, strong) NSNumber *ID;
@property (nonatomic, assign) NSInteger quantity;
@property (nonatomic, assign) NSInteger discountPercentage;

+ (id)buyItemDiscountWithDictionary:(NSDictionary *)dict;
- (id)initWithDictionary:(NSDictionary *)dictionary;

+ (id)buyItemDiscountWithQuantity:(NSInteger)quantity
                       percentage:(NSInteger)percentage;

@end

NS_ASSUME_NONNULL_END
