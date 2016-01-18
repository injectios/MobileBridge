//
//  MB_BannerView.h
//  MobileBridge
//
//  Created by Lior Lavon on 31-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol MB_BannerViewDelegate <NSObject>
@required
- (void)MB_BannerSelected:(NSString*)type itemId:(NSDictionary*)pAssetInfo;
@end

@interface MB_BannerView : UIView 
{
    __weak id <MB_BannerViewDelegate> delegate;
}
@property (weak) id <MB_BannerViewDelegate> delegate;

+(MB_BannerView*)newInstance:(CGRect)frame;

@end
