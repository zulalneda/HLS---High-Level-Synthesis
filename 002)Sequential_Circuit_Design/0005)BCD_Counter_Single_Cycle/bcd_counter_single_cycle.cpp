#include "bcd_counter_single_cycle.h"

void show_display(ap_uint<4> counter_state, ap_uint<8> &seven_segment_data, ap_uint<4> &seven_segment_enable)
{
    switch (counter_state)
    {
        case 0:
        {
            seven_segment_data = seven_segment_code[0];
        }
        break;

        case 1:
        {
            seven_segment_data = seven_segment_code[1];
        }
        break;

        case 2:
        {
            seven_segment_data = seven_segment_code[2];
        }
        break;

        case 3:
        {
            seven_segment_data = seven_segment_code[3];
        }
        break;

        case 4:
        {
            seven_segment_data = seven_segment_code[4];
        }
        break;

        case 5:
        {
            seven_segment_data = seven_segment_code[5];
        }
        break;

        case 6:
        {
            seven_segment_data = seven_segment_code[6];
        }
        break;

        case 7:
        {
            seven_segment_data = seven_segment_code[7];
        }
        break;

        case 8:
        {
            seven_segment_data = seven_segment_code[8];
        }
        break;

        case 9:
        {
            seven_segment_data = seven_segment_code[9];
        }
        break;

        default:
        break;
    }

    seven_segment_enable = 0b1110;
}

void bcd_counter_single_cycle(bool pulse, ap_uint<8> &seven_segment_data, ap_uint<4> &seven_segment_enable)
{
    #pragma HLS INTERFACE ap_none port = pulse
    #pragma HLS INTERFACE ap_none port = seven_segment_data
    #pragma HLS INTERFACE ap_none port = seven_segment_enable
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static ap_uint<4> counter_state = 0;

    if(pulse == 1)
    {
        if(counter_state == 9)
        {
            counter_state = 0;
        }
        else
        {
            counter_state = counter_state + 1;
        }
    }

    show_display(counter, seven_segment_data, seven_segment_enable);
}