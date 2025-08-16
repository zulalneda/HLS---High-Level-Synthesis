#pragma once
#include "vending_machine.h"
void vending_machine(
    bool nickel_in,
    bool dime_in,
    bool quarter_in,
    bool thanks_in,
    bool &candy_out,
    bool &nickel_out,
    ap_uint<2> &dime_out
);