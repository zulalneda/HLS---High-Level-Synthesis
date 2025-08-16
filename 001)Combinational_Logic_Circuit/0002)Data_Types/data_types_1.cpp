#include "data_types_1" //fonksiyona hangi ismi vereceksek o

ap_uint<6> extract_opcode(ap_uint<32> instruction)
{
    return instruction(31,26);
}

ap_uint<5> extract_rs(ap_uint<32> instruction)
{
    return instruction(25,21);
}

ap_uint<5> extract_rd(ap_uint<32> instruction)
{
    return instruction(20,16);
}

ap_uint<16> extract_immediate(ap_uint<32> instruction)
{
    return instruction(15,0);
}

void data_types_1
(
    ap_uint<32> instruction,
    ap_uint<6> *opcode,
    ap_uint<5> *rs,
    ap_uint<5> *rd,
    ap_uint<16> *immediate
)
{
    #pragma HLS INTERFACE ap_none port = instruction
    #pragma HLS INTERFACE ap_none port = opcode
    #pragma HLS INTERFACE ap_none port = rs
    #pragma HLS INTERFACE ap_none port = rd
    #pragma HLS INTERFACE ap_none port = immediate
    #pragma HLS INTERFACE ap_ctrl_none port = return

    *opcode = extract_opcode(instruction);
    *rs = extract_rs(instruction);
    *rd = extract_rd(instruction);
    *immediate = extract_immediate(instruction);
}
