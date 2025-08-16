#include "bcd_counter_pipelining_tb.h"
#include <iostream>

int main()
{
    int status = 0;

    bool pulse;
    ap_uint<8> seven_segment_data_hw; //RTL sonucu nasıl olacak?
    ap_uint<4> seven_segment_enable_hw;

    ap_uint<8> seven_segment_data_sw; //golden model --> istenen
    ap_uint<4> seven_segment_enable_sw;

    std::cout << "-------------" << std::endl;


    pulse = 1;
    for(int i = 0; i < 12; i++)
    {
        pulse = !pulse;
        bcd_counter_pipelining(pulse, seven_segment_data_hw, seven_segment_enable_hw);
        std::cout << " pulse = " << pulse << " seven_segment_data = " << seven_segment_data_hw << " seven_segment_enable = " << seven_segment_enable_hw << std::endl;
    }

    if(status == 0)
    {
        std::cout << "Test Passed!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed!" << std::endl;
    }

    return status;
}