//
//  GetBeaconData.h
//  MobileBridge
//
//  Created by Lior Lavon on 04/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GetBeaconDataDelegate <NSObject>
@required
- (void)BeaconDataReceived:(NSDictionary*)data;
@end

@interface GetBeaconData : NSObject
{
    __weak id <GetBeaconDataDelegate> delegate;
}
@property (weak) id <GetBeaconDataDelegate> delegate;

-(id)initWith:(int)_major minor:(int)_minor delegate:(id <GetBeaconDataDelegate>)_delegate;

@end
