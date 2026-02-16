//
//  IGIShipment.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 28/03/2024.
//  Copyright © 2024 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IGIShipment : NSObject

+ (id)shipmentWithDictionary:(NSDictionary *)dict;
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
