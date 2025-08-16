#pragma once
#include "serial2parallel.h"
const int N = 8;

void serial2parallel(bool serial_start, bool &end_conversion, bool data, ap_uint<N> &a);
