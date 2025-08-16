#include "parallel2serial.h"
const int N = 8;

// Bu veriyi her clock'ta bir bit olarak sırayla data çıkışına veririz

void parallel2serial
(
    ap_uint<N> a,
    bool &data,
    bool &serial_start,
    bool &serial_end,
    bool begin
)
{
    #pragma HLS INTERFACE ap_none port = a
    #pragma HLS INTERFACE ap_none port = data
    #pragma HLS INTERFACE ap_none port = serial_start
    #pragma HLS INTERFACE ap_none port = serial_end
    #pragma HLS INTERFACE ap_none port = begin
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static int count = N;
    if (begin == 1) // Başlangıç sinyali geldiğinde sayacı sıfırla
    {
        count = 0;
    }

    if (count == 0) // ilk biti gönder
    {
        serial_start = 1;
        serial_end = 0;
        data = a[count++];
    }

    else if (count == N -1) // son biti gönder
    {
        serial_start = 0;
        serial_end = 1;
        data = a[count];
        count = N;
    }

    else if (count < N -1) // işlem devam ediyor
    {
        serial_start = 0;
        serial_end = 0;
        data = a[count++];
    }

    else
    {
        serial_start = 0;
        serial_end = 0;
        count = N;
    }


}