#ifndef __HOME_ALARM_SYSTEM_TB_H__
#define __HOME_ALARM_SYSTEM_TB_H__
#include "home_alarm_system.h"

void home_alarm_system(
    ap_uint<16> switches,
    ap_uint<5> buttons,
    ap_uint<16> &leds,
    ap_uint<8> &segment_data,
    ap_uint<4> &segment_enable
);

#endif