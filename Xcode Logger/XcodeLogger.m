//
//  XcodeLogger.m
//
//  Created by Razvan Tanase on 29/06/15.
//  Copyright (c) 2015 Codebringers Software Inc. All rights reserved.
//

#import "XcodeLogger.h"

@implementation XcodeLogger

void funcXLogOutput (NSString *format, ...) {
    va_list args;
    va_start(args, format);
    
    if (kXLOG_SHOULD_ADD_NEWLINE_AFTER_OUTPUT) {
        format = [format stringByAppendingString:@"\n"];
    }
    
    format = [format stringByAppendingString:@"\n"];
    fputs([[[NSString alloc] initWithFormat:format arguments:args] UTF8String], stdout);
    
    va_end(args);
}

NSString *timeStamp(void) {
    NSDate *currentTime = [NSDate date];
    
    static NSDateFormatter *dateFormatter;
    
    if (!dateFormatter) {
        dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:kTIMESTAMP_FORMAT];
    }
    
    return [dateFormatter stringFromDate: currentTime];
}

@end
