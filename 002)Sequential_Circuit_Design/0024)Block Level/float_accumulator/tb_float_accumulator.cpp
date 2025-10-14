#include <iostream>
#include <stdlib.h>
#include "tb_float_accumulator.h"

const int N = 10;

void float_accumulator_golden(DATATYPE *d, DATATYPE &acc)
{
    acc = 0;
    for (int i = 0; i < N; i++)
    {
        acc += d[i];
    }
}

int main()
{
    int status = 0;

    DATATYPE data[10] =
        {
            6.23,
            7.39,
            8.49,
            1.22,
            3.98,
            5.64,
            4.99,
            7.29,
            0.81,
            4.31
        };
        
    DATATYPE acc_golden = 0;
    DATATYPE acc_hw = 0;

    std::cout << "------------------------" << std::endl;

    for(int i = 0; i < N; i++)
    {
        float_accumulator(data[i], acc_hw);
        std::cout << "acc_hw = " << acc_hw << std::endl;
    }

    float_accumulator_golden(data, acc_golden);

    std::cout << "------------------------" << std::endl;
    std::cout << "acc_hw = " << acc_hw << "acc_golden = " << acc_golden << std::endl;

    if(acc_hw != acc_golden)
    {
        status = -1;
    }

    if(status == 0)
    {
        std::cout << "Test Passed!!!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed!!!" << std::endl;
    }

    return status;
}
