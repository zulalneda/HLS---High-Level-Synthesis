#pragma once
#include "state_machine.h"

void state_machine
(
    ap_uint<4> x,
    bool enter,
    bool &door_open,
    bool lock,
    ap_uint<8> &seven_segment_data,
    ap_uint<4> &seven_segment_enable
);