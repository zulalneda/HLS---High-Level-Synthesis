#include "dot_product.h"

DATA_TYPE dot_product_core (DATA_TYPE x, DATA_TYPE y, bool start)
{
    static DATA_TYPE s = 0;
    if(start == 1)
    {
        s = x * y;
    }
    else
    {
        s = s + x * y;
    }

    return s;
}

void dot_product(DATA_TYPE x, DATA_TYPE y, unsigned int i, bool input_vld, DATA_TYPE &d)
{
    #pragma HLS PIPELINE
    #pragma HLS INTERFACE ap_none port = x
    #pragma HLS INTERFACE ap_none port = y
    #pragma HLS INTERFACE ap_none port = i
    #pragma HLS INTERFACE ap_none port = d
    #pragma HLS INTERFACE ap_none port = input_vld
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static DATA_TYPE dot_product_reg = 0;
    DATA_TYPE next_dot_product;


    DATA_TYPE z = x*y;

    if(input_vld == 1)
    {
        next_dot_product = dot_product_core(x, y, (i = 0));
    }
    else
    {
        next_dot_product = dot_product_reg;
    }

    dot_product_reg = next_dot_product;
    d = dot_product_reg;
}