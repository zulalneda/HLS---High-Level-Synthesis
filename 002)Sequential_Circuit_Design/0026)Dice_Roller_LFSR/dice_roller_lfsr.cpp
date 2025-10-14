#include "dice_roller_lfsr.h"

ap_uint<32> pseudo_random(ap_uint<32> seed, bool load)
{
    static ap_uint<32> lfsr;

    if(load == 1)
    {
        lfsr = seed;   
    }
    bool b_32 = lfsr.get_bit(32-32);
    bool b_22 = lfsr.get_bit(32-22);
    bool b_2 = lfsr.get_bit(32-2);
    bool b_1 = lfsr.get_bit(32-1);

    bool new_bit = b_32 ^ b_22 ^ b_2 ^ b_1;
        
    lfsr = lfsr >> 1;

    lfsr.set_bit(31, new_bit);

    return lfsr;
}

unsigned int get_rand()
{
    unsigned int r;
    static bool first_time = 1;

    if(first_time == 1)
    {
        pseudo_random(11, 1);
        first_time = 0;
    }

    r = pseudo_random(0, 0) % 6 + 1;

    return r;
}

void dice_roller_lfsr(bool roll, ap_uint<8> &seven_segment_data, ap_uint<4> &seven_segment_enable)
{
    #pragma HLS INTERFACE ap_none port = roll
    #pragma HLS INTERFACE ap_none port = seven_segment_data
    #pragma HLS INTERFACE ap_none port = seven_segment_enable
    #pragma HLS INTERFACE ap_ctrl_none port = return
    #pragma HLS PIPELINE

    static unsigned int rand_number = 0;

    if(roll == 1)
    {
        rand_number = get_rand();
    }

    seven_segment_data = seven_segment_code_numbers[rand_number];
    seven_segment_enable = 0b1110;
}