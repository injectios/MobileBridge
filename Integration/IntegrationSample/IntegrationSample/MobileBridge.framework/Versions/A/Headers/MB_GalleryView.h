//
//  MB_GalleryView.h
//  MobileBridge
//
//  Created by Lior Lavon on 11/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MB_GalleryViewDelegate <NSObject>
@required
- (void)MB_GalleryTitle:(NSString*)galleryTitle;
- (void)MB_GalleryDeleted;
@end

@interface MB_GalleryView : UIView
{
    __weak id <MB_GalleryViewDelegate> delegate;
}
@property (weak) id <MB_GalleryViewDelegate> delegate;

//- (id)initWithFrame:(CGRect)frame galleryId:(NSDictionary*)_galleryId delegate:(id <MB_GalleryViewDelegate>)_delegate;
+(MB_GalleryView*)newInstance:(CGRect)frame galleryId:(NSDictionary*)_galleryId delegate:(id <MB_GalleryViewDelegate>)_delegate;

@end
