#include "edge_detector_tb.h"
#include <iostream>

int main()
{
    int status = 0;

    bool input_signal;
    bool rising_edge;
    bool falling_edge;

    std::cout << "----------------" << std::endl;
   
    for(int i = 0; i < 10; i++)
    {
        input_signal = 0;
        edge_detector(input_signal,rising_edge,falling_edge);
        std::cout << " input_signal = " << input_signal << " rising_edge = " << rising_edge << " falling_edge = " << falling_edge << std::endl;
    }

    std::cout << "---" << std::endl;

    for(int i = 0; i < 10; i++)
    {
        input_signal = 1;
        edge_detector(input_signal,rising_edge,falling_edge);
        std::cout << " input_signal = " << input_signal << " rising_edge = " << rising_edge << " falling_edge = " << falling_edge << std::endl;
    }

    std::cout << "---" << std::endl;

    for(int i = 0; i < 10; i++)
    {
        input_signal = 0;
        edge_detector(input_signal,rising_edge,falling_edge);
        std::cout << " input_signal = " << input_signal << " rising_edge = " << rising_edge << " falling_edge = " << falling_edge << std::endl;
    }

    std::cout << "----------------" << std::endl;

    return status;
}