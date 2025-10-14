#include "display_float.h"
#define ONE_MS 100000

typedef enum{display1, display2, display3, display4} display_state_type;

void display_driver(
    ap_uint<4> a,
    ap_uint<4> b,
    ap_uint<4> c,
    ap_uint<4> d,

    ap_uint<8> &seven_segment_data,
    ap_uint<4> &seven_segment_enable
)
{
    static ap_uint<2> state = display1;
    static unsigned int timer = ONE_MS;

    ap_uint<2> next_state;
    next_state = state;
    unsigned int next_timer;
    next_timer = timer;

    switch(state)
    {
        case display1:
        seven_segment_data = seven_segment_code[a];
        seven_segment_enable = 0b0111;
        if(timer != 0)
        {
            next_timer = timer - 1;
            next_state = display1;
        }
        else
        {
            next_timer = ONE_MS;
            next_state = display2;
        }
        break;

        case display2:
        seven_segment_data = seven_segment_code[b]& 0b01111111; //decimal point'i yakarak sayıyı "aa.bb" şeklinde ondalıklı gösteriyoruz.
        seven_segment_enable = 0b1011;
        if(timer != 0)
        {
            next_timer = timer - 1;
            next_state = display2;
        }
        else
        {
            next_timer = ONE_MS;
            next_state = display3;
        }
        break;

        case display3:
        seven_segment_data = seven_segment_code[c];
        seven_segment_enable = 0b1101;
        if(timer != 0)
        {
            next_timer = timer - 1;
            next_state = display3;
        }
        else
        {
            next_timer = ONE_MS;
            next_state = display4;
        }
        break;

        case display4:
        seven_segment_data = seven_segment_code[d];
        seven_segment_enable = 0b1110;
        if(timer != 0)
        {
            next_timer = timer - 1;
            next_state = display4;
        }
        else
        {
            next_timer = ONE_MS;
            next_state = display1;
        }
        break;

        default:
        break;
    }

    state = next_state;
    timer = next_timer;
}

void display_float(DATATYPE acc, ap_uint<8> &seven_segment_data, ap_uint<4> &seven_segment_enable)
{
    #pragma HLS INTERFACE ap_none port = acc
    #pragma HLS INTERFACE ap_none port = seven_segment_data
    #pragma HLS INTERFACE ap_none port = seven_segment_enable
    #pragma HLS INTERFACE ap_ctrl_none port = return //ap_ctrl_hs X
    #pragma HLS PIPELINE

    unsigned int acc_int = acc;
    DATATYPE b = acc - acc_int;

    unsigned int acc_int_0 = acc_int % 10;
    acc_int = acc_int / 10;
    unsigned int acc_int_1 = acc_int % 10;
    
    unsigned int b_int_0 = b * 10;
    b = b * 10 - b_int_0;
    unsigned int b_int_1 = b * 10;

    display_driver(acc_int_1, acc_int_0, b_int_0, b_int_1, seven_segment_data, seven_segment_enable);
}