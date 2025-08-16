#include "home_alarm_system_tb.h"
#include <iostream>

void home_alarm_system_sw(
	ap_uint<16> switches,
	ap_uint<5> buttons,

	ap_uint<16> &leds,
	ap_uint<8> &segment_data,
	ap_uint<4> &segment_enable)
{
	leds = switches;
if (switches.range(15, 12) == 0b1011)
{										 // ev alarm sistemi AÇIK
	if (switches.range(2, 0) == 0b000	 // Tüm pencereler kapalı
		&& switches.range(7, 6) == 0b00) // Hiçbir hareket algılanmadı
	{
		segment_data = 0b10001000;
		segment_enable = 0b0000;
	}
	else
	{ // security breach
		segment_data = 0b10000110;
		segment_enable = 0b0000;

		if (buttons[0] == 1) // P17 - Window 1
		{
			if (switches[0] == 1)
			{
				segment_data = 0b11111001;
				segment_enable = 0b1110;
			}
		}

		if (buttons[1] == 1)
		{
			if (switches[1] == 1)
			{
				segment_data = 0b10100100;
				segment_enable = 0b1110;
			}
		}

		if (buttons[2] == 1)
		{
			if (switches[2] == 1)
			{
				segment_data = 0b10110000;
				segment_enable = 0b1110;
			}
		}

		if (buttons[3] == 1)
		{
			if (switches[6] == 1)
			{
				segment_data = 0b11111001;
				segment_enable = 0b1101;
			}
		}

		if (buttons[4] == 1)
		{
			if (switches[7] == 1)
			{
				segment_data = 0b10100100;
				segment_enable = 0b1101;
			}
		}
	}
}
else
{ // ev alarm sistemi KAPALI
	segment_data = 0b11000000;
	segment_enable = 0b0000;
}
}

int main()
{

	int status = 0;

	ap_uint<3> window_sensors;
	ap_uint<2> motion_sensors;
	ap_uint<4> on_pattern;

	ap_uint<16> switches;
	ap_uint<5> buttons;

	ap_uint<16> leds_hw;
	ap_uint<8> segment_data_hw;
	ap_uint<4> segment_enable_hw;

	ap_uint<16> leds_sw;
	ap_uint<8> segment_data_sw;
	ap_uint<4> segment_enable_sw;

	for (int i = 0; (i < 8) && (status == 0); i++)
	{
		for (int j = 0; (j < 4) && (status == 0); j++)
		{
			for (int k = 0; (k < 16) && (status == 0); k++)
			{
				buttons = (ap_uint<5>)0b00001;
				for (int l = 0; (l < 32) && (status == 0); l++)
				{
					window_sensors = i;
					motion_sensors = j;
					on_pattern = k;
					buttons = push_buttons << 1;
					switches = (push_buttons, (ap_int<4>)0, motion_sensors, (ap_int<3>)0, window_sensors);

					home_alarm_system(
						switches,
						buttons,

						leds_hw,
						segment_data_hw,
						segment_enable_hw);

					home_alarm_system_sw(
						switches,
						buttons,

						leds_sw,
						segment_data_sw,
						segment_enable_sw);

					if (leds_hw != leds_sw || segment_data_hw != segment_data_swv || segment_enable_hw != segment_enable_sw)
					{

						status = -1;
						std::cout << "leds_hw = " << leds_hw.to_string() << "?" << "leds_sw = " << leds_sw.to_string() << std::endl;
						std::cout << "segment_data_hw = " << segment_data_hw.to_string() << "?" << "segment_data_sw = " << segment_data_sw.to_string() << std::endl;
						std::cout << "segment_enable_hw = " << segment_enable_hw.to_string() << "?" << "segment_enable_sw = " << segment_enable_sw.to_string() << std::endl;
						break;
					}
				}
			}
		}
	}

	if (status == 0)
	{
		std::cout << " Test passed!" << std::endl;
	}
	else
	{
		std::cout << " Test failed!" << std::endl;
	}

	return status;
}