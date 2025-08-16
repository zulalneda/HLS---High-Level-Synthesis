#include "fir_toplam_formulu.h"

const int N = 11;

typedef int coef_t;
typedef int data_t;
typedef int acc_t;

void fir (data_t *y, data_t x)
{
    #pragma HLS PIPELINE
    #pragma HLS INTERFACE ap_none port = y
    #pragma HLS INTERFACE ap_none port = x
    #pragma HLS INTERFACE ap_ctrl_none port = return
    coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};

    static data_t shift_reg[N];

    acc_t acc;
    acc = 0;

    Shift_Accum_Loop:
    for(int i = N -1; i >= 0; i--)
    {
        if (i == 0)
        {
            acc += x * c[0];
            shift_reg[0] = x;
        }
        else
        {
            shift_reg[i] = shift_reg[i - 1];
            acc += shift_reg[i] * c[i];
        }
    }

    *y = acc;

}
