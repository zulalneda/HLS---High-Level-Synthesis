#include "state_machine_tb.h"
#include <iostream>

int main()
{
    int status = 0;

    ap_uint<4> x;
    bool enter = 1;
    bool door_open;
    bool lock = 0;
    ap_uint<8> seven_segment_data;
    ap_uint<4> seven_segment_enable;

    x = 1; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 2; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 3; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 1; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 2; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 3; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 4; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 6; enter = 0;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 6; enter = 0;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 6; enter = 0;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 6; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " << seven_segment_data.to_string() << std::endl;

    x = 1; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " << seven_segment_data.to_string() << std::endl;

    x = 2; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open <<  "seven _segment_data = "<< seven_segment_data.to_string() << std::endl;

    x = 2; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " << seven_segment_data.to_string() << std::endl;

    x = 2; enter = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 1; enter = 1; lock = 1;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    x = 1; enter = 1; lock = 0;
    state_machine(x, enter, door_open, lock, seven_segment_data, seven_segment_enable);
    std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << "seven _segment_data = " <<seven_segment_data.to_string() << std::endl;

    return status;
}