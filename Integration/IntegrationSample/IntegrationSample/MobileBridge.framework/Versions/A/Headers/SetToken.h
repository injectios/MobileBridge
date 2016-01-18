//
//  SetToken.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 22-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SetTokenDelegate <NSObject>
@required
- (void)UpdateTokenFinished:(int)status;
@end

typedef enum
{
    _APNS = 0,
    _BAIDU = 1
}PushType;

@interface SetToken : NSObject
{
    __weak id <SetTokenDelegate> delegate;
}
@property (weak) id <SetTokenDelegate> delegate;

-(id)initSetTokenValue:(NSString*)pToken type:(PushType)_type;
-(id)initSetTokenStatus:(int)_status;



@end
