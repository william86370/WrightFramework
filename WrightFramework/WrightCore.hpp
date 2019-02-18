//
//  WrightCore.hpp
//  WrightFramework
//
//  Created by william wright on 2/18/19.
//  Copyright © 2019 Silvertap. All rights reserved.
//  WrightCore Provides Native Functions and Classes For C++ and WrightFramework

#ifndef WrightCore_hpp
#define WrightCore_hpp
#include "WrightNetworking.hpp"
#include "WrightCryptography.hpp"
#include <sys/utsname.h>
#include <sstream>
#endif /* WrightCore_hpp */
utsname GetSystemInformation();
void GetCurrentTime();
std::string RunCommand(const char* cmd);
