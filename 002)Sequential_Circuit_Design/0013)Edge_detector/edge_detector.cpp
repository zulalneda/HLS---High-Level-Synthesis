#include "edge_detector.h"

void edge_detector(bool input_signal, bool &rising_edge, bool &falling_edge)
{
    #pragma HLS INTERFACE ap_none port = input_signal
    #pragma HLS INTERFACE ap_none port = rising_edge
    #pragma HLS INTERFACE ap_none port = falling_edge
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static bool previous_input_signal = 0;

    if(previous_input_signal == 0 && input_signal == 1)
    {
        rising_edge = 1;
        falling_edge = 0;
    }
    else if(previous_input_signal == 1 && input_signal == 0)
    {
        rising_edge = 0;
        falling_edge = 1;
    }
    else
    {
        rising_edge = 0;
        falling_edge = 0;
    }

    previous_input_signal = input_signal; //geçmişi bilmeden kontrol yapamayız. o yüzden atama sırası böyle
}