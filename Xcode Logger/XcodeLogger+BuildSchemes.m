//
//  XcodeLogger+BuildSchemas.m
//
//  Created by Razvan Tanase on 30/06/15.
//  Copyright (c) 2015 Codebringers Software Inc. All rights reserved.
//

#import "XcodeLogger+BuildSchemes.h"

BOOL DEBUG_MODE_ON = NO;
BOOL DEVELOPMENT_MODE_ON = NO;

LOGGERTYPE logType;

@implementation XcodeLogger (BuildSchemes)

void funcXLSchemaLogOutput (NSString *format, ...) {
    
    //case-insensitive (all uppercase trick) search for the currently running scheme
    NSString *currentSchema = [(NSString *)[[[NSBundle mainBundle] infoDictionary] valueForKey:key_RUNNING_SCHEME] uppercaseString];
    
    if ([DEBUG_SCHEME.uppercaseString isEqualToString:currentSchema]) {
        DEBUG_MODE_ON = YES;
    } else if ([DEVELOPMENT_SCHEME.uppercaseString isEqualToString:currentSchema]) {
        DEVELOPMENT_MODE_ON = YES;
    }
        
    BOOL showOutput = NO;
    
    if (DEBUG_MODE_ON) {
        switch (logType) {
            case LOGGERTYPE_DLog:
                showOutput = YES;
                break;
            case LOGGERTYPE_DLog_NH:
                showOutput = YES;
                break;
            case LOGGERTYPE_DLog_INFO:
                showOutput = YES;
                break;
            case LOGGERTYPE_DLog_HIGHLIGHT:
                showOutput = YES;
                break;
            case LOGGERTYPE_DLog_WARNING:
                showOutput = YES;
                break;
            case LOGGERTYPE_DLog_ERROR:
                showOutput = YES;
                break;
                
            default:
                showOutput = NO;
                break;
        }
    }
    
    if (DEVELOPMENT_MODE_ON) {
        switch (logType) {
            case LOGGERTYPE_DEVLog:
                showOutput = YES;
                break;
            case LOGGERTYPE_DEVLog_NH:
                showOutput = YES;
                break;
            case LOGGERTYPE_DEVLog_INFO:
                showOutput = YES;
                break;
            case LOGGERTYPE_DEVLog_HIGHLIGHT:
                showOutput = YES;
                break;
            case LOGGERTYPE_DEVLog_WARNING:
                showOutput = YES;
                break;
            case LOGGERTYPE_DEVLog_ERROR:
                showOutput = YES;
                break;
                
            default:
                showOutput = NO;
                break;
        }
    }
    
    
    if (DEBUG_MODE_ON || DEVELOPMENT_MODE_ON) {
        switch (logType) {
            case LOGGERTYPE_DDVLog:
                showOutput = YES;
                break;
            case LOGGERTYPE_DDVLog_NH:
                showOutput = YES;
                break;
            case LOGGERTYPE_DDVLog_INFO:
                showOutput = YES;
                break;
            case LOGGERTYPE_DDVLog_HIGHLIGHT:
                showOutput = YES;
                break;
            case LOGGERTYPE_DDVLog_WARNING:
                showOutput = YES;
                break;
            case LOGGERTYPE_DDVLog_ERROR:
                showOutput = YES;
                break;
            default:
                break;
        }
    }
    
    if (showOutput) {
        va_list args;
        va_start(args, format);
        
        if (kLOGS_SHOULD_ADD_NEWLINE_AFTER_OUTPUT) {
            //add a new line after the output
            format = [format stringByAppendingString:@"\n"];
        }
        
        format = [format stringByAppendingString:@"\n"];
        //output the log
        fputs([[[NSString alloc] initWithFormat:format arguments:args] UTF8String], stdout);
        
        va_end(args);
    }
}

NSString *logFormatOutput (LOGGERTYPE lType) {
    //to be continued..
    return nil;
}

NSString *logTypeOutput (LOGGERTYPE lType) {
    
    logType = lType;
    
    switch (lType) {
        case LOGGERTYPE_DLog:
            return [NSString stringWithFormat:@"DEBUG"];
            break;
        case LOGGERTYPE_DLog_INFO:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_INFO @"DEBUG:INFO" XCODE_COLORS_RESET];
            break;
        case LOGGERTYPE_DLog_HIGHLIGHT:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_HIGHLIGHT @"DEBUG:STATUS" XCODE_COLORS_RESET];
            break;
        case LOGGERTYPE_DLog_WARNING:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_WARNING @"DEBUG:WARNING" XCODE_COLORS_RESET];
            break;
        case LOGGERTYPE_DLog_ERROR:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_ERROR @"DEBUG:ERROR" XCODE_COLORS_RESET];
            break;
            
        case LOGGERTYPE_DEVLog:
            return [NSString stringWithFormat:@"DEVELOPMENT"];
            break;
        case LOGGERTYPE_DEVLog_INFO:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_INFO @"DEVELOPMENT:INFO" XCODE_COLORS_RESET];
            break;
        case LOGGERTYPE_DEVLog_HIGHLIGHT:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_HIGHLIGHT @"DEVELOPMENT:STATUS" XCODE_COLORS_RESET];
            break;
        case LOGGERTYPE_DEVLog_WARNING:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_WARNING @"DEVELOPMENT:WARNING" XCODE_COLORS_RESET];
            break;
        case LOGGERTYPE_DEVLog_ERROR:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_ERROR @"DEVELOPMENT:ERROR" XCODE_COLORS_RESET];
            break;
            
        case LOGGERTYPE_DDVLog:
            return [NSString stringWithFormat:@"DBG&DEV"];
            break;
        case LOGGERTYPE_DDVLog_INFO:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_INFO @"DBG&DEV:INFO" XCODE_COLORS_RESET];
            break;
        case LOGGERTYPE_DDVLog_HIGHLIGHT:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_HIGHLIGHT @"DBG&DEV:STATUS" XCODE_COLORS_RESET];
            break;
        case LOGGERTYPE_DDVLog_WARNING:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_WARNING @"DBG&DEV:WARNING" XCODE_COLORS_RESET];
            break;
        case LOGGERTYPE_DDVLog_ERROR:
            return [NSString stringWithFormat:XCODE_COLORS_ESCAPE kLOGTYPE_COLOR_ERROR @"DBG&DEV:ERROR" XCODE_COLORS_RESET];
            break;
            
        default:
            break;
    }
    return nil;
}
@end
