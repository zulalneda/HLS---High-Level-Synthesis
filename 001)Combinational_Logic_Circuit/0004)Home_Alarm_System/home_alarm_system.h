#ifndef __HOME_ALARM_SYSTEM_H__
#define __HOME_ALARM_SYSTEM_H__
#include<ap_int.h>

const ap_uint<8> seven_segment_code[] =
{
    // aktif - düşük
    0b11000000,   // 0---------- > index 0
	0b11111001,   // 1---------- > index 1
	0b10100100,   // 2---------- > index 2
	0b10110000,   // 3---------- > index 3
	0b10011001,   // 4---------- > index 4
	0b10010010,   // 5---------- > index 5
	0b10000010,   // 6---------- > index 6
	0b11111000,   // 7---------- > index 7
	0b10000000,   // 8---------- > index 8
	0b10010000,   // 9---------- > index 9

	0b10001000,   // A---------- > index 10
	0b10000011,   // b---------- > index 11
	0b11000110,   // C---------- > index 12
	0b10100001,   // d---------- > index 13
	0b10000110,   // E---------- > index 14
	0b10001110    // F---------- > index 15
};

void security_breach(
    ap_uint<3> window_sensors,
    ap_uint<2> motion_detectors,
    ap_uint<5> faults,

    ap_uint<8> &segment_data,
    ap_uint<4> &segment_enable
);
#endif