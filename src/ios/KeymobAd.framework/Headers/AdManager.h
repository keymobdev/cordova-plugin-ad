//
//  AdManager.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlatformAdapter.h"
#import "IPlatform.h"
#import "IAdEventListener.h"
struct KMBannerState {
    BOOL isShowing;
    BOOL isRelation;
    int sizeType;
    int xvalue;
    int yvalue;
};
typedef struct KMBannerState KMBannerState;
@interface AdManager : NSObject <IAdEventListener,IBannerPlatform,IAppWallPlatform,IInterstitialPlatform,IVideoPlatform>
@property (nonatomic,retain) id<IAdEventListener> listener;
@property (nonatomic,retain) UIViewController* controller;
-(void) configWithConfig:(BOOL) _isTesting withRateModel:(int)_model andPlatforms:(NSArray*) _items;
-(void) configWithJSON:(NSString*)jsonStr;
-(void) configWithKeymobService:(NSString*) appID isTesting:(BOOL) _testing;
//-(id) initWith:(UIViewController*) controller andListener:(id<IAdEventListener>) listener;
-(void) setController:(UIViewController*) _controller andListener:(id<IAdEventListener>) _listener;
+ (AdManager*)sharedInstance ;
@end
