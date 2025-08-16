//Design clock, genellikle yüksek frekanslıdır ve düşük hızı sebebiyle UART transmission hattı üzerinden veri göndermek için KULLANILAMAZ.
// Bu nedenle daha düşük frekanslı başka bir saat sinyali kullanılmalıdır.
// Ayrı bir IP olara veya UART modülüne dahil olarak üretilebilir.
// Ayrı olarak ürettim çünkü tasarım akışı ve hata ayıklama daha yönetilebilir oluyor.

#include "baud_rate_generator.h"

#define BAUD_RATE_NUMBER 10416 //9600 baud rate --> BAUD_RATE_NUMBER = (1s/9600)/10ns = (1000000000/9600)/10 = 10416

//#define BAUD_RATE_NUMBER 20 //for simulation

typedef enum{zero, one} state_type;

void baud_rate_generator(bool &baud_rate_signal)
{
    #pragma HLS INTERFACE ap_none port = baud_rate_signal
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static state_type state = zero;
    static unsigned int counter = BAUD_RATE_NUMBER - 1;

    state_type next_state;
    unsigned int next_counter;

    bool baud_rate_signal_local;

    switch(state)
    {
        case zero: //Sayaç 1’e gelene kadar baud_rate_signal = 0 döner.
        if(counter == 1)
        {
            next_counter = counter - 1;
            next_state = one;
        }
        else
        {
            next_counter = counter - 1;
            next_state = zero;
        }
        baud_rate_signal_local = 0;
        break;

        case one: //bir adet clock süresi boyunca pulse üretir. Sonra tekrar zero’ya geçer.
        next_counter = BAUD_RATE_NUMBER - 1;
        next_state = zero;
        baud_rate_signal_local = 1;
        break;

        default:
        break;
    }

    state = next_state;
    counter = next_counter;
    baud_rate_signal = baud_rate_signal_local;
}
