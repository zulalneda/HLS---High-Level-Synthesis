#include "tb_dice_roller_counter_based.h"
#include <iostream>
#include <map>
#include <time.h>
#include <ctime>
#include <cstdlib>

std::map <ap_uint<8>, int> seven_segment_numbers_Inst0 =
{
    {0b11000000, 0},
	{0b11111001, 1},
	{0b10100100, 2},
	{0b10110000, 3},
	{0b10011001, 4},
	{0b10010010, 5},
	{0b10000010, 6},
	{0b11111000, 7},
	{0b10000000, 8},
	{0b10010000, 9}
};

int main()
{
    int status = 0;
    bool roll;
    ap_uint<8> seven_segment_data;
    ap_uint<4> seven_segment_enable;

    srand(time(NULL));

    std::cout << "---------------------" << std::endl;

    roll = 1;
    dice_roller_counter_based(roll, seven_segment_data, seven_segment_enable);
    std::cout << "Real Number: " << seven_segment_numbers_Inst0[seven_segment_data] << std::endl;

    for(int i = 0; i < 20; i++)
    {
        int r = rand() % 1024;
        for(int j = 0; j < r; j++)
        {
            roll = 0;
            dice_roller_counter_based(roll, seven_segment_data, seven_segment_enable);
        }
        roll = 1;
        dice_roller_counter_based(roll, seven_segment_data, seven_segment_enable);
        std::cout << "rand_number: " << seven_segment_numbers_Inst0[seven_segment_data] << std::endl;
    }

    return status;
}