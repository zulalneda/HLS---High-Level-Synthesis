#include "float_accumulator.h"

void float_accumulator(DATATYPE a, DATATYPE &acc)
{
    #pragma HLS INTERFACE ap_none port = a
    #pragma HLS INTERFACE ap_none port = acc
    #pragma HLS INTERFACE ap_ctrl_hs port = return
    #pragma HLS PIPELINE

    volatile static DATATYPE acc_state = 0; //volatile, ana hafızadan alınan bir değerdir ve tüm thread'lerde aynı değer geçerlidir.
    acc_state = acc_state + a;

    acc = acc_state;
}
