#include "pwm.h"

//divisor = pwm periyodunun uzunluğu (toplam kaç clock sürecek)
//duty_cycle = pwm içinde ne kadar süre "1" olacak
//start = yeni bir döngü başlatılacak mı

typedef enum {zero, one} clock_state_type;
void pwm(ap_uint<16> divisor, ap_uint<16> duty_cycle, bool start, bool &slow_clock_signal)
{
    #pragma HLS INTERFACE ap_none port = divisor
    #pragma HLS INTERFACE ap_none port = duty_cycle
    #pragma HLS INTERFACE ap_none port = start
    #pragma HLS INTERFACE ap_none port = slow_clock_signal
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static clock_state_type state = zero;
    static unsigned int one_counter = 0;
    static unsigned int zero_counter = 0;

    clock_state_type next_state;
    unsigned int next_one_counter;
    unsigned int next_zero_counter;

    bool slow_clock_signal_local;

    switch(state)
    {
        case zero:
        if(zero_counter == 0) //counter 0'a ulaşmışsa artık "1" üretmeye başla
        {
            next_zero_counter = divisor - duty_cycle - 1; //0'ların sayısı
            next_state = one;
        }
        else //değilse 0'a kadar bekle
        {
            next_zero_counter = zero_counter - 1;
            next_state = zero;
        }
        slow_clock_signal_local = 0;
        next_one_counter = duty_cycle - 1;
        break;

        case one:
        if(one_counter == 0) //bir üretme süresi bitti mi? 0'a geç
        {
            next_one_counter = duty_cycle - 1;
            next_state = zero;
        }
        else
        {
            next_one_counter = one_counter - 1;
            next_state = one;
        }
        slow_clock_signal_local = 1;
        next_zero_counter = divisor - duty_cycle - 1;
        break;
    }

    state = next_state;
    if(start == 1) //start = 1 ise PWM üreticisi sıfırlanıyor. Yeni bir periyot başlıyor.
    {
        one_counter = (duty_cycle - 1);
        zero_counter = (divisor - duty_cycle - 1);
    }
    else //yoksa counter'lar kaldığı yerden devam ediyor
    {
        one_counter = next_one_counter;
        zero_counter = next_zero_counter;
    }

    slow_clock_signal = slow_clock_signal_local;
}

/*
örnek: 
divisor = 10
duty_cycle = 3
1 periyor 10 clock sürecek. 3 clock boyunca 1, 7 clock boyunca 0 olacak.
1110000000 1110000000 ... gibi
*/