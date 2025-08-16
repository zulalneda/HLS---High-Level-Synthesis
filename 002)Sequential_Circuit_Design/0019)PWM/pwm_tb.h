#pragma once
#include "pwm.h"

void pwm(ap_uint<16> divisor, ap_uint<16> duty_cycle, bool start, bool &slow_clock_signal);