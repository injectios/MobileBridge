//
//  MobileBridgeLibrary.h
//  MobileBridge
//
//  Created by Lior Lavon on 27-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MB_PromotionView.h"
#import "MB_GalleryView.h"
#import "MB_RichMessageView.h"
#import "MB_SurveyView.h"
#import "MB_PollView.h"
#import "MB_LocationType.h"

#import "MB_BannerView.h"
#import "GetInboxData.h"
#import "GetBeaconsData.h"
#import "GetBeaconData.h"
#import "MB_Settings.h"
#import "DeviceLocation.h"
#import "LocationManager.h"
#import "GenderManager.h"
#import "BirthdateManager.h"
#import "CustomDataManager.h"
#import "SetToken.h"
#import "MB_Profile.h"
#import "InitApp.h"
#import "ClearHistory.h"
#import "AppTraceCodeType.h"
#import "GetTagsData.h"

@class  MobileBridgeLibrary;
@protocol MobileBridgeLibraryDelegate <NSObject>
@required
- (void)MB_LibraryInitialized:(MobileBridgeLibrary*)mbLib;
- (void)MB_SettingEventReply:(NSDictionary*)response;
- (void)MB_NetworkAlertPrompt:(int)alertId;
- (void)MB_LocationUpdate:(int)position max:(int)max;
- (void)MB_UpdateCachingDataFinished;
@end

@protocol MB_ProfileDelegate <NSObject>
@required
- (void)MB_GetProfileReply:(NSString*)data;
- (void)MB_SetProfileReply:(NSString*)data;
@end

// Inbox Data Delegate
@protocol MB_GetInboxDataDelegate <NSObject>
@required
- (void)MB_GetInboxDataFinished:(MB_InboxActionType)identifyer data:(NSDictionary*)data;
@end

// Rich Message Data Delegate
@protocol MB_GetRichMessageDataDelegate <NSObject>
@required
- (void)MB_GetRichMessageDataFinished:(NSDictionary*)data;
- (void)MB_GetAllRichMessagesFinished:(NSArray*)data;
@end

// Text Message Data Delegate
@protocol MB_GetSimpleMessageDataDelegate <NSObject>
@required
- (void)MB_GetSimpleMessageDataFinished:(NSDictionary*)message;
@end

// video Data Delegate
@protocol MB_GetVideoDataDelegate <NSObject>
@required
- (void)MB_GetVideoDataFinished:(NSDictionary*)data;
@end

// Beacons status Data Delegate
@protocol MB_GetBeaconsDataDelegate <NSObject>
@required
- (void)MB_GetBeaconsDataFinished:(MB_GetBeaconType)key data:(NSArray*)data;
@end

// Beacon Data Delegate
@protocol MB_GetBeaconDataDelegate <NSObject>
@required
- (void)MB_GetBeaconDataFinished:(NSDictionary*)data;
@end

// Banner Data Delegate
@protocol MB_GetBannerDataDelegate <NSObject>
@required
- (void)MB_GetBannerDataFinished:(NSArray*)data;
@end

// used in MB_GetPublicPromotionData API
@protocol MB_GetPublicPromotionDataDelegate <NSObject>
@required
- (void)MB_GetPublicPromotionDataFinished:(NSArray*)data;
@end

// used in MB_GetPromotionsByLocationId API
@protocol MB_GetPromotionsByLocationIdDelegate <NSObject>
@required
- (void)MB_GetPromotionsByLocationIdFinished:(NSArray*)data;
@end

// used in MB_GetLocationsByPromotionId API
@protocol MB_GetLocationsByPromotionIdDelegate <NSObject>
@required
- (void)MB_GetLocationsByPromotionIdFinished:(NSArray*)data;
@end

// Gallery Data Delegate
@protocol MB_GetGalleryDataDelegate <NSObject>
@required
- (void)MB_GetGalleryDataFinished:(NSDictionary*)data;
@end

// Points Data Delegate
@protocol MB_PointsDataDelegate <NSObject>
@required
- (void)MB_PointsDataReceived:(NSString*)identifyer data:(NSDictionary*)data;
- (void)MB_PointsHistoryReceived:(NSString*)identifyer data:(NSArray*)data;
@end

// CMS Logo Data Delegate
@protocol MB_CMSLogoDelegate <NSObject>
@required
- (void)MB_CMSLogoReceived:(NSDictionary*)data;
@end

// used in MB_GetTagsData API
@protocol MB_GetTagsDelegate <NSObject>
@required
- (void)MB_GetTagsDataFinished:(TagsType)tagType data:(NSArray*)data;
@end

// Update caching Data Delegate
@protocol MB_UpdateCachingDataDelegate <NSObject>
@required
- (void)MB_UpdateCachingDataFinished;
@end


typedef enum
{
    _active = 0,
    _used = 1,
    _expired = 2
}SavedPromotionType;

typedef enum
{
    _join_test_group = 0,
    _leave_test_group = 1
}TestGroupType;


