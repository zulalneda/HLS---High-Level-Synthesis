#include "leading_one_tb.h"
#include <iostream>

//ilk 1 nerede var

int find_leading_one_golden(int degisken)
{
    int r;
    
    if(degisken == 0) // 1 yok
    {
        r = -1;
    }
    if(degisken > 0 && degisken < 2) // ilk 1 0. bitte var
    {
        r = 0;
    }
    if(degisken > 1 && degisken < 4) // ilk 1 1. bitte var
    {
        r = 1;
    }
    if(degisken > 3 && degisken < 8) // ilk 1 2. bitte var
    {
        r = 2;
    }
    if(degisken > 7 && degisken < 16) // ilk 1 3. bitte var
    {
        r = 3;
    }
    if(degisken > 15 && degisken < 32) // ilk 1 4. bitte var
    {
        r = 4;
    }
    if(degisken > 31 && degisken < 64) // ilk 1 5. bitte var
    {
        r = 5;
    }
    if(degisken > 63 && degisken < 128) // ilk 1 6. bitte var
    {
        r = 6;
    }
    if(degisken > 127 && degisken < 256) // ilk 1 7. bitte var
    {
        r = 7;
    }
    if(degisken > 255 && degisken < 512) // ilk 1 8. bitte var
    {
        r = 8;
    }

    return r;
}

int main()
{
    int status = 0;

    for(int i = 0; i < 512; i++) // i = test edilecek değer
    {
        int code_gold = find_leading_one_golden(i); // code_gold, cpp dosyamızda tanımlanmış doğru sonuç
        ap_int<9> degisken = (ap_int<9>)i; // degisken = test edilen HLS fonksiyonundan gelecek sonuç
        ap_int<5> code = leading_one(degisken); 

        if(code != code_gold) // eğer HLS fonksiyonundan çıkan code, code_gold ile aynıysa doğru
        {
            status = -1;
            std::cout <<"number = " << i << "code_gold = " << code_gold << " code = " << code << std::endl;
            std::cout << "number = " << degisken.to_string() << "leading one at " << code << std::endl;
        }
        else
        {
            std::cout  << "number = " << degisken.to_string() << "leading one at " << code << std::endl;
        }

        
    }

    if(status == 0)
        {
            std::cout << "test passed!!!" << std::endl;
        }
        else
        {
            std::cout << "test failed!!!" << std::endl;
        }

    return status;
}
