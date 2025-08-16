#include "serial2parallel.h"
const int N = 8;

// Dışarıdan teker teker, her seferinde gelen 1 biti N'e kadar toplamak

void serial2parallel(bool serial_start, bool &end_conversion, bool data, ap_uint<N> &a)
{
    #pragma HLS INTERFACE ap_none port = serial_start
    #pragma HLS INTERFACE ap_none port = end_conversion
    #pragma HLS INTERFACE ap_none port = data
    #pragma HLS INTERFACE ap_none port = a
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static ap_uint<N> state_reg = 0; // içeri gelen verileri topladığımız yer
    static ap_uint<N> a_reg_out = 0; // çeviri tamamlandığında dışarı aktarılacak veri
    static unsigned int counter = N; // kaç bit aldığımızı takip eder

    unsigned int next_counter;
    ap_uint<N> next_state = state_reg;

    next_counter = counter;

    if(serial_start == 1)
    {
        next_counter = 0;
        next_state = 0;
    }

    if(next_counter < N - 1)
    {
        next_state = (next_state >> 1);
        next_state[N-1] = data; //next_state'i sağa kaydırır, en sola gelen biti (d) ekler.
        next_counter++;
        end_conversion = 0;
    }
    else if(next_counter == N - 1)
    {
        next_state = (next_state >> 1);
        next_state[N-1] = data;
        next_counter++;
        a_reg_out = next_state;
        end_conversion = 1;
    }
    else
    {
        end_conversion = 0;
    }


    counter = next_counter;
    state_reg = next_state;
    a = a_reg_out;
}