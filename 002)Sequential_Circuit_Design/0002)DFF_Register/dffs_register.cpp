#include "dffs_register.h"

void dffs_register(bool data, ap_uint<3> &q)
{
    #pragma HLS INTERFACE ap_none port = data
    #pragma HLS INTERFACE ap_none port = q
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static ap_uint<3> reg = 0b000;
    reg = reg >> 1; //sağa doğru 1 bit kaydır
    reg[2] = data; //MSB ye datayı ata

    q = reg;
}