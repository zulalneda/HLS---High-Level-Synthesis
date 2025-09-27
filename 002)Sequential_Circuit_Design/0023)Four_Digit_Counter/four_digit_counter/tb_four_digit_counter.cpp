#include "tb_four_digit_counter.h"
#include <iostream>

int main()
{
    int status = 0;

    ap_uint<14> counter_init_value = 123;
    bool load;
    bool up_count;
    bool down_count;

    ap_uint<4> first_digit;
    ap_uint<4> second_digit;
    ap_uint<4> third_digit;
    ap_uint<4> fourth_digit;

    load = 0;
    up_count = 0;
    down_count = 0;

    four_digit_counter(
        counter_init_value,
        load,
        up_count,
        down_count,
        first_digit,
        second_digit,
        third_digit,
        fourth_digit);

    for (int i = 0; i < 10; i++)
    {
        up_count = 1;
        for (int j = 0; j < 10; j++)
        {
            four_digit_counter(
                counter_init_value,
                load,
                up_count,
                down_count,
                first_digit,
                second_digit,
                third_digit,
                fourth_digit);
            up_count = 0;
        }

        std::cout << "first_digit = " << first_digit << "second_digit" << second_digit << "third_digit = " << third_digit << "fourth_digit" << fourth_digit << std::endl;
    }

    return status;
}