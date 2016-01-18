//
//  AppTraceCodeType.h
//  MobileBridge
//
//  Created by Lior Lavon on 27/11/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppTraceCodeType : NSObject
{
    NSString* code;
}
@property (nonatomic, retain) NSString* code;

-(void)setCode:(NSString *)_code;

@end
