#include "dffs_tb.h"
#include <iostream>

int main()
{
    int status = 0;
    bool data, q1, q2, q3;

    std::cout << "d| q1, q2, q3" << "------------" <<std::endl;
    std:: cout << "--------------" << std::endl;

    data = 1;
    dffs(data, q1, q2, q3);
    std::cout << data << "| " << q1 << "," << q2 << "," << q3 << std::endl;

    data = 1;
    dffs(data, q1, q2, q3);
    std::cout << data << "| " << q1 << "," << q2 << "," << q3 << std::endl;

    data = 0;
    dffs(data, q1, q2, q3);
    std::cout << data << "| " << q1 << "," << q2 << "," << q3 << std::endl;

    data = 1;
    dffs(data, q1, q2, q3);
    std::cout << data << "| " << q1 << "," << q2 << "," << q3 << std::endl;

    data = 0;
    dffs(data, q1, q2, q3);
    std::cout << data << "| " << q1 << "," << q2 << "," << q3 << std::endl;

    return status;
}

