//
//  MB_PollView.h
//  MobileBridge
//
//  Created by Lior Lavon on 25/03/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MB_PollViewDelegate <NSObject>
@required
- (void)MB_PollViewTitle:(NSString*)title;
- (void)MB_PollView_PollAnswered:(NSString*)message;
- (void)MB_PollView_PollAllreadyAnswered;
- (void)MB_PollView_ShowDatePicker:(BOOL)visible viewTag:(int)viewTag;
@end

@interface MB_PollView : UIView <UIAlertViewDelegate>
{
    __weak id <MB_PollViewDelegate> delegate;
}
@property (weak) id <MB_PollViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame assetInfo:(NSDictionary*)_assetInfo delegate:(id <MB_PollViewDelegate>)_delegate;

+(MB_PollView*)newInstance:(CGRect)frame assetInfo:(NSDictionary*)_assetInfo delegate:(id <MB_PollViewDelegate>)_delegate;
-(void)SetBirthdayTag:(NSTimeInterval)_birthday viewTag:(int)viewTag;

@end
