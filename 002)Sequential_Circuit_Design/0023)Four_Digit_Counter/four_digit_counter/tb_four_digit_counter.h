#pragma once
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
);