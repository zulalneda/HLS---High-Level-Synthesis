#include "binary2bcd_double_dabble_tb.h"
#include <iostream>
#include <cstdlib> //rand() //srand()
#include <ctime> //time()


int main()
{
    int status = 0;

    //uint8 binary = 36;

    srand(time(0)); //sadece bir kere çağrılmalı
    uint8 binary = rand() %256; // 0-255 arası rastgele bir sayı üret
    
    uint16 unpacked_bcd;
    uint8 packed_bcd;

    binary2bcd_double_dabble(binary, &unpacked_bcd, &packed_bcd);
    std::cout << "binary = " << binary.to_string() << "unpacked_bcd = " << unpacked_bcd.to_string() << "packed_bcd = " << packed_bcd.to_string() << std::endl;

    return status;
}