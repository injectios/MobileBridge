//
//  UserNameManager.h
//  MobileBridge
//
//  Created by Lior Lavon on 7/11/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    _name = 0,
    _email = 1,
    _app_version = 2,
    _phone_number = 3
}CustomDataType;

@protocol CustomDataManagerDelegate <NSObject>
@required
- (void)CustomDataManagerFinished;
@end

@interface CustomDataManager : NSObject
{
    __weak id <CustomDataManagerDelegate> delegate;
    
}
@property (weak) id <CustomDataManagerDelegate> delegate;

-(id)initCustomData:(CustomDataType)_type data:(NSString *)data delegate:(id <CustomDataManagerDelegate>)_delegate;
-(NSString*)GetCustomData:(CustomDataType)_type;



@end
