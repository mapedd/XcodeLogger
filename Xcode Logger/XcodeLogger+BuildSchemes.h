//
//  XcodeLogger+BuildSchemas.h
//
//  Created by Razvan Tanase on 30/06/15.
//  Copyright (c) 2015 Codebringers Software Inc. All rights reserved.
//
//  Version 0.1

#import "XcodeLogger.h"

// !!!: CHECK THAT THE FOLLOWING CONSTANT MATCHES THE KEY IN YOUR INFO.PLIST FILE
static NSString *const key_RUNNING_SCHEME = @"RunningScheme";

// TODO: CHANGE THE CONSTANTS TO MATCH YOUR SCHEMES
static NSString *const DEBUG_SCHEME        = @"XL-Sample DEBUG";//CHANGE
static NSString *const DEVELOPMENT_SCHEME  = @"XL-Sample DEVELOPMENT";//CHANGE

// ???: ADD NEWLINE AFTER EACH OUTPUT?
static BOOL kLOGS_SHOULD_ADD_NEWLINE_AFTER_OUTPUT = YES;

// !!!: FLAGS TO CHECK AT RUNTIME IF NEEDED
extern BOOL DEBUG_MODE_ON;
extern BOOL DEVELOPMENT_MODE_ON;

//TYPES OF LOGGERS
typedef NS_ENUM(short, LOGGERTYPE) {
    LOGGERTYPE_DLog,
    LOGGERTYPE_DLog_NH,
    LOGGERTYPE_DLog_INFO,
    LOGGERTYPE_DLog_HIGHLIGHT,
    LOGGERTYPE_DLog_WARNING,
    LOGGERTYPE_DLog_ERROR,
    
    LOGGERTYPE_DEVLog,
    LOGGERTYPE_DEVLog_NH,
    LOGGERTYPE_DEVLog_INFO,
    LOGGERTYPE_DEVLog_HIGHLIGHT,
    LOGGERTYPE_DEVLog_WARNING,
    LOGGERTYPE_DEVLog_ERROR,
    
    LOGGERTYPE_DDVLog,
    LOGGERTYPE_DDVLog_NH,
    LOGGERTYPE_DDVLog_INFO,
    LOGGERTYPE_DDVLog_HIGHLIGHT,
    LOGGERTYPE_DDVLog_WARNING,
    LOGGERTYPE_DDVLog_ERROR,
};


@interface XcodeLogger (BuildSchemes)
void funcXLSchemaLogOutput (NSString *format, ...);
NSString *logTypeOutput (LOGGERTYPE lType);
NSString *logFormatOutput (LOGGERTYPE lType);
@end


#pragma mark - Headers Colors
#define kLOGTYPE_COLOR_INFO      @"fg204,0,204;"
#define kLOGTYPE_COLOR_HIGHLIGHT @"fg0,122,22;"
#define kLOGTYPE_COLOR_WARNING   @"fg255,98,0;"
#define kLOGTYPE_COLOR_ERROR     @"fg255,0,0;"

#pragma mark - DDVLog - DEBUG & DEVELOPMENT LOG
//DDVLog - DEBUG & DEVELOPMENT LOG
#define DDVLog(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_NO_HIGHLIGHT s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DDVLog), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//DDVLOG NO HEADER
#define DDVLog_NH(s, ...) funcXLSchemaLogOutput(@"%@", XCODE_COLORS_ESCAPE kTEXT_COLOR_NO_HIGHLIGHT s XCODE_COLORS_RESET, logTypeOutput(LOGGERTYPE_DDVLog_NH))

//DDVLOG INFO
#define DDVLog_INFO(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_INFO \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_INFO s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DDVLog_INFO), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//DDVLOG HIGHLIGHT
#define DDVLog_HIGHLIGHT(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_HIGHLIGHT \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_HIGHLIGHT s XCODE_COLORS_RESET, \
\
logTypeOutput(LOGGERTYPE_DDVLog_HIGHLIGHT), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//DDVLOG WARNING
#define DDVLog_WARNING(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_WARNING \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_WARNING s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DDVLog_WARNING), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//DDVLOG ERROR
#define DDVLog_ERROR(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_ERROR \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_ERROR s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DDVLog_ERROR), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

#pragma mark - DLog - DEBUG ONLY LOG
//DLog - DEBUG ONLY LOG
#define DLog(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_NO_HIGHLIGHT s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DLog), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//DLOG NO HEADER
#define DLog_NH(s, ...) funcXLSchemaLogOutput(@"%@", XCODE_COLORS_ESCAPE kTEXT_COLOR_NO_HIGHLIGHT s XCODE_COLORS_RESET)

//DLOG INFO
#define DLog_INFO(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_INFO \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_INFO \
\
s  \
\
XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DLog_INFO), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__,\
__PRETTY_FUNCTION__,\
##__VA_ARGS__])

//DLOG HIGHLIGHT
#define DLog_HIGHLIGHT(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_HIGHLIGHT \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_HIGHLIGHT \
\
s  \
\
XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DLog_HIGHLIGHT), \
timeStamp(),\
self,\
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__,\
__PRETTY_FUNCTION__,\
##__VA_ARGS__])

//DLOG WARNING
#define DLog_WARNING(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_WARNING \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_WARNING \
\
s  \
\
XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DLog_WARNING), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//DLOG ERROR
#define DLog_ERROR(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_ERROR \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_ERROR \
\
s  \
\
XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DLog_ERROR), \
timeStamp(),\
self,\
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__,\
__PRETTY_FUNCTION__,\
##__VA_ARGS__])


#pragma mark - DEVLog - DEVELOPMENT ONLY LOG
//DEVLog - DEVELOPMENT ONLY LOG
#define DEVLog(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_NO_HIGHLIGHT s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DEVLog), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//DEVLOG NO HEADER
#define DEVLog_NH(s, ...) funcXLSchemaLogOutput(@"%@", XCODE_COLORS_ESCAPE kTEXT_COLOR_NO_HIGHLIGHT s XCODE_COLORS_RESET,logTypeOutput(LOGGERTYPE_DEVLog_NH))

//DEVLOG INFO
#define DEVLog_INFO(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_INFO \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_INFO s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DEVLog_INFO), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//DEVLOG HIGHLIGHT
#define DEVLog_HIGHLIGHT(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_HIGHLIGHT \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_HIGHLIGHT s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DEVLog_HIGHLIGHT), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//DEVLOG WARNING
#define DEVLog_WARNING(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_WARNING \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_WARNING s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DEVLog_WARNING), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])


//DEVLOG ERROR
#define DEVLog_ERROR(s, ...) funcXLSchemaLogOutput(@"%@", \
[NSString stringWithFormat:@"[%@](%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_ERROR \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_ERROR s XCODE_COLORS_RESET, \
logTypeOutput(LOGGERTYPE_DEVLog_ERROR), \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])