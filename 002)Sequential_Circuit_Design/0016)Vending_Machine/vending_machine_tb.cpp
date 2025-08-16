#include "vending_machine_tb.h"
#include <iostream>

void put_coin(bool nickel_in, bool dime_in, bool quarter_in)
{
    bool thanks_in;
    bool candy_out;
    bool nickel_out;
    ap_uint<2> dime_out;

    vending_machine(nickel_in, dime_in, quarter_in, thanks_in, candy_out, nickel_out, dime_out);
    std::cout << "nickel_in = " << nickel_in << " dime_in = " << dime_in << " quarter_in = " << quarter_in << " | ";
    std::cout << "candy_out = " << candy_out << "nickel_out = " << nickel_out << " dime_out = " << dime_out.to_string() << std::endl;

    nickel_in = 0; dime_in = 0; quarter_in = 0; thanks_in = 0;
    int n = rand() % 10 + 2;
    for(int i = 0; i < n; i++)
    {
        vending_machine(nickel_in, dime_in, quarter_in, thanks_in, candy_out, nickel_out, dime_out);
        std::cout << "nickel_in = " << nickel_in << " dime_in = " << dime_in << " quarter_in = " << quarter_in << " | ";
        std::cout << "candy_out = " << candy_out << "nickel_out = " << nickel_out << " dime_out = " << dime_out.to_string() << std::endl;
    }

}

int main()
{
    int status = 0;

    bool nickel_in;
    bool dime_in;
    bool quarter_in;
    bool thanks_in;
    bool candy_out;
    bool nickel_out;
    ap_uint<2> dime_out;

    std::cout << "-------------" << std::endl;
    put_coin(0,0,0); // coin yok
    put_coin(0,1,0); // dime
    put_coin(0,1,0); // dime
    put_coin(0,0,1); // quarter


    return status;
}