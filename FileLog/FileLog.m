//
//  FileLog.m
//  FileLogger
//
//  Created by yenkai huang on 2014/10/16.
//  Copyright (c) 2014年 yenkai huang. All rights reserved.
//

#import "FileLog.h"

@implementation FileLog

- (id) init {
    if (self == [super init]) {
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *documentsDirectory = [paths objectAtIndex:0];
        NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"APP.log"];
        NSFileManager *fileManager = [NSFileManager defaultManager];
        if (![fileManager fileExistsAtPath:filePath]) {
            [fileManager createFileAtPath:filePath
                                 contents:nil
                               attributes:nil];
        }
        logFile = [NSFileHandle fileHandleForWritingAtPath:filePath];
        [logFile seekToEndOfFile];
    }
    
    return self;
}

- (void)log:(NSString *)format, ... {
    va_list ap;
    va_start(ap, format);
    
    NSString *message = [[NSString alloc] initWithFormat:format arguments:ap];
//    [logFile writeData:[[message stringByAppendingString:@"\n"] dataUsingEncoding:NSUTF8StringEncoding]];
//    [logFile synchronizeFile];
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"APP.log"];
    NSFileHandle* wFile = [NSFileHandle fileHandleForWritingAtPath:filePath];
    [wFile seekToEndOfFile];
    [wFile writeData:[[message stringByAppendingString:@"\n"] dataUsingEncoding:NSUTF8StringEncoding]];
    [wFile closeFile];
}

+ (FileLog *)sharedInstance {
    static FileLog *instance = nil;
    if (instance == nil) instance = [[FileLog alloc] init];
    return instance;
}

@end
