#include "bcd_counter_tb.h"
#include <iostream>

int main()
{
    int status = 0;
    ap_uint<4> count;

    for(int i = 0; i < 20; i++)
    {
        bcd_counter(count);
        std::cout << " count = " << count << std::endl;
    }

    return status;

}