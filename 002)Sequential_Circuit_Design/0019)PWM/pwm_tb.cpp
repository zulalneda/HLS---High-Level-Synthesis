#include "pwm_tb.h"
#include <iostream>

int main()
{
    int status = 0;
    ap_uint<16> divisor;
    ap_uint<16> duty_cycle;
    bool start;
    bool slow_clock_signal;

    std::cout << "-----------" << std::endl;

    start = 0;
    pwm(divisor,duty_cycle, start, slow_clock_signal);

    start = 1;
    divisor = 20;
    duty_cycle = 5;
    pwm(divisor, duty_cycle, start, slow_clock_signal);

    start = 0;
    for(int i = 0; i < 100 ; i++)
    {
        pwm(divisor, duty_cycle, start, slow_clock_signal);
        std::cout << slow_clock_signal;
    }
    std::cout << std::endl;

    std::cout << "-----------" << std::endl;

    return status;
}