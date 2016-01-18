//
//  GetTagsData.h
//  MobileBridge
//
//  Created by Lior Lavon on 04/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    _promotion_tag = 0,
    _rich_message_tag = 1,
    _survey_tag = 2,
    _poll_tag = 3,
    _location_tag = 4
}TagsType;

@protocol GetTagsDataDelegate <NSObject>
@required
- (void)TagDataReceived:(TagsType)tagType data:(NSArray*)dataarray;
@end

@interface GetTagsData : NSObject
{
    __weak id <GetTagsDataDelegate> delegate;
}
@property (weak) id <GetTagsDataDelegate> delegate;

-(id)initWithTag:(TagsType)tagType delegate:(id <GetTagsDataDelegate>)_delegate;

@end
