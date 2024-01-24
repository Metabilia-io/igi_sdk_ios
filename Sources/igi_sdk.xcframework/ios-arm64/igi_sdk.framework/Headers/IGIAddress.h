//
//  IGIAddress.h
//  Pods
//
//  Created by Hammad Mehmood on 01/06/2016.
//
//

#import <Foundation/Foundation.h>

@interface IGIAddress : NSObject

@property (nonatomic, strong) NSString *address_line1;
@property (nonatomic, strong) NSString *address_line2;
@property (nonatomic, strong) NSString *city;
@property (nonatomic, strong) NSString *country;
@property (nonatomic, strong) NSString *state;
@property (nonatomic, strong) NSString *zip;



+ (id)addressFromDictionary:(NSDictionary *)addressDict;
- (id)initWithDictionary:(NSDictionary *)dictionary;

- (NSString *)shortString;
- (NSString *)longString;

@end
