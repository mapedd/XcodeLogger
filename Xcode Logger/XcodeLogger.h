//
//  XcodeLogger.h
//
//  Created by Razvan Tanase on 29/06/15.
//  Copyright (c) 2015 Codebringers Software Inc. All rights reserved.
//
//  Version 0.1

#import <Foundation/Foundation.h>

// !!!: CHANGE THE TIMESTAMP FORMAT IF NEEDED
static NSString *const kTIMESTAMP_FORMAT = @"HH:mm:ss";

// ???: ADD NEWLINE AFTER EACH OUTPUT?
static BOOL kXLOG_SHOULD_ADD_NEWLINE_AFTER_OUTPUT = YES;

// CHANGE COLORS: RGB FORMAT (fg: text / bg: background)
#pragma mark - COLORS
//default log color
#pragma mark DEFAULT Log Color
#define kTEXT_COLOR_NO_HIGHLIGHT @"fg0,0,255;"

//text & backgroud colors for INFO Log
#pragma mark INFO Log Color
#define kTEXT_COLOR_INFO      @"fg255,255,255;"
#define kBGND_COLOR_INFO      @"bg204,0,204;"

//text & backgroud colors for HIGHLIGHT Log
#pragma mark HIGHLIGHT Log Color
#define kTEXT_COLOR_HIGHLIGHT @"fg255,255,255;"
#define kBGND_COLOR_HIGHLIGHT @"bg0,102,51;"

//text & backgroud colors for WARNING Log
#pragma mark WARNING Log Color
#define kTEXT_COLOR_WARNING   @"fg0,0,0;"
#define kBGND_COLOR_WARNING   @"bg255,255,0;"

//text & backgroud colors for ERROR Log
#pragma mark ERROR Log Color
#define kTEXT_COLOR_ERROR     @"fg255,255,255;"
#define kBGND_COLOR_ERROR     @"bg255,0,0;"
#pragma mark -


@interface XcodeLogger : NSObject
void funcXLogOutput (NSString *format, ...);
NSString *timeStamp(void);
@end


#pragma mark - XLOG
#define XLog(s, ...) funcXLogOutput(@"%@", \
[NSString stringWithFormat:@"(%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE kTEXT_COLOR_NO_HIGHLIGHT s XCODE_COLORS_RESET, \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//XLog NO HEADER
#define XLog_NH(s, ...) funcXLogOutput(@"%@",XCODE_COLORS_ESCAPE kTEXT_COLOR_NO_HIGHLIGHT s XCODE_COLORS_RESET)

//XLog INFO
#define XLog_INFO(s, ...) funcXLogOutput(@"%@", \
[NSString stringWithFormat:@"(%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_INFO \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_INFO s XCODE_COLORS_RESET, \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//XLog HIGHLIGHT
#define XLog_HIGHLIGHT(s, ...) funcXLogOutput(@"%@", \
[NSString stringWithFormat:@"(%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_HIGHLIGHT \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_HIGHLIGHT s XCODE_COLORS_RESET, \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//XLog WARNING
#define XLog_WARNING(s, ...) funcXLogOutput(@"%@", \
[NSString stringWithFormat:@"(%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_WARNING \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_WARNING s XCODE_COLORS_RESET, \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

//XLog ERROR
#define XLog_ERROR(s, ...) funcXLogOutput(@"%@", \
[NSString stringWithFormat:@"(%@)=> [>%p<]:%@:[#%d]:[> %s <]\n" \
XCODE_COLORS_ESCAPE \
kTEXT_COLOR_ERROR \
XCODE_COLORS_ESCAPE \
kBGND_COLOR_ERROR s XCODE_COLORS_RESET, \
timeStamp(), \
self, \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__PRETTY_FUNCTION__, \
##__VA_ARGS__])

#pragma mark - TIME MEASUREMENT WRAPPER
#define TICK NSDate *startTime = [NSDate date]
#define TICK_RESET startTime = [NSDate date]
#define TOCK XLog_INFO(@"Elapsed Time For < %@ > Operation: %f", \
NSStringFromSelector(_cmd), \
-[startTime timeIntervalSinceNow])

#pragma mark - XCODE COLORS PLUGIN RELATED
#define XCODE_COLORS_ESCAPE_MAC @"\033["
#define XCODE_COLORS_ESCAPE_IOS @"\xC2\xA0["

#if TARGET_OS_IPHONE
#define XCODE_COLORS_ESCAPE  XCODE_COLORS_ESCAPE_IOS
#else
#define XCODE_COLORS_ESCAPE  XCODE_COLORS_ESCAPE_MAC
#endif

#define XCODE_COLORS_RESET_FG  XCODE_COLORS_ESCAPE @"fg;" // Clear any foreground color
#define XCODE_COLORS_RESET_BG  XCODE_COLORS_ESCAPE @"bg;" // Clear any background color
#define XCODE_COLORS_RESET     XCODE_COLORS_ESCAPE @";"   // Clear any foreground or background color

