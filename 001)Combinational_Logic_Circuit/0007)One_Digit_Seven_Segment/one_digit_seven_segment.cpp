#include <ap_int.h>

void one_digit_seven_segment(ap_uint<8> digit, ap_uint<8> *code7segment, ap_uint<8> *anodes)
{
    #pragma HLS INTERFACE ap_none port = digit
    #pragma HLS INTERFACE ap_none port = code7segment
    #pragma HLS INTERFACE ap_none port = anodes
    #pragma HLS INTERFACE ap_ctrl_none port = return

    switch(digit)
    {
        case 0:
        *code7segment = 0b11000000; // ABCDEF yanıyor (active - low) G ile DP(decimal point) yanmıyor
        break;
        case 1:
        *code7segment = 0b11111001; // B ve C yanıyor
        break;
        case 2:
        *code7segment = 0b10100100; // A, B, D, E, G yanıyor
        break;
        case 3:
        *code7segment = 0b10110000; // A, B, C, D, G yanıyor
        break;
        case 4:
        *code7segment = 0b10011001; // B, C, F, G yanıyor
        break;
        case 5:
        *code7segment = 0b10010010; // A, C, D, F, G yanıyor
        break;
        case 6:
        *code7segment = 0b10000010; // A, C, D, E, F, G yanıyor
        break;
        case 7:
        *code7segment = 0b11111000; // A, B, C  yanıyor                     
        break;
        case 8:
        *code7segment = 0b10000000; // A, B, C
        break;
        case 9:
        *code7segment = 0b10010000; // A, B, C
        break;
        default:
        *code7segment = 0b11111111; // Tüm segmentler kapalı (error state)
        break;
    }

    *anodes = 0b11111110; // Anotlar aktif (active - low) 0. anode aktif
}