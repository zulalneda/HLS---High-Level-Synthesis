#pragma once
#include "uart_receiver.h"

void uart_receiver(bool uart_rx, bool baud_rate_signal, ap_uint<8> &data, bool &valid_data);