#pragma once
#include "parallel2serial_tb.h"
#include <iostream>
#define N 8

int main()
{
    int status = 0;
    ap_uint<N> in_parallel = 0b11010011;
    
    bool data;
    bool serial_start;
    bool serial_end;
    bool begin;

    ap_uint<N> output;

    begin = 0;
    parallel2serial(in_parallel, data, serial_start, serial_end, begin);

    begin = 1;
    for(int i = 0; i < N; i++)
    {
        parallel2serial(in_parallel, data, serial_start, serial_end, begin);
        begin = 0;
        std::cout << " data = " << data << "serial_start = " << serial_start << " serial_end = " << serial_end << std::endl;
        output[i] = data; 
    }

    if (in_parallel != output)
    {
        status = -1;
        std::cout << "ERROR = " << " in_parallel = " << in_parallel.to_string() << " output = " << output.to_string() << std::endl;
    }

    if(status == 0)
    {
        std::cout << "Test passed!" << std::endl;
    }
    else
    {
        std::cout <<" Test failed!" << std::endl;
    }


    return status;
}