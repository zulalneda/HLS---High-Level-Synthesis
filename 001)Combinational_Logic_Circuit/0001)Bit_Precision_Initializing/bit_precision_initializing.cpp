#include "bit_precision_initializing.h"

void bit_precision_initializing(
    ap_int<41> &a1, // -2^40 < ...< 2^40 -1 (alabileceği değerler)
    ap_int<41> &a2,
    ap_int<41> &a3,
    ap_int<41> &a4,

    ap_int<763> &b1,  // -2^762 < ... < 2^762 - 1 (alabileceği değerler)
    ap_int<763> &b2,
    ap_int<763> &b3
)

{
    #pragma HLS INTERFACE ap_none port = a1
    #pragma HLS INTERFACE ap_none port = a2
    #pragma HLS INTERFACE ap_none port = a3
    #pragma HLS INTERFACE ap_none port = a4

    #pragma HLS INTERFACE ap_none port = b1
    #pragma HLS INTERFACE ap_none port = b2
    #pragma HLS INTERFACE ap_none port = b3

    #pragma HLS INTERFACE ap_ctrl_none port = return

    //04017 = (1 x 7) + (8 x 1) + (64 x 0) + (512 x 4) = 2063(oktal)

    a1 = 04017; // başındaki "0", 8'lik tabanda olduğunu gösteriyor (güvenli)
    a2 = ap_int<41>("4017", 8); //sayıyı direkt hem kendisi hem de tabanoyla ifade etmiş (güvenli)
    a3 = ap_int<41>("0o4017"); 
    a4 = ap_int<41>("0o4017",8);

    b1 = ap_int<763>("401740174017401740174017",16); // güvenli
    b2 = ap_int<763>("0x401740174017401740174017");
    b3 = ap_int<763>("0x401740174017401740174017",16); // en güvenlisi
}