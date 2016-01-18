//
//  LocationManager.h
//  MobileBridge
//
//  Created by Lior Lavon on 24-03-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LocationManagerDelegate <NSObject>
@required
- (void)LocationManagerUpdate:(int)position max:(int)max;
- (void)LocationManagerFinished:(BOOL)updateGeo;
@end

@interface LocationManager : NSObject 
{
    __weak id <LocationManagerDelegate> delegate;
}
@property (weak) id <LocationManagerDelegate> delegate;

-(id)initLocationManager;
-(void)UpdateLocations;
-(void)ParsResult:(NSArray*)data;

@end
