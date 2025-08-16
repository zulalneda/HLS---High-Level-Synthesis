#include "clock_generator_tb.h"
#include <iostream>

const int clock_frequency_divisor = 20;

int main()
{
    int status = 0;
    bool slow_clock_signal;
    std::cout << "------------" << std::endl;
    std::cout << "------------" << std::endl;

    for(int i = 0; i < 100; i++)
    {
        clock_generator(slow_clock_signal);
        std::cout << " slow_clock_signal = " << slow_clock_signal << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    return status;
}