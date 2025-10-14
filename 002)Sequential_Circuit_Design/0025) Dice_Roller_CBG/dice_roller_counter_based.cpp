#include "dice_roller_counter_based.h"

unsigned int get_rand()
{
    static unsigned int count = 0;
    unsigned int r;
    count++;
    r = count % 6 + 1;

    return r;
}

void dice_roller_counter_based(bool roll, ap_uint<8> &seven_segment_data, ap_uint<4> &seven_segment_enable)
{
    #pragma HLS INTERFACE ap_none port = roll
    #pragma HLS INTERFACE ap_none port = seven_segment_data
    #pragma HLS INTERFACE ap_none port = seven_segment_enable
    #pragma HLS INTERFACE ap_ctrl_none port = return
    #pragma HLS PIPELINE

    static unsigned int rand_number = 0;

    unsigned int r = get_rand();
    if(roll == 1)
    {
        rand_number = r;
    }

    seven_segment_data = seven_segment_code_numbers[rand_number];
    seven_segment_enable = 0b1110;

}