#include "seven_segment_signal.h"

const int SIGNAL_PERIOD = 400000;
//const int SIGNAL_PERIOD = 10; //for simulation
//saat freknsı 100 MHz, her clock 10ns , 400000 x 10 ns = 4ms --> her 4 ms'de 1 clock sinyali üretir.

void seven_segment_signal(bool &out_signal)
{
    #pragma HLS INTERFACE ap_none port = out_signal
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static int count = SIGNAL_PERIOD - 1; //reset atılmadıkça sayacın değeri korunur.
    int next_count = count;
    bool next_out_signal;

    if(count == 0)
    {
        next_out_signal = 1;
        next_count = SIGNAL_PERIOD - 1;
    }
    else
    {
        next_out_signal = 0;
        next_count = count - 1;
    }

    count = next_count;
    out_signal = next_out_signal;
}
