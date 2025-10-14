#include "generate_float_numbers.h"

void generate_float_numbers(bool generate, DATATYPE &float_number)
{
    #pragma HLS INTERFACE ap_ctrl_none port = generate
    #pragma HLS INTERFACE ap_ctrl_none port = float_number
    #pragma HLS PIPELINE
    #pragma HLS INTERFACE ap_ctrl_hs port = return

    static unsigned int index = 0;
    static DATATYPE float_number_state = 0;

    unsigned int next_index;
    if(generate == 1)
    {
        float_number_state = data[index];
        if(index == 9)
        {
            next_index = 0;
        }
        else
        {
            next_index = index + 1;
        }
    }
    else
    {
        next_index = index;
    }

    index = next_index;
    float_number = float_number_state;
}