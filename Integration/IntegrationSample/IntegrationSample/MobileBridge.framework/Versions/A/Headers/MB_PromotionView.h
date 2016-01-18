//
//  MB_PromotionView.h
//  MobileBridge
//
//  Created by Lior Lavon on 10/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PromotionManager.h"
#import "PromotionActivationView.h"
#import "MessageUI/MessageUI.h"
#import "innerPollView.h"

typedef enum
{
	share_on_facebook = 0,
	share_on_twitter = 1,
	share_on_qr = 2,
	share_on_whatsapp = 3,
	share_on_email = 4
}PromotionViewShareType;

@protocol MB_PromotionViewDelegate <NSObject>
@required
- (void)MB_PromotionViewTitle:(NSString*)title;
- (void)MB_PromotionViewAllowSharing;
- (void)MB_PromotionViewFinishedActivation:(NSString*)message;
- (void)MB_PromotionViewClose:(NSString*)message;
- (void)MB_PromotionView_ShowGallery:(NSDictionary*)pGalleryId;
- (void)MB_PromotionView_ShowRichMessage:(NSDictionary*)pRichMessageId;
- (void)MB_PromotionView_ShowLocations:(NSDictionary*)pPromotionId;
@optional
- (BOOL)MB_PreRedemtionEvent;
@end

@interface MB_PromotionView : UIView
{
    __weak id <MB_PromotionViewDelegate> delegate;
}
@property (weak) id <MB_PromotionViewDelegate> delegate;

+(MB_PromotionView*)newInstance:(CGRect)frame delegate:(id <MB_PromotionViewDelegate>)_delegate assetInfo:(NSDictionary*)_assetInfo pParent:(UIViewController*)_pParentViewController;
//- (id)initWithFrame:(CGRect)frame delegate:(id <MB_PromotionViewDelegate>)_delegate assetInfo:(NSDictionary*)_assetInfo pParent:(UIViewController*)_pParentViewController;
-(void)ShareWith:(PromotionViewShareType)shareWith;
-(BOOL)BackPressed:(NSString*)type;
-(void)ContinueRedemtion;

@end
