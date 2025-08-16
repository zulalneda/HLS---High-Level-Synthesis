#include "uart_receiver_tb.h"
#include <iostream>

int main()
{
    int status = 0;

    bool uart_rx;
    bool baud_rate_signal;
    ap_uint<8> data;
    bool valid_data;

    uart_rx = 1;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 1;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 0;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 1;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 0;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 0;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 0;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 0;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 0;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 1;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 0;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 1;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 1;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    uart_rx = 1;
    baud_rate_signal = 1;
    uart_receiver(uart_rx, baud_rate_signal, data, valid_data);
    std::cout << " data = " << data << " | " << " valid_data = " << valid_data << std::endl;

    return status;

}