@interface MobileBridgeLibrary : NSObject <MB_SettingsDelegate, DeviceLocationDelegate, LocationManagerDelegate, SetTokenDelegate, ProfileDelegate, InitAppDelegate, ClearHistoryDelegate, GetInboxDataDelegate>
{
    __weak id <MobileBridgeLibraryDelegate> delegate;
    __weak id <MB_ProfileDelegate> profileDelegate;
    __weak id <MB_GetInboxDataDelegate> getInboxDataDelegate;
    __weak id <MB_GetBannerDataDelegate> getBannerDataDelegate;
    __weak id <MB_GetRichMessageDataDelegate> getRichMessageDataDelegate;
    __weak id <MB_GetGalleryDataDelegate> getGalleryDataDelegate;
    __weak id <MB_GetSimpleMessageDataDelegate> getSimpleMessageDataDelegate;
    __weak id <MB_GetVideoDataDelegate> getVideoDataDelegate;
    __weak id <MB_GetBeaconsDataDelegate> getBeaconsDataDelegate;
    __weak id <MB_GetBeaconDataDelegate> getBeaconDataDelegate;
    __weak id <MB_PointsDataDelegate> pointsDataDelegate;
    __weak id <MB_PointsDataDelegate> pointsHistoryDataDelegate;
    __weak id <MB_GetPublicPromotionDataDelegate> getPublicPromotionDataDelegate;
    __weak id <MB_GetPromotionsByLocationIdDelegate> getPromotionByLocationIdDelegate;
    __weak id <MB_GetLocationsByPromotionIdDelegate> getLocationByPromotionIdDelegate;
    __weak id <MB_UpdateCachingDataDelegate> updateCachingDelegate;
    __weak id <MB_GetTagsDelegate> getTagsDelegate;
    __weak id <MB_CMSLogoDelegate> getCMSLogoDelegate;
    
}
@property (weak) id <MobileBridgeLibraryDelegate> delegate;
@property (weak) id <MB_ProfileDelegate> profileDelegate;
@property (weak) id <MB_GetInboxDataDelegate> getInboxDataDelegate;
@property (weak) id <MB_GetBannerDataDelegate> getBannerDataDelegate;
@property (weak) id <MB_GetRichMessageDataDelegate> getRichMessageDataDelegate;
@property (weak) id <MB_GetGalleryDataDelegate> getGalleryDataDelegate;
@property (weak) id <MB_GetSimpleMessageDataDelegate> getSimpleMessageDataDelegate;
@property (weak) id <MB_GetVideoDataDelegate> getVideoDataDelegate;
@property (weak) id <MB_GetBeaconsDataDelegate> getBeaconsDataDelegate;
@property (weak) id <MB_GetBeaconDataDelegate> getBeaconDataDelegate;
@property (weak) id <MB_PointsDataDelegate> pointsDataDelegate;
@property (weak) id <MB_PointsDataDelegate> pointsHistoryDataDelegate;
@property (weak) id <MB_GetPublicPromotionDataDelegate> getPublicPromotionDataDelegate;
@property (weak) id <MB_GetPromotionsByLocationIdDelegate> getPromotionByLocationIdDelegate;
@property (weak) id <MB_GetLocationsByPromotionIdDelegate> getLocationByPromotionIdDelegate;
@property (weak) id <MB_UpdateCachingDataDelegate> updateCachingDelegate;
@property (weak) id <MB_GetTagsDelegate> getTagsDelegate;
@property (weak) id <MB_CMSLogoDelegate> getCMSLogoDelegate;

// Initiate the library
+(BOOL)MB_InitLibrary:(NSString*)clientKey clientSecret:(NSString*)clientSecret delegate:(id <MobileBridgeLibraryDelegate>)delegate;

// Set Phone Token
-(void)MB_SetToken:(NSString*)pToken type:(PushType)type;

// Promotion View
-(MB_BannerView*)MB_BannerViewWithFrame:(CGRect)frame;

// InboxView
-(void)MB_GetInboxData:(MB_InboxActionType)inboxAction inboxId:(NSString*)_inboxId delegate:(id <MB_GetInboxDataDelegate>)_delegate;

// richmessage
-(void)MB_GetRichMessageData:(NSDictionary*)_assetInfo delegate:(id <MB_GetRichMessageDataDelegate>)_delegate;
-(void)MB_GetAllRichMessages:(id <MB_GetRichMessageDataDelegate>)_delegate;

// text message
-(void)MB_GetSimpleMessageData:(NSDictionary*)_assetInfo delegate:(id <MB_GetSimpleMessageDataDelegate>)_delegate;

// video
-(void)MB_GetVideoData:(NSDictionary*)_assetInfo delegate:(id <MB_GetVideoDataDelegate>)_delegate;

// beacons data
-(void)MB_GetBeaconsData:(MB_GetBeaconType)getBeaconType delegate:(id <MB_GetBeaconsDataDelegate>)_delegate;
-(void)MB_GetBeaconData:(int)major minor:(int)minor delegate:(id <MB_GetBeaconDataDelegate>)_delegate;

// ProfileView
-(void)MB_GetProfileData:(id<MB_ProfileDelegate>)_delegate;

