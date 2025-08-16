#include "home_alarm_system.h"


void display_window(
    ap_uint<3> window_sensors,
    ap_uint<5> faults,
    ap_uint<8> &segment_data,
    ap_uint<4> &segment_enable)
{
    segment_data = seven_segment_code[14]; // E harfi
    segment_enable = 0b0000;               // Tüm yedi segmenti etkinleştir - active low

    if (faults[0] && window_sensors[0])
    {
        segment_data = seven_segment_code[1];
        segment_enable = 0b1110; // 1. segmenti etkinleştir
    }
    else if (faults[1] && window_sensors[1])
    {
        segment_data = seven_segment_code[2];
        segment_enable = 0b1110;
    }
    else if (faults[2] && window_sensors[2])
    {
        segment_data = seven_segment_code[3];
        segment_enable = 0b1110;
    }
}

void display_motion(
    ap_uint<2> motion_detectors,
    ap_uint<5> faults,
    ap_uint<8> &segment_data,
    ap_uint<4> &segment_enable)
{
    segment_data = seven_segment_code[14]; // E
    segment_enable = 0b0000;               // Tüm yedi segmenti etkinleştir - active low

    if (faults[3] && motion_detectors[0])
    {
        segment_data = seven_segment_code[1];
        segment_enable = 0b1101; // 2. segmenti etkinleştir
    }
    else if (faults[4] && motion_detectors[1])
    {
        segment_data = seven_segment_code[2];
        segment_enable = 0b1101;
    }
}


void security_breach(
    ap_uint<3> window_sensors,
    ap_uint<2> motion_detectors,
    ap_uint<5> faults,
    ap_uint<8> &segment_data,
    ap_uint<4> &segment_enable
)
{
    segment_data = seven_segment_code[14]; // E harfi
    segment_enable = 0b0000;

    if(faults != 0b00000)
    {
        if(window_sensors != 0b000)
        {
            display_window(window_sensors, faults, segment_data, segment_enable);
        }
        if(motion_detectors != 0b00)
        {
            display_motion(motion_detectors, faults, segment_data, segment_enable);
        }
    }
}