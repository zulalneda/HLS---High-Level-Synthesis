#include "timing_constraint.h"

void timing_constraint(ap_uint<W> a, ap_uint<b>, ap_uint<W> *f)
{
    #pragma HLS INTERFACE ap_none port = a
    #pragma HLS INTERFACE ap_none port = b
    #pragma HLS INTERFACE ap_none port = f
    #pragma HLS INTERFACE ap_ctrl_none port = return

    *f = a*b;
}