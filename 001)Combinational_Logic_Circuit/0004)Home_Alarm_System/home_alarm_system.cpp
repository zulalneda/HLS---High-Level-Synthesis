#include "home_alarm_system.h"
#include <iostream>

void home_alarm_system(
    ap_uint<16> switches,
    ap_uint<5> buttons,
    ap_uint<16> &leds,
    ap_uint<8> &segment_data,
    ap_uint<4> &segment_enable)

{
#pragma HLS INTERFACE ap_none port = switches
#pragma HLS INTERFACE ap_none port = buttons
#pragma HLS INTERFACE ap_none port = leds
#pragma HLS INTERFACE ap_none port = segment_data
#pragma HLS INTERFACE ap_none port = segment_enable
#pragma HLS INTERFACE ap_ctrl_none port = return

    ap_uint<3> window_sensors = switches.range(2, 0); // switches(2,1,0) / switches[2:0]
    ap_uint<2> motion_detectors = switches(7, 6);
    ap_uint<4> switch_code = switches.range(15, 12);
    ap_uint<5> faults = buttons;

    leds = switches;

    if (switch_code == 0b1011) // alarm sistemi AÇIK İSE
    {
        if (window_sensors != 0b000 || motion_detectors != 0b00)
        {
            security_breach(window_sensors, motion_detectors, faults, segment_data, segment_enable);
        }
        else
        {
            segment_data = seven_segment_code[10]; // A harfi
            segment_enable = 0b0000;               // Tüm yedi segmenti etkinleştir - active low
        }
    }

    else // Alarm sistemi KAPALIYSA
    {
        segment_data = seven_segment_code[0]; // 0
        segment_enable = 0b0000;
    }
}