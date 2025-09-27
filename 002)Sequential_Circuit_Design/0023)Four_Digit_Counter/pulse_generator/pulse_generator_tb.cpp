#include "pulse_generator_tb.h"
#include <iostream>

int main()
{
    int status = 0;
    bool input;
    bool pulse;

    std::cout << "-----------------" << std::endl;

    std::cout << " pulse = " ;
    for(int i = 0; i < 100; i++)
    {
        input = 0;
        pulse_generator(input,pulse);
        std::cout << " " << pulse;
    }

    for(int i = 0; i < 100; i++)
    {
        input = 1;
        pulse_generator(input,pulse);
        std::cout << " " << pulse;
    }

    for(int i = 0; i < 100; i++)
    {
        input = 0;
        pulse_generator(input,pulse);
        std::cout << " " << pulse;
    }
    std::cout << std::endl;
    std::cout << "-----------------" << std::endl;
    return status;
}