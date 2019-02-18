//
//  WrightCryptography.hpp
//  WrightFramework
//
//  Created by william wright on 2/18/19.
//  Copyright © 2019 Silvertap. All rights reserved.
//  Developed To Allow WrightFramework to Crypt

#ifndef WrightCryptography_hpp
#define WrightCryptography_hpp
#include <iostream>
#include <stdio.h>
#define MAXLEN 1024
#endif /* WrightCryptography_hpp */
using namespace std;
class WrightCryptography{
public:
    string GetBuffer();
    void SetBuffer(string buffer_in);
    string Base16EncryptString(string buffer_in);
    string Base16DecryptString(string buffer_in);
    string C_EncryptWithSalt(string buffer_in,string Salt);
    string C_DecryptWithSalt(string buffer_in,string Salt);
    string WrightCrypt(string Buffer_in,int mode);//base 32 encrypt then change asci value
    string ConvertFromBaseTo(unsigned int convertFrom, int convertTo);
    string CaesarCipher(string text, int shift,int mode);
    string XorCrypt(string StringToEncrypt, char xorKey);
    string XorHMAC(string StringToEncrypt,char XorKey1,char XorKey2);
private:
    string buffer;
};
