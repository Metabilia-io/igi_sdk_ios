//
//  IGIVenue.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 15/07/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGIPhoto.h>
#import <igi_sdk/IGIAddress.h>
#import <CoreLocation/CoreLocation.h>



@interface IGIVenue : NSObject

@property (nonatomic, strong) NSNumber *ID;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *venueDescription;
@property (nonatomic, strong) IGIPhoto *photo;
@property (nonatomic, strong) IGIAddress *venueAddress;
@property (nonatomic, assign) double latitude;
@property (nonatomic, assign) double longitude;
@property (nonatomic, strong) CLLocation *venueLocation;

+ (id)venueWithDictionary:(NSDictionary *)addressDict;
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
