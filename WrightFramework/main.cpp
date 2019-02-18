//
//  main.cpp
//  WrightFramework
//
//  Created by william wright on 2/13/19.
//  Copyright © 2019 Silvertap. All rights reserved.
//

#include "WrightCore.hpp"//include WrightFramwork With WrightNetworking and WrightCrypto

int main(int argc, const char * argv[]) {
    //Define Varables
    char HostIpAddress[] = "192.168.1.1";
    //Init the Wright Framework Classes
    WrightNetworking ClientNetworking;
    WrightCryptography ClientCrypto;
    //Make the network socket
    ClientNetworking.ipv4TCPClientSocket(HostIpAddress,25565);
    //Send the Init to the Host for processing
    FirstConnect(ClientNetworking,ClientCrypto);
    //Recieve Data From the Host And Process Data
    
    //Create Watchdog Daemon To make sure Logging Client Isnt Ever Closed
    
    //Start Logging Data From Client
    StartLogging();
    return 0;
}
