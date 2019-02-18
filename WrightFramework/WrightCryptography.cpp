//
//  WrightCryptography.cpp
//  WrightFramework
//
//  Created by william wright on 2/18/19.
//  Copyright © 2019 Silvertap. All rights reserved.
//

#include "WrightCryptography.hpp"
string WrightCryptography::WrightCrypt(string Buffer_in,int mode){
    //shift the string ascii vale then convirt to base 16 for transfer
    CaesarCipher(Buffer_in,4,1);//first we shift the string so its encrypted
    Base16EncryptString(buffer);//convert the shifted mexssage to hex
    return buffer;
}
//Takes a String and converts it to hex returns a string
string WrightCryptography::Base16EncryptString(string buffer_in){
    buffer = "";//clear the buffer to rewrite it
    for(int i=0;i<buffer_in.length();i++){
    buffer.append(ConvertFromBaseTo(buffer_in[i], 16));
    }
    return buffer;
}
string WrightCryptography::Base16DecryptString(string buffer_in){
    return nullptr;
}
//convertFromBaseTo() This Function Takes in a base 10 number and converts it into any other base it returns a string
std::string WrightCryptography::ConvertFromBaseTo(unsigned int convertFrom, int convertTo) {
    std::string answer;
    while (convertFrom != 0){
        int digit = convertFrom % convertTo;
        char stringDigit;
        if (digit < 10) {
            stringDigit = '0' + digit;
        } else {
            stringDigit = digit - 10 + 'A';
        }
        answer.insert(answer.begin(), stringDigit);
        convertFrom /= convertTo;
    }
    return answer;
}
string WrightCryptography::CaesarCipher(string text, int shift,int mode)
{
    buffer = "";//zero the buffer to allow us to overwrite it from scratch
    switch (mode) {
        case 1:
            for (int i=0;i<text.length();i++)
            {
                if (isupper(text[i]))
                    buffer += char(int(text[i]+shift-65)%26 +65);
                else
                    buffer += char(int(text[i]+shift-97)%26 +97);
            }
            return buffer;
        case 2:
            return CaesarCipher(text, 26-shift, 1);
    }
    return "Invalid Mode Selected";
    
}
string WrightCryptography::XorCrypt(string StringToEncrypt, char xorKey)
    {
        buffer= StringToEncrypt;
        for (int i = 0; i < StringToEncrypt.length(); i++)
        {
            buffer[i] = StringToEncrypt[i] ^ xorKey;
        }
        return buffer;
}
string WrightCryptography::XorHMAC(string StringToEncrypt,char XorKey1,char XorKey2){
   string temp = XorCrypt(StringToEncrypt, XorKey1);
    buffer = XorCrypt(buffer, XorKey2);
    return buffer;
}
