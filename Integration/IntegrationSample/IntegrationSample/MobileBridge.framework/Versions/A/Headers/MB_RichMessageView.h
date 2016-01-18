//
//  MB_RichMessageView.h
//  MobileBridge
//
//  Created by Lior Lavon on 11/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GetRichMessageData.h"

@protocol MB_RichMessageViewDelegate <NSObject>
@optional
- (void)MB_RichMessageTitle:(NSString*)messageTitle;
- (void)MB_RichMessageDeleted;
@end


@interface MB_RichMessageView : UIView
{
    __weak id <MB_RichMessageViewDelegate> delegate;
}
@property (weak) id <MB_RichMessageViewDelegate> delegate;

//-(id)initWithFrame:(CGRect)frame delegate:(id <MB_RichMessageViewDelegate>)_delegate assetInfo:(NSDictionary*)_assetInfo;
+(MB_RichMessageView*)newInstance:(CGRect)frame delegate:(id <MB_RichMessageViewDelegate>)_delegate assetInfo:(NSDictionary*)_assetInfo;

@end
