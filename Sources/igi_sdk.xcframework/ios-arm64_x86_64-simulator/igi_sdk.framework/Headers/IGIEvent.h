//
//  IGIEvent.h
//  Pods
//
//  Created by Hammad Mehmood on 01/06/2016.
//
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGIPhoto.h>
#import <igi_sdk/IGIVenue.h>

@interface IGIEvent : NSObject

@property (nonatomic, strong) NSString * eventDescription;
@property (nonatomic, strong) NSDate * endAt;
@property (nonatomic, strong) NSDate * startAt;
@property (nonatomic, strong) NSString * ID;
@property (nonatomic, assign) BOOL status;
@property (nonatomic, strong) NSString * tagLine;
@property (nonatomic, strong) NSString * title;
@property (nonatomic, strong) IGIPhoto * photo;
@property (nonatomic, strong) NSNumber *order;
@property (nonatomic, strong) NSString *channelName;
@property (nonatomic, strong) IGIVenue *venue;
@property (nonatomic, strong) NSString *dateString;
@property (nonatomic, assign) BOOL isPromotion;
@property (nonatomic, strong) NSString *deepLinkURL;



+ (id)eventWithDictionary:(NSDictionary *)dictionary;
- (id)initWithDictionary:(NSDictionary *)dictionary;

- (NSComparisonResult)compareByOrder:(IGIEvent *)otherEvent;

- (BOOL)isEventLive;
- (BOOL)isFinished;

- (NSString *)getDateStringForFutureEvent;

@end
