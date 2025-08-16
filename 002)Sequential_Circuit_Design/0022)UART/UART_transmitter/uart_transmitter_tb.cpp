#include "uart_transmitter_tb.h"
#include <iostream>

int main()
{
    int status = 0;

    bool uart_tx;
    ap_uint<8> data = 0b01000001;
    bool baud_rate_signal;
    bool start;
    bool led;

    std::cout << " uart_tx = ";

    start = 0;
    baud_rate_signal = 0;
    uart_transmitter(uart_tx, data, baud_rate_signal, start);
    std::cout << uart_tx;

    start = 1;
    baud_rate_signal = 0;
    uart_transmitter(uart_tx, data, baud_rate_signal, start);
    std::cout << uart_tx;

    for(int i = 0; i < 20; i++)
    {
        start = 0;
        baud_rate_signal = 0;
        uart_transmitter(uart_tx, data, baud_rate_signal, start);
        std::cout << uart_tx;

        start = 0;
        baud_rate_signal = 1;
        uart_transmitter(uart_tx, data, baud_rate_signal, start);
        std::cout << uart_tx;
    }

    std::cout << std::endl;

    return status;
}