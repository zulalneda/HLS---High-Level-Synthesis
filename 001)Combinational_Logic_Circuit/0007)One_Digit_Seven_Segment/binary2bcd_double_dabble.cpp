#include "double_dabble.h"

void double_dabble(uint16 &scratch_pad)
{
    #pragma HLS INLINE //donanımda ayrı blok oluşturmak yerine kodu inline eder
    scratch_pad = scratch_pad << 1; //binary sayıdan 1 biti bcd2ye kaydır
    if(scratch_pad(11,8) > 4) //bcd'nin sağdaki 4 bitini ifade eder (küçük kısım)
        scratch_pad(11,8) = scratch_pad(11,8) + 3; // bcd değeri 5 veya 5ten büyükse 3 ekle

}

void binary2bcd_double_dabble(uint8 binary, uint16 *unpacked_bcd, uint8 *packed_bcd) //dışarıdan gelen 8 bitlik binary sayıyı hem packed hem de unpacked yapısına çevirir
{
    #pragma HLS INTERFACE ap_none port = binary
    #pragma HLS INTERFACE ap_none port = unpacked_bcd
    #pragma HLS INTERFACE ap_none port = packed_bcd
    #pragma HLS INTERFACE ap_ctrl_none port = return

    uint16 scratch_pad = binary; // 8 bitlik binary sayıyı 16 bitlik scratch pad'e atar
    uint4 zero_4 = 0b0000; // unpacked için lazım

    double_dabble(scratch_pad); // 7 kez double dabble uygula
    double_dabble(scratch_pad);
    double_dabble(scratch_pad);
    double_dabble(scratch_pad);

    double_dabble(scratch_pad);
    double_dabble(scratch_pad);
    double_dabble(scratch_pad);
    scratch_pad = scratch_pad << 1; // 8. biti doğrudan kaydır

    *packed_bcd = scratch_pad(15,8);
    *unpacked_bcd = (zero_4, scratch_pad(15,12), zero_4, scratch_pad(11,8));

}