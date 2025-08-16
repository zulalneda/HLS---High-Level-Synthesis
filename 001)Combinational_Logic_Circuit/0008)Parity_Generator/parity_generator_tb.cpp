#include "parity_generator_tb.h"
#include <iostream>
#include <bitset> // sabit uzunluktaki bit serilerini tutmak ve onlarla çalışmak
/*
1) TANIMLAMA
#include <bitset>
std::bitset<8> bits;              // 00000000
std::bitset<8> bits2(13);         // 00001101
std::bitset<8> bits3("1101");     // 00001101

2) TEMEL İŞLEMLER
bits.set(3);      // 3. biti 1 yap
bits.reset(2);    // 2. biti 0 yap
bits.flip(0);     // 0. biti tersle (0->1, 1->0)
bool val = bits.test(3);  // 3. bit 1 mi?

3) ÇIKTI
std::cout << bits << std::endl; // string gibi yazdırır (örnek: 10110001)
*/

bool parity_generator_sw(ap_uint<W> a)
{
    bool parity = 0;
    for (int i = 0; i < W; i++)
    {
        parity = parity ^ a[i];
    }

    return parity;
}

int main()
{
    int status = 0;
    ap_uint<W> x;

    bool parity_hw;
    bool parity_sw;

    for (int i = 0; i < 65536; i++)
    {
        x = (ap_uint<W>)i;
        parity_hw = parity_generator(x);
        parity_sw = parity_generator_sw(x);

        if (parity_sw != parity_hw)
        {
            status = -1;
            std::cout << "x = " << std::bitset<W>(x) << "parity_hw = " << parity_hw << "parity_sw = " << parity_sw << std::endl;
            break;
        }
    }

    if (status == 0)
    {
        std::cout << "Test successfull!" << std::endl;
    }

    else
    {
        std::cout << "Test failed!" << std::endl;
    }
}