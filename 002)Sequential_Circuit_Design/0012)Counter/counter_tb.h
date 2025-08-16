#pragma once
#include "counter.h"
#include <map>

void counter(bool count_button,
    ap_uint<8> &seven_segment_data,
    ap_uint<4> &seven_segment_enable);