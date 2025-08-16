#pragma once
#include "uart_transmitter.h"
void uart_transmitter(bool &uart_tx, ap_uint<8> data, bool baud_rate_signal, bool start);