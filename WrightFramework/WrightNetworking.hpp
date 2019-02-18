//
//  WrightNetworking.hpp
//  WrightFramework
//
//  Created by william wright on 2/13/19.
//  Copyright © 2019 Silvertap. All rights reserved.
//

#ifndef WrightNetworking_hpp
#define WrightNetworking_hpp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#define MAXLEN 1024
#endif /* WrightNetworking_hpp */
using namespace std;
struct ConnectionInfo{
    int socket;
    struct sockaddr_in address;
    socklen_t len;
};
class WrightNetworking{
public:
    void DieOnError(string error);
    int Createipv4TCPServer(int PORT);
    int ipv4TCPClientSocket(char *IPAddress,int PORT);
    int ipv4TCPServerSocket(int PORT);
    int ipv6TCPClientSocket(char *IPAddress,int PORT);
    int ipv6TCPServerSocket(int PORT);
    int ipv4UDPClientSocket(char *IPAddress,int PORT);
    int ipv4UDPServerSocket(int PORT);
    int ipv6UDPClientSocket(char *IPAddress,int PORT);
    int ipv6UDPServerSocket(int PORT);
    int bindsocket();
    int ListenSocket();
    int ConnectSocket();
    int AcceptSocket();
    long ReadData(char bufferin[MAXLEN]);
    void SendData(char Data[MAXLEN]);
    char* GetBuffer();
    ConnectionInfo GetHostConnectionDetails();
    ConnectionInfo GetClientConnectionDetails();
private:
    int networkingsocket;//our socket for the class
    int clientSocket;//for server to out client details
    struct sockaddr_in clientaddress;
    int ipvtype;//soon
    int networkingtype;
    struct sockaddr_in address;
    char buffer[MAXLEN];
    int addrlen;
    socklen_t len;
    const int on = 1;
    struct sockaddr_in cliaddr, servaddr;
    
};
