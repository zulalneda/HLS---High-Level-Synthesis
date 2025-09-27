#include "four_digit_counter.h"

void four_digit_counter
(
    ap_uint<14> counter_init_value,
    bool load, //1 ise sayacı bu değere yükle
    bool up_count, //1 ise bir artır
    bool down_count, //1 ise bir azalt
    ap_uint<4> &first_digit, 
    ap_uint<4> &second_digit,
    ap_uint<4> &third_digit,
    ap_uint<4> &fourth_digit
)
{
    #pragma HLS PIPELINE
    #pragma HLS INTERFACE ap_none port = counter_init_value
    #pragma HLS INTERFACE ap_none port = load
    #pragma HLS INTERFACE ap_none port = up_count
    #pragma HLS INTERFACE ap_none port = down_count
    #pragma HLS INTERFACE ap_none port = first_digit
    #pragma HLS INTERFACE ap_none port = second_digit
    #pragma HLS INTERFACE ap_none port = third_digit
    #pragma HLS INTERFACE ap_none port = fourth_digit
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static ap_uint<14> counter = 0;
    ap_uint<14> next_counter = counter;

    if(load == 1)
    {
        next_counter = counter_init_value;
    }

    if(up_count == 1)
    {
        if(counter == 9999)
        {
            next_counter = 0;
        }
        else
        {
            next_counter = counter + 1;
        }
    }

    if(down_count == 1)
    {
        if(counter == 0)
        {
            next_counter = 9999;
        }
        else
        {
            next_counter = counter - 1;
        }
    }

    //hiyerarşi: load --> up --> down 

    ap_uint<14> a = next_counter;
    first_digit = a%10;
    a = a / 10;

    second_digit = a % 10;
    a = a / 10;

    third_digit = a % 10;
    a = a / 10;

    fourth_digit = a % 10;
    
    counter = next_counter;
}