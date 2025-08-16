#include "bcd_counter.h"

typedef enum{s0, s1, s2, s3, s4, s5, s6, s7, s8, s9} state_type;

void bcd_counter(ap_uint<4> &count)
{
    #pragma HLS INTERFACE ap_none port = count
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static state_type state = s0; //başlangıç

    ap_uint<4> count_temp;
    state_type next_state = state; //switch içerisinde next_state kullanacağımız için atama
    
    switch(state)
    {
        case s0:
        next_state = s1;
        count_temp = 0;
        break;

        case s1:
        next_state = s2;
        count_temp = 1;
        break;

        case s2:
        next_state = s3;
        count_temp = 2;
        break;

        case s3:
        next_state = s4;
        count_temp = 3;
        break;

        case s4:
        next_state = s5;
        count_temp = 4;
        break;

        case s5:
        next_state = s6;
        count_temp = 5;
        break;

        case s6:
        next_state = s7;
        count_temp = 6;
        break;

        case s7:
        next_state = s8;
        count_temp = 7;
        break;

        case s8:
        next_state = s9;
        count_temp = 8;
        break;

        case s9:
        next_state = s0;
        count_temp = 9;
        break;

        default:
        break;

    }

    state = next_state;
    count = count_temp;
}