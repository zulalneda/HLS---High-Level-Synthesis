#include "leading_one.h"
#include <ap_int.h>

ap_int<5> leading_one(ap_uint<9> degisken)
{
#pragma HLS INTERFACE ap_none port = degisken
#pragma HLS INTERFACE ap_ctrl_none port = return

    ap_int<5> code;

    if (degisken[8] == 1)
    {
        code = 8;
    }
    else if (degisken[7] == 1)
    {
        code = 7;
    }
    else if (degisken[6] == 1)
    {
        code = 6;
    }
    else if (degisken[5] == 1)
    {
        code = 5;
    }
    else if (degisken[4] == 1)
    {
        code = 4;
    }
    else if (degisken[3] == 1)
    {
        code = 3;
    }
    else if (degisken[2] == 1)
    {
        code = 2;
    }
    else if (degisken[1] == 1)
    {
        code = 1;
    }
    else if (degisken[0] == 1)
    {
        code = 0;
    }
    else
    {
        code = -1;
    }

    return code;
}
