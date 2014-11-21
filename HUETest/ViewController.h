//
//  ViewController.h
//  HUETest
//
//  Created by yenkai huang on 2014/11/19.
//  Copyright (c) 2014年 yenkai huang. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "DLog.h"

#import "PHBridgePushLinkViewController.h"
#import <HueSDK_iOS/HueSDK.h>

@interface ViewController : UIViewController<PHBridgePushLinkViewControllerDelegate>

@property (strong, nonatomic) PHHueSDK *phHueSDK;

@end

