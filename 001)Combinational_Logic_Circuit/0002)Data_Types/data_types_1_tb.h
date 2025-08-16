#ifndef __DATA_TYPES_1_TB__
#define __DATA_TYPES_1_TB__

#include "data_types_1.h"

void data_types_1(
    ap_uint<32> instruction,
    ap_uint<6> *opcode,
    ap_uint<5> *rs,
    ap_uint<5> *rd,
    ap_uint<16> *immediate
);

#endif 
