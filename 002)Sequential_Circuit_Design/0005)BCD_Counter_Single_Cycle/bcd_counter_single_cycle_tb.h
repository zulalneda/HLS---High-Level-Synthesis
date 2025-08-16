#pragma once
#include "bcd_counter_single_cycle.h"

void bcd_counter_single_cycle(bool pulse, ap_uint<8> &seven_segment_data, ap_uint<4> &seven_segment_enable);
