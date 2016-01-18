//
//  GetBeaconsData.h
//  MobileBridge
//
//  Created by Lior Lavon on 09/11/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    get_all_beacons_list = 0, // returns all configured beacons list
    get_triggered_beacon_list = 1, // returns an array of beacon id that where triggerd once
    get_triggered_beacon_history_list = 2, // return an array of all beacon history
    get_top_triggered_beacon_history_list = 3 // get top x beacons is array
}MB_GetBeaconType;

@protocol GetBeaconsDataDelegate <NSObject>
@required
- (void)BeaconsDataReceived:(MB_GetBeaconType)key dataarray:(NSArray*)dataarray;
@end

@interface GetBeaconsData : NSObject
{
    __weak id <GetBeaconsDataDelegate> delegate;
}
@property (weak) id <GetBeaconsDataDelegate> delegate;

-(id)init:(MB_GetBeaconType)actionType delegate:(id <GetBeaconsDataDelegate>)_delegate;

@end