// Settings / Set
-(void)MB_SetNotificationEnabled:(BOOL)status delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert; // default status = TRUE
-(void)MB_SetTimeReminderEnabled:(BOOL)status delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert; // default status = TRUE
-(void)MB_SetTimeReminderInterval:(TimeReminderType)alarmInterval delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert; // default status = TRUE
-(void)MB_SetLocationReminderEnabled:(BOOL)status delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert; // default status = TRUE
-(void)MB_SetBeaconReminderEnabled:(BOOL)status delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert;
-(BOOL)MB_GetBeaconStatus;

// Settings / Get
-(BOOL)MB_GetNotificationStatus;

-(BOOL)MB_GetTimeReminderStatus;
-(TimeReminderType)MB_GetTimeReminderInterval;

-(BOOL)MB_GetLocationReminderStatus;
//-(LocationReminderType)MB_GetLocationReminderRadius;

-(NSString*)MB_GetLibraryVersion; // get library version

-(BOOL)MB_SetProfileValue:(NSNumber*)value forKey:(NSString*)key;
-(BOOL)MB_SendProfileUpdate;
//-(void)MB_ClearProfileData;

// view TraceLog
-(BOOL)MB_ViewTraceLog_Start:(NSString*)key code:(AppTraceCodeType*)pCode;
-(BOOL)MB_ViewTraceLog_Stop:(NSString*)key code:(AppTraceCodeType*)pCode;
// click TraceLog
-(BOOL)MB_ClickTraceLog:(NSString*)key;
// app traceLog
-(BOOL)MB_AppTraceLog_Start:(AppTraceCodeType*)pCode;
-(BOOL)MB_AppTraceLog_Stop:(AppTraceCodeType*)pCode;

-(void)MB_SetColorTemplate:(NSArray*)pColorArray;

-(BOOL)MB_SetGender:(GenderType)gender;
-(GenderType)MB_GetGender;
-(BOOL)MB_SetDateOfBirth:(long)utcDate;
-(long)MB_GetDateOfBirth;

-(BOOL)MB_SetCustomData:(CustomDataType)_type data:(NSString*)_data;
-(NSString*)MB_GetCustomData:(CustomDataType)_type;

-(BOOL)MB_SetScanValue:(NSString*)scanValue; // set the activation_code or trigger_code and pass it to the message center

//Set/Get Member flag
-(BOOL)MB_SetMemberFlag:(BOOL)_memberFlag;
-(BOOL)MB_GetMemberFlag;

-(NSString*)MB_GetDeviceId;
-(NSString*)MB_GetServerUrl;
-(void)MB_SetApplicationName:(NSString*)applicationName;

-(void)MB_ClearUserHistory;

-(void)MB_GetTagsData:(TagsType)tagType delegate:(id <MB_GetTagsDelegate>)_delegate;

-(NSArray*)MB_GetSavedPromotionArray:(SavedPromotionType)savePromotionType;
-(BOOL)MB_DeleteSavedPromotion:(int)promotionId;
-(void)MB_DeleteAllSavedPromotions:(SavedPromotionType)savePromotionType;

-(void)MB_CustomTriggerEvent;
-(void)MB_TapEvent:(int)major minor:(int)minor;

-(void)MB_GetBannerData:(NSString*)tag delegate:(id <MB_GetBannerDataDelegate>)_delegate;
-(void)MB_GetGalleryData:(NSDictionary*)_assetInfo delegate:(id <MB_GetGalleryDataDelegate>)_delegate;
-(void)MB_PrintSQSMessages:(BOOL)status;

-(BOOL)MB_GetNetworkStatus;
-(void)MB_UpdateLocations;
-(void)MB_UpdateCachedAssets:(BOOL)updateLocations delegate:(id <MB_UpdateCachingDataDelegate>)_delegate;

-(void)MB_GetPublicPromotionData:(id <MB_GetPublicPromotionDataDelegate>)_delegate;
-(void)MB_GetPromotionsByLocationId:(int)locationId delegate:(id <MB_GetPromotionsByLocationIdDelegate>)_delegate;
-(void)MB_GetLocationsByPromotionId:(NSDictionary*)pPromotionId delegate:(id <MB_GetLocationsByPromotionIdDelegate>)_delegate;
-(NSArray*)MB_GetAllLocations;

// points
-(void)MB_GetPoints:(id <MB_PointsDataDelegate>)_delegate;
-(void)MB_SetPoints:(id <MB_PointsDataDelegate>)_delegate points:(int)points category:(NSString*)category reason:(NSString*)reason;
-(void)MB_GetPointsHistory:(id <MB_PointsDataDelegate>)_delegate;
-(void)MB_CustomPointEvent:(NSString*)eventkey;

// TestGroup
-(void)MB_TestGroup:(TestGroupType)event firstname:(NSString*)firstname lastname:(NSString*)lastname;
-(void)MB_GetCMSLogo:(id <MB_CMSLogoDelegate>)_delegate;

-(NSDictionary*)MB_GetScannerResult:(NSString*)result;

@end
