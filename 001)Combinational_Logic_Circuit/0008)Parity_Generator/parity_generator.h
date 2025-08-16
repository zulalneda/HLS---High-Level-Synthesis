#ifndef __PARITY_GENERATOR_H__
#define __PARITY_GENERATOR_H__
#include <ap_int.h>

const int W = 16;
bool parity_generator(ap_uint<W> a);

#endif