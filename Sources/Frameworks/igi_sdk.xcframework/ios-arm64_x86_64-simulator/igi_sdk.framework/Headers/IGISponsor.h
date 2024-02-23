//
//  IGISponsor.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 02/06/2020.
//  Copyright © 2020 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGIPhoto.h>

NS_ASSUME_NONNULL_BEGIN

@interface IGISponsor : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) IGIPhoto *photo;

+ (id)sponsorWithDictionary:(NSDictionary *)dict;
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
