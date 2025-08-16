#include "dffs.h"

void dffs(bool data, bool &q1, bool &q2, bool &q3)
{
    #pragma HLS INTERFACE ap_none port = data
    #pragma HLS INTERFACE ap_none port = q1
    #pragma HLS INTERFACE ap_none port = q2
    #pragma HLS INTERFACE ap_none port = q3
    #pragma HLS INTERFACE ap_ctrl_none port = return

    volatile // Use volatile to ensure the compiler does not optimize away the static variable. 
    //Derleyici her okumada "bu değişken değişebilir, tekrar oku" der
    static bool dff0 = 0;
    static bool dff1 = 0;
    static bool dff2 = 0;
    static bool dff3 = 0;

    dff3 = dff2;
    dff2 = dff1;
    dff1 = dff0;
    dff0 = data;

    q1 = dff1;
    q2 = dff2;
    q3 = dff3;

}

