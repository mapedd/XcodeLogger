#Xcode Logger

Xcode Logger `version 0.1` is a simple and colorful console output library based on the [Xcode Colors](https://github.com/robbiehanson/XcodeColors) plugin for Xcode IDE which works great in multi-threaded environments.

---
Xcode Logger is tested on iOS 7 and 8, and requires ARC. Released under the [MIT License](https://github.com/codeFi/XcodeLogger/blob/master/LICENSE).
![Xcode Colors]
(http://i62.tinypic.com/15hk5y9.png)

It has multiple schemes of logging (`macros`) with automatic log scheme switching based on the selected build schemes. It ships by default as plug-and-play for the following schemes:     
 - DEBUG
 - DEVELOPMENT
 - DEBUG and DEVELOPMENT (a common logger for both schemes)
 - RELEASE (disables every logger except `XLog` which replaces `NSLog`)

Every log scheme accounts for multiple scenarios, so there's a logging function (`macro`) for each of the following:
 - Simple logger with or without header information
 - Information logger
 - Highlight logger
 - Warning logger
 - Error logger

##How to install

1. Download or clone the repository. If you don't have `XcodeColors` plugin installed, now it's a good time to [install it](https://github.com/robbiehanson/XcodeColors).

2. After installing  and testing the `XcodeColors` plugin, add `XcodeLogger` and `XcodeLogger+BuildSchemes` category `.h` and `.m` files to your project.
![Copy Xcode Logger into your project]
(http://i60.tinypic.com/s6hb9v.jpg)

3. If you don't have any custom build schemes for your project, you should add `RELEASE`, `DEBUG` and `DEVELOPMENT` schemes or just two of them based on the same configurations. If you're new to this, be sure your schemes are running with the correct configurations even though `Xcode Logger` doesn't depend on the running config.

4. In order for the library to determine your currently running scheme you'll need to add a value for a `key` (default is `RunningScheme`) in your `info.plist` file at runtime so go to your `info.plist` file and add a key named `RunningScheme` of type `String`.
![Info.plist Key](http://i61.tinypic.com/r1c2ea.jpg)
The following script will provide that value at runtime:

		/usr/libexec/PlistBuddy -c "Set :RunningScheme \"$SCHEME_NAME\"" "$PROJECT_DIR/$INFOPLIST_FILE"		
		
	Add the script above to your every build scheme under `Build` > `Pre-actions`. Be sure to select a **target** from which to build from!
![Add the script to your schema]
(http://i61.tinypic.com/2m6vbf8.jpg)

5. Change the values of `static NSString *const DEBUG_SCHEME` and `static NSString *const DEVELOPMENT_SCHEME` string constants in `XcodeLogger+BuildSchemes.h` to match the names of your build schemes.
![Change these constants]
(http://i60.tinypic.com/2i1folh.jpg)

##How to use
You can use `Xcode Logger` by simply importing in your classes either `XcodeLogger.h` if you want only `XLog` or `XcodeLogger+BuildSchemes.h` if you want `scheme-dependant` loggers.

After you've done that you simply call the `macros` where you need them as you would do with `NSLog`.

These are the loggers:

1. `NSLog`'s replacement `XLog` which runs independently from the running scheme:
> **XLog()** - a simple logger with an information header.
**XLog_NH()** - a simple logger without a header.
**XLog_INFO()** - a general purpose information logger.
**XLog_HIGHLIGHT()** - a general purpose information and highlight logger.
**XLog_WARNING()** - a logger for special situations like warnings.
**XLog_ERROR** - a logger for errors.

2. `DLog` which is meant to run only on a `DEBUG` scheme:
> **DLog()** 
**DLog_NH()**
**DLog_INFO()**
**DLog_HIGHLIGHT()**
**DLog_WARNING()**
**DLog_ERROR()**

3. `DEVLog` which is meant to run only on a `DEVELOPMENT` scheme:
> **DEVLog()** 
**DEVLog_NH()**
**DEVLog_INFO()**
**DEVLog_HIGHLIGHT()**
**DEVLog_WARNING()**
**DEVLog_ERROR()**

4. `DDVLog` which is meant to run only on both `DEBUG` and `DEVELOPMENT` schemes:
> **DDVLog()** 
**DDVLog_NH()**
**DDVLog_INFO()**
**DDVLog_HIGHLIGHT()**
**DDVLog_WARNING()**
**DDVLog_ERROR()**

The info headers contain the following informations (in order):

( _timestamp_ )=> [> _memory address of self_ <]: _file name_ :[ _line number_ ]:[> _the method which called the logger_ <]

----

You're more than welcome to fork and improve this software!
