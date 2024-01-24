//
//  IGITeamObject.h
//  igi_sdk
//
//  Created by Hammad Mehmood on 24/11/2016.
//  Copyright © 2016 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGISportObject.h>
#import <igi_sdk/IGISelectable.h>
#import <igi_sdk/IGIPhoto.h>

@interface IGITeamObject : NSObject <IGISelectable>

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSNumber *ID;
@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong) IGIPhoto *selectedPhoto;
@property (nonatomic, strong) IGIPhoto *unselectedPhoto;
@property (nonatomic, strong) NSNumber *sportId;

+ (id)teamObjectWithDictionary:(NSDictionary *)dictionary;
- (id)initWithDictionary:(NSDictionary *)dictionary;
@end
