#include "serial2parallel_tb.h"
#include <iostream>
const int N = 8;

int main()
{
    int status = 0;
    ap_uint<N> target = 0b10011011;
    ap_uint<N> a;
    bool start_serial_data;
    bool end_conversion;
    bool data;

    std::cout << std::endl;;
    start_serial_data = 0;
    serial2parallel(start_serial_data, end_conversion, target, a);

   
    start_serial_data = 1;
	for (int i = 0; i <200; i++) 
    {
		data= target[i];
		serial2parallel(start_serial_data, end_conversion, data, a);
		start_serial_data = 0;
		if (end_conversion == 1) {
			std::cout << a.to_string() << std::endl;
			break;
		}
	}

	if (target != a)
    {
		status = -1;
		std::cout << "  target = " << target.to_string() << " a = " << a.to_string() << std::endl;
	}


	if (status == 0) {
		std::cout << "Test Passed" << std::endl;
	} else {
		std::cout << "Test Failed" << std::endl;
	}

	return status;
}