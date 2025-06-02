//
//  IGICompany.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 19/08/2023.
//  Copyright © 2023 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGIPhoto.h>

NS_ASSUME_NONNULL_BEGIN

@interface IGICompany : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *apiKey;

+ (id)companyWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
