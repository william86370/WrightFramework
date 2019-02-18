//
//  main.cpp
//  WrightFramework
//
//  Created by william wright on 2/13/19.
//  Copyright © 2019 Silvertap. All rights reserved.
//

#include "WrightCore.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    WrightCryptography test;
   
    struct utsname sysinfo;
    uname(&sysinfo);
    string systeminfo;
    std::stringstream ss;
    ss<<sysinfo.nodename<<","<<sysinfo.machine<<","<<sysinfo.release;
    systeminfo = ss.str();
    cout<<systeminfo<<endl;
    string buff = test.XorHMAC(systeminfo,'h','p');
    cout<<"HMAC string: "<<buff<<endl;
    string buff2 = test.XorHMAC(buff,'h','p');
    cout<<"HMAC decrypted string: "<<buff2<<endl;
    return 0;
}
