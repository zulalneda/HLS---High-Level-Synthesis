#include "dot_product_tb.h"
#include <iostream>

DATA_TYPE golden_dot_product(DATA_TYPE *x, DATA_TYPE *y, int n)
{
    DATA_TYPE d = 0;
    for(int i = 0; i < n; i++)
    {
        d += x[i]*y[i];
    }

    return d;
}

int main()
{
    int status = 0;
    int n = 4;
    DATA_TYPE *x_data = new int[n];
    DATA_TYPE *y_data = new int[n];

    for(int i = 0; i < n; i++)
    {
        x_data[i] = rand()%100;
        y_data[i] = rand()%100;
    }

    DATA_TYPE x;
    DATA_TYPE y;
    bool start;
    bool input_vld;
    DATA_TYPE d;
    bool d_vld;
    DATA_TYPE d_golden;
    DATA_TYPE d_hardware;

    for(int i = 0; i < n ; i++)
    {
        x = x_data[i];
        y = y_data[i];

        input_vld = 1;
        dot_product(x, y, i, input_vld, d);

        for(int j = 0; j < 4; j++)
        {
            dot_product(x, y, i, 0, d);
        }

        std::cout << "x = " << x << " y = " << y << " i = " << i << " input_vld = " << input_vld << " d = " << d << std::endl;
    }

    d_golden = golden_dot_product(x_data,y_data,n);

    if(d != d_golden)
    {
        status = -1;
        std::cout << " ERROR! d_hardware =  " << d_hardware << " d_golden = " << d_golden << std::endl; 
    }

    if(status == 0)
    {
        std::cout << "Test Passed!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed!" << std::endl;
    }

    return status;
}