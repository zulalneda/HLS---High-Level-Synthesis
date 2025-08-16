#include "clock_generator.h"

const int clock_frequency_divisor = 20;

typedef enum{zero, one} clock_state_type;

void clock_generator(bool &slow_clock_signal)
{
    #pragma HLS INTERFACE ap_none port = slow_clock_signal
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static clock_state_type state = zero;
    static unsigned int counter = clock_frequency_divisor / 2-1;

    clock_state_type next_state;
    unsigned int next_counter;

    bool slow_clock_signal_local;

    switch(state)
    {
        case zero:
        if(counter == 0)
        {
            next_counter = clock_frequency_divisor / 2 - 1;
            next_state = one;
        }
        else
        {
            next_counter = counter - 1;
            next_state = zero;
        }
        slow_clock_signal_local = 0;
        break;

        case one:
        if(counter == 0)
        {
            next_counter = clock_frequency_divisor / 2-1;
            next_state = zero;
        }
        else
        {
            next_counter = counter - 1;
            next_state = one;
        }
        slow_clock_signal_local = 1;
        break;

        default:
        break;
    }


    state = next_state;
    counter = next_counter;
    slow_clock_signal = slow_clock_signal_local;
}