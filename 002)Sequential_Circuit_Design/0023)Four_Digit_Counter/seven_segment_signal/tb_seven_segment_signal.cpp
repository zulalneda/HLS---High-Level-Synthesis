#include "tb_seven_segment_signal.h"
#include <iostream>
const int SIGNAL_PERIOD = 400000;
//const int SIGNAL_PERIOD = 10; //for simulation

int main()
{
    int status = 0;
    bool out_signal;

    std::cout << "----------" << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < 10 * SIGNAL_PERIOD; i++)
    {
        seven_segment_signal(out_signal);
        std::cout << out_signal;
    }

    std::cout << std::endl;
    std::cout << "----------" << std::endl;

    return status;
}
