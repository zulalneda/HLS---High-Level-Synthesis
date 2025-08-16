#include "binary2bcd_div.h"

void get_digit(uint27 &a, uint8 &digit)
{
    digit = a - 10*(a/10);
    a = a / 10;
}

void binary2bcd_div(uint27 binary, uint29 *bcd)
{
    #pragma HLS INTERFACE ap_none port = binary
    #pragma HLS INTERFACE ap_none port = bcd
    #pragma HLS INTERFACE ap_ctrl_none port = return

    uint27 a = binary;
    uint8 digit_1, digit_2, digit_3, digit_4, digit_5, digit_6, digit_7, digit_8;

    *bcd = (digit_8, digit_7,digit_6, digit_5, digit_4, digit_3, digit_2, digit_1);
}