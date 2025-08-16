#include "baud_rate_generator_tb.h"
#include <iostream>

int main()
{
    int status = 0;

    bool baud_rate_signal;

    std::cout << "-----------------" << std::endl;

    for(int i = 0; i < 100; i++)
    {
        baud_rate_generator(baud_rate_signal);
        std::cout << baud_rate_signal;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "-----------------" << std::endl;


    return status;
}