#ifndef __BIT_PRECISION_INITIALIZING_TB_H__ //bu iki satır bir "header guard"
#define __BIT_PRECISION_INITIALIZING_TB_H__ //"define" ve "ifndef" sayesinde aynı dosyanın birden fazla kez include olmasını engeller
#include "bit_precision_initializing.h"

void bit_precision_initializing(
    ap_int<41> &a1,
    ap_int<41> &a2,
    ap_int<41> &a3,
    ap_int<41> &a4,

    ap_int<763> &b1,
    ap_int<763> &b2,
    ap_int<763> &b3
);

#endif __BIT_PRECISION_INITIALIZING_TB_H__

