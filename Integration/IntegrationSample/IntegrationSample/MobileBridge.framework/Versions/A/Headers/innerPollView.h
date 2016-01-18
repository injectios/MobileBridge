//
//  innerPollView.h
//  MobileBridge
//
//  Created by Lior Lavon on 25/03/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol innerPollViewDelegate <NSObject>
@required
- (void)PollUpdateHeight:(int)tag deltaHeight:(int)deltaHeight;
- (void)PollAnswered:(NSString*)messageReplay;
- (void)PollCoverViewClicked;
- (void)PollViewLoadDateTimePicker:(int)_tagView;
- (void)PollTitle:(NSString*)title;
@end

@interface innerPollView : MyUIView
{
    __weak id <innerPollViewDelegate> delegate;
}
@property (weak) id <innerPollViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame viewTag:(int)_viewTag pollId:(int)_pollId lastUpdateTime:(int)lastUpdateTime delegate:(id <innerPollViewDelegate>)_delegate actionType:(int)_actionType couponId:(int)_couponId;
-(void)SetPollStrokeWithColor:(BOOL)_strokeStatus stroke_r:(float)_stroke_r stroke_g:(float)_stroke_g stroke_b:(float)_stroke_b;
-(void)EditBoxViewSetDate:(int)viewTag secondsFrom1970:(NSTimeInterval)ti;

@end
