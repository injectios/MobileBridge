//
//  MB_SurveyView.h
//  MobileBridge
//
//  Created by Lior Lavon on 12/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "lib_UICheckView.h"

#import "lib_UICheckView.h"
#import "MySliderView.h"
#import "lib_GroupCBView.h"

#import "MessageUI/MessageUI.h"

@protocol MB_SurveyViewDelegate <NSObject>
@required
- (void)MB_SurveyView_SurveyTitle:(NSString*)title;
- (void)MB_SurveyView_SurveyAnswered:(NSString*)message;
- (void)MB_SurveyView_SurveyAllreadyAnswered;
@end

@interface MB_SurveyView : UIView 
{
    __weak id <MB_SurveyViewDelegate> delegate;
}
@property (weak) id <MB_SurveyViewDelegate> delegate;

//- (id)initWithFrame:(CGRect)frame assetInfo:(NSDictionary*)_assetInfo delegate:(id <MB_SurveyViewDelegate>)_delegate;
+(MB_SurveyView*)newInstance:(CGRect)frame assetInfo:(NSDictionary*)_assetInfo delegate:(id <MB_SurveyViewDelegate>)_delegate;

@end
