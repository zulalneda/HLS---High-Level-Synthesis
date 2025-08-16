#include "uart_receiver.h"

typedef enum {idle, recieve} state_type;

void uart_receiver(bool uart_rx, bool baud_rate_signal, ap_uint<8> &data, bool &valid_data)
{
    #pragma HLS INTERFACE ap_none port = uart_rx
    #pragma HLS INTERFACE ap_none port = baud_rate_signal
    #pragma HLS INTERFACE ap_none port = data
    #pragma HLS INTERFACE ap_none port = valid_data
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static ap_uint<8> d;
    static unsigned int bit_counter = 0;
    static state_type state = idle;

    state_type next_state;
    unsigned int next_bit_counter;

    bool stop_bit;
    bool valid_data_local = 0;

    switch(state)
    {
        case idle:
        if(baud_rate_signal == 1)
        {
            if(uart_rx == 0)
            {
                next_state = recieve;
            }
            else
            {
                next_state = idle;
            }
        }
        else
        {
            next_state = idle;
        }
        valid_data_local = 0;
        next_bit_counter = 0;
        break;

        case recieve:
        if(baud_rate_signal == 1)
        {
            if(bit_counter == 8)
            {
                stop_bit = uart_rx;
                if(stop_bit == 1)
                {
                    valid_data_local = 1;
                }
                else
                {
                    valid_data_local = 0;
                }
                next_bit_counter = 0;
                next_state = idle;
            }
            else
            {
                d[bit_counter] =uart_rx;
                next_bit_counter = bit_counter + 1;
                next_state = state;
                valid_data_local = 0;
            }
        }
        else
        {
            valid_data_local = 0;
            next_state = recieve;
            next_bit_counter = bit_counter;
        }
        break;

        default:
        break;
    }

    state = next_state;
    bit_counter = next_bit_counter;
    data = d;
    valid_data = valid_data_local;
}