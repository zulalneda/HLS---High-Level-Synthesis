#pragma once
#include "bcd_counter_pipelining.h"

void bcd_counter_pipelining(bool pulse, ap_uint<8> &seven_segment_data, ap_uint<4> &seven_segment_enable);
