#include "data_types_1.h"
#include <iostream>

int main()
{
    int status = 0;

    ap_uint<32> instruction("11011001111100001010010111000011",2);
    ap_uint<6> opcode;
    ap_uint<5> rs;
    ap_uint<5> rd;
    ap_uint<16> immediate;

    data_types_1(instruction, opcode, rs, rd, immediate);

    std::cout << "instruction = " <<  instruction.to_string(2) << std::endl;
    std::cout << "opcode = " <<  opcode.to_string(2) << std::endl;
    std::cout << "source register = " <<  rs.to_string(2) << std::endl;
    std::cout << "destination register = " <<  rd.to_string(2) << std::endl;
    std::cout << "immediate = "  << immediate.to_string(2) << std::endl;

    printf("instruction = %s \n", instruction.to_string().c_str()); // default radix is 2
    printf("opcode = %s \n", opcode.to_string(2).c_str()); // veya
    printf("source register = %s \n", rs.to_string().c_str());
    printf("destination register = %s \n", rd.to_string().c_str());
    printf("immediate = %s \n", immediate.to_string().c_str());

    if(opcode != 0b110110 || rs != 0b01111 || rd != 0b00001 || immediate != 0b0100101110000011)
    {
        std::cout << " HATA: BEKLENMEYEN SONUC " << std::endl;
        status = 1;
    }

    return status;
}
