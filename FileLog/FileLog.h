//
//  FileLog.h
//  FileLogger
//
//  Created by yenkai huang on 2014/10/16.
//  Copyright (c) 2014年 yenkai huang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FileLog : NSObject{
    NSFileHandle *logFile;
}

/**
 * @brief FileLog sharedInstance
 * @return class FileLog
 */
+ (FileLog *)sharedInstance;

/**
 * @brief log string and save to App.log
 * @param format the string be saved to App.log
 */
- (void)log:(NSString *)format, ...;

@end
