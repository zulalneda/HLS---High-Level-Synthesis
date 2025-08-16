#include "dffs_register_tb.h"
#include <iostream>

int main()
{
    int status = 0;

    bool data;
    ap_uint<3> q;

    std::cout << "data,q" << std::endl;

    data = 1;
    dffs_register(data, q);
    std::cout << data << "," << q.to_string() << std::endl;

    data = 0;
    dffs_register(data, q);
    std::cout << data << "," << q.to_string() << std::endl;

    data = 1;
    dffs_register(data, q);
    std::cout << data << "," << q.to_string() << std::endl;

    data = 0;
    dffs_register(data, q);
    std::cout << data << "," << q.to_string() << std::endl;

    data = 1;
    dffs_register(data, q);
    std::cout << data << "," << q.to_string() << std::endl;

    
    return status;
}