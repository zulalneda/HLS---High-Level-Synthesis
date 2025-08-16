#pragma once
#include "parallel2serial.h"
const int N = 8;

void parallel2serial
(
    ap_uint<N> a,
    bool &data,
    bool &serial_start,
    bool &serial_end,
    bool begin
);