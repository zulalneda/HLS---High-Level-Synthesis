#pragma once
#include "seven_segment_driver_new.h"

void seven_segment_driver_new
(
    bool refresh_signal,
    ap_uint<4> first_digit,
    ap_uint<4> second_digit,
    ap_uint<4> third_digit,
    ap_uint<4> fourth_digit,
    ap_uint<8> &seven_segment_data,
    ap_uint<4> &seven_segment_enable
);