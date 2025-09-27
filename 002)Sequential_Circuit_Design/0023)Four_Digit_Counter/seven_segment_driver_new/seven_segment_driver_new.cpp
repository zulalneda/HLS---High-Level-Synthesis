#include "seven_segment_driver_new.h"

typedef enum{display1, display2, display3, display4} state_type;

void seven_segment_driver_new
(
    bool refresh_signal,
    ap_uint<4> first_digit,
    ap_uint<4> second_digit,
    ap_uint<4> third_digit,
    ap_uint<4> fourth_digit,
    ap_uint<8> &seven_segment_data,
    ap_uint<4> &seven_segment_enable
)
{
    #pragma HLS PIPELINE
    #pragma HLS INTERFACE ap_none port = refresh_signal
    #pragma HLS INTERFACE ap_none port = first_digit
    #pragma HLS INTERFACE ap_none port = second_digit
    #pragma HLS INTERFACE ap_none port = third_digit
    #pragma HLS INTERFACE ap_none port = fourth_digit
    #pragma HLS INTERFACE ap_none port = seven_segment_data
    #pragma HLS INTERFACE ap_none port = seven_segment_enable
    #pragma HLS INTERFACE ap_ctrl_none port = return
    
    static state_type state = display1;

    ap_uint<8> seven_segment_data_local;
    ap_uint<4> seven_segment_enable_local;

    state_type next_state;

    switch(state)
    {
        case display1:
        if(refresh_signal)
        {
            next_state = display2;
            seven_segment_data_local = seven_segment_code[second_digit];
            seven_segment_enable_local = 0b1110;
        }
        else
        {
            next_state = display1;
            seven_segment_data_local = seven_segment_code[first_digit];
            seven_segment_enable_local = 0b1110;
        }
        break;

        case display2:
        if(refresh_signal)
        {
            next_state = display3;
            seven_segment_data_local = seven_segment_code[third_digit];
            seven_segment_enable_local = 0b1101;
        }
        else
        {
            next_state = display2;
            seven_segment_data_local = seven_segment_code[second_digit];
            seven_segment_enable_local = 0b1101;
        }
        break;

        case display3:
        if(refresh_signal)
        {
            next_state = display4;
            seven_segment_data_local = seven_segment_code[fourth_digit];
            seven_segment_enable_local = 0b1011;
        }
        else
        {
            next_state = display3;
            seven_segment_data_local = seven_segment_code[third_digit];
            seven_segment_enable_local = 0b1011;
        }
        break;

        case display4:
        if(refresh_signal)
        {
            next_state = display1;
            seven_segment_data_local = seven_segment_code[first_digit];
            seven_segment_enable_local = 0b0111;
        }
        else
        {
            next_state = display4;
            seven_segment_data_local = seven_segment_code[fourth_digit];
            seven_segment_enable_local = 0b0111;
        }
        break;

        default:
        break;
    }

    state = next_state;
    seven_segment_data = seven_segment_data_local;
    seven_segment_enable = seven_segment_enable_local;
}