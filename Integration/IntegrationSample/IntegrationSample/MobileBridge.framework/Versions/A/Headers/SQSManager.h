//
//  SQSManager.h
//  SQSTest
//
//  Created by Lior Lavon on 23/06/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AWSSQS/AWSSQS.h>

@protocol SQSManagerDelegate <NSObject>
@optional
@end


@interface SQSManager : NSObject
{
    __weak id <SQSManagerDelegate> delegate;
}
@property (weak) id <SQSManagerDelegate> delegate;

+(SQSManager*)getSQSManager;

-(void)PostLogEvent:(NSString*)subject log:(NSDictionary*)log payload:(NSDictionary*)payload useCaching:(BOOL)useCaching;

@end
