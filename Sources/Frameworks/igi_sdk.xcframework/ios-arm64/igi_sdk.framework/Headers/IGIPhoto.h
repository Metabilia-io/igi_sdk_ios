//
//  IGIPhoto.h
// 
//
//  Created by Hammad Mehmood on 01/06/2016.
//
//

#import <Foundation/Foundation.h>

@interface IGIPhoto : NSObject

@property (nonatomic, strong) NSString *thumbUrl;
@property (nonatomic, strong) NSString *mediumUrl;
@property (nonatomic, strong) NSString *largeUrl;

+ (id)photoWithDictionary:(NSDictionary *)dictionary;
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
