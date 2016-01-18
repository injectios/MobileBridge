//
//  GetInboxData.h
//  MobileBridge
//
//  Created by Lior Lavon on 04/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
	get_inbox_data = 0,
    delete_all_and_get_inbox_data = 1,
    delete_item_and_get_inbox_data = 2,
    get_inbox_count = 3
}MB_InboxActionType;

@protocol GetInboxDataDelegate <NSObject>
@required
- (void)InboxDataReceived:(MB_InboxActionType)identifier dataarray:(NSDictionary*)dataarray;
@end

@interface GetInboxData : NSObject
{
    __weak id <GetInboxDataDelegate> delegate;
}
@property (weak) id <GetInboxDataDelegate> delegate;

-(id)init:(MB_InboxActionType)actionType inboxId:(NSString*)inboxId delegate:(id <GetInboxDataDelegate>)_delegate;

@end
