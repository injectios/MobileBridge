//
//  GetRichMessageData.h
//  MobileBridge
//
//  Created by Lior Lavon on 04/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GetRichMessageDataDelegate <NSObject>
@required
- (void)RichMessageDataReceived:(NSString*)type data:(NSArray*)data;
@end

@interface GetRichMessageData : NSObject
{
    __weak id <GetRichMessageDataDelegate> delegate;
}
@property (weak) id <GetRichMessageDataDelegate> delegate;

-(id)initWithRichMessageData:(NSDictionary*)_assetInfo delegate:(id <GetRichMessageDataDelegate>)_delegate;
-(id)initWithRichMessageId:(int)_articleId delegate:(id <GetRichMessageDataDelegate>)_delegate;
-(id)initGetAllRichMessageData:(id <GetRichMessageDataDelegate>)_delegate;

@end
