#include "pulse_generator.h"

typedef enum{w1, w0} pulse_gen_states_type;

//w1 = giriş düşükken bekleme
//w0 = giriş yüksekken bekleme

void pulse_generator(bool input, bool &pulse)
{
    #pragma HLS INTERFACE ap_none port = input
    #pragma HLS INTERFACE ap_none port = pulse
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static pulse_gen_states_type state = w1;
    pulse_gen_states_type next_state;
    bool next_pulse;

    switch(state)
    {
        case w1:
        if(input == 1) //pulse üret ve yükselen kenara geç
        {
            next_state = w0;
            next_pulse = 1;
        }
        else //pulse üretme, bu kenar değil
        {
            next_state = w1;
            next_pulse = 0;
        }
        break;

        case w0:
        if(input == 1) //hala tuş basılı, aynı durumda kal. Pulse ÜRETME!
        {
            next_state = w0;
            next_pulse = 0;
        }
        else //tuş bırakıldı. Tekrar kenar aramak için w1 e geç
        {
            next_state = w1;
            next_pulse = 0;
        }
        break;

        default:
        break;
    }

    state = next_state;
    pulse = next_pulse;
}