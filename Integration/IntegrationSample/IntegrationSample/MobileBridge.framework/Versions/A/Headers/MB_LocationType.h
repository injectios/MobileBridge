//
//  mb_LocationType.h
//  MobileBridge
//
//  Created by Lior Lavon on 9/21/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MB_LocationType : NSObject
{
    int location_id;
    NSString* title;
    NSString* formatted_address;
    
    NSString* phone;
    NSString* email;
    NSString* website;
    double latitude;
    double longitude;
//    double last_modified;
    int allow_trigger; // 0=dont allow trigger 1=allow trigger
    int trigger_status; // 0=not triggered , 1=triggered
    int radius; // radius in meters
    int pin_id; // id of the pin
    NSString* pin_url; // url to the image path
    NSString* pin_name; // name of image path
    NSString* icon_name;
    NSString* icon_path;
    NSArray* pOpeningHours;
    NSArray* pTags;
    double tmp_distance;
}
@property (nonatomic) int location_id;
@property (nonatomic, strong) NSString* title;
@property (nonatomic, strong) NSString* formatted_address;
@property (nonatomic, strong) NSString* phone;
@property (nonatomic, strong) NSString* email;
@property (nonatomic, strong) NSString* website;
@property (nonatomic) double latitude;
@property (nonatomic) double longitude;
//@property (nonatomic) double last_modified;
@property (nonatomic) int allow_trigger;
@property (nonatomic) int trigger_status;
@property (nonatomic) int radius;
@property (nonatomic) int pin_id;
@property (nonatomic, strong) NSString* pin_url;
@property (nonatomic, strong) NSString* pin_name;
@property (nonatomic, strong) NSString* icon_name;
@property (nonatomic, strong) NSString* icon_path;
@property (nonatomic) double tmp_distance;

@property (nonatomic, strong) NSArray* pOpeningHours;
@property (nonatomic, strong) NSArray* pTags;

-(void)description;
@end
