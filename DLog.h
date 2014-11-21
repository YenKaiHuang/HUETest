//
//  DLog.h
//  Symphony
//
//  Created by smpuser on 2014/9/2.
//  Copyright (c) 2014年 JimmyDai. All rights reserved.
//

#import "FileLog.h"

#define DEBUG_MODE 1

#if(DEBUG_MODE)
#define DLog( s, ... ) \
    NSLog( @"<%@:(%d)> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] ); \
    [[FileLog sharedInstance] log:@"<%@:(%d)> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__]]
#else
#define DLog( s, ... )
#endif

#define Microsecond(code) \
double t1 = [[NSDate date] timeIntervalSince1970];\
code;\
double t2 = [[NSDate date] timeIntervalSince1970];\
DLog(@"%f", t2 - t1)