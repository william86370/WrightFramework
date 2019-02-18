//
//  WrightNetworking.cpp
//  WrightFramework
//
//  Created by william wright on 2/13/19.
//  Copyright © 2019 Silvertap. All rights reserved.
//

#include "WrightNetworking.hpp"
using namespace std;
void WrightNetworking::DieOnError(string error){
    cout<<error<<endl;
    exit(0);
}
int WrightNetworking::ipv4TCPClientSocket(char *IPAddress,int PORT){
    if ((networkingsocket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed To Create");
        return 0;
    }
    address.sin_family = AF_INET;
    if(inet_pton(AF_INET, IPAddress, &address.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    address.sin_port = htons(PORT);
    networkingtype=2;
    return 1;
}
int WrightNetworking::ipv4TCPServerSocket(int PORT){
    if ((networkingsocket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed To Create");
        return 0;
    }
     memset(&address, 0, sizeof(address));   /* Zero out structure */
    address.sin_family = AF_INET;//ipv4
    address.sin_addr.s_addr = INADDR_ANY;//any incoming address
    address.sin_port = htons(PORT);//set port
    networkingtype=1;
    return 1;
}
int WrightNetworking::ipv6TCPClientSocket(char *IPAddress,int PORT){
    if ((networkingsocket = socket(AF_INET6, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed To Create");
        return 0;
    }
    address.sin_family = AF_INET6;//ipv6
    if(inet_pton(AF_INET6, IPAddress, &address.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    address.sin_port = htons(PORT);//set port
    networkingtype=2;
    return 1;
}
int WrightNetworking::ipv6TCPServerSocket(int PORT){
    if ((networkingsocket = socket(AF_INET6, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed To Create");
        return 0;
    }
    address.sin_family = AF_INET6;//ipv4
    address.sin_addr.s_addr = INADDR_ANY;//any incoming address
    address.sin_port = htons(PORT);//set port
    networkingtype=1;
    return 1;
}
int WrightNetworking::ipv4UDPClientSocket(char *IPAddress,int PORT){
    if ((networkingsocket = socket(AF_INET, SOCK_DGRAM, 0)) == 0)
    {
        perror("Socket failed To Create");
        return 0;
    }
    address.sin_family = AF_INET;
    if(inet_pton(AF_INET, IPAddress, &address.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    address.sin_port = htons(PORT);
    networkingtype=2;
    return 1;
}
int WrightNetworking::ipv4UDPServerSocket(int PORT){
    if ((networkingsocket = socket(AF_INET, SOCK_DGRAM, 0)) == 0)
    {
        perror("Socket failed To Create");
        return 0;
    }
    address.sin_family = AF_INET;//ipv4
    address.sin_addr.s_addr = INADDR_ANY;//any incoming address
    address.sin_port = htons(PORT);//set port
    networkingtype=1;
    return 1;
}
int WrightNetworking::ipv6UDPClientSocket(char *IPAddress,int PORT){
    if ((networkingsocket = socket(AF_INET6, SOCK_DGRAM, 0)) == 0)
    {
        perror("Socket failed To Create");
        return 0;
    }
    address.sin_family = AF_INET6;//ipv6
    if(inet_pton(AF_INET6, IPAddress, &address.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    address.sin_port = htons(PORT);//set port
    networkingtype=2;
    return 1;
}
int WrightNetworking::ipv6UDPServerSocket(int PORT){
    if ((networkingsocket = socket(AF_INET6, SOCK_DGRAM, 0)) == 0)
    {
        perror("Socket failed To Create");
        return 0;
    }
    address.sin_family = AF_INET6;//ipv4
    address.sin_addr.s_addr = INADDR_ANY;//any incoming address
    address.sin_port = htons(PORT);//set port
    networkingtype=1;
    return 1;
}
int WrightNetworking::bindsocket(){
    int reuseaddr=1;
    if (setsockopt(networkingsocket,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(reuseaddr))==-1) {
        return 0;
    }
    bind(networkingsocket,(struct sockaddr *)&address,sizeof(address));
    return 1;
}
int WrightNetworking::ListenSocket(){
    if (listen(networkingsocket, 10) < 0)
    {
        perror("Failed To Listen For A Connection");
        return 0;
    }
    return 1;
}
int WrightNetworking::ConnectSocket(){
    if (connect(networkingsocket, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    return 1;
}
int WrightNetworking::AcceptSocket(){
  clientSocket = accept(networkingsocket, (struct sockaddr*)&cliaddr, &len);
    return 1;
}
long WrightNetworking::ReadData(char bufferin[MAXLEN]){
    if(networkingtype==1){
        return read(clientSocket,bufferin,1024);
    }
    if(networkingtype==2){
        return read(networkingsocket,bufferin,1024);
    }
    return -1;
}
void WrightNetworking::SendData(char Data[MAXLEN]){
    if(networkingtype==1){
        send(clientSocket,Data,strlen(Data),0);
    }
    if(networkingtype==2){
        send(networkingsocket,Data,strlen(Data),0);
    }
}
char* WrightNetworking::GetBuffer(){
    return buffer;
}
int WrightNetworking::Createipv4TCPServer(int PORT){
    cout<<"Starting IPV4 TCP Server On Port "<<PORT<<endl;
    if(ipv4TCPServerSocket(PORT)==0){
    DieOnError("Failed To Create TCP Server");
    }
    bindsocket();
    ListenSocket();
     cout<<"Lisening For New Connections on Port "<<PORT<<endl;
    return 1;
}
ConnectionInfo WrightNetworking::GetHostConnectionDetails(){
    ConnectionInfo Host;
    Host.address = address;
    Host.socket = networkingsocket;
    Host.len = sizeof(address);
    return Host;
}
ConnectionInfo WrightNetworking::GetClientConnectionDetails(){
    ConnectionInfo Client;
    Client.address = cliaddr;
    Client.socket = clientSocket;
    Client.len = sizeof(cliaddr);
    return Client;
}
