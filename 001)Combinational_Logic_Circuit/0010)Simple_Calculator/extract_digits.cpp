#include "simple_calculator.h"

// sayısal bir sonucu 4 tane 4 bitlik segmente ayıran ve 7 displayde gösteren kod
uint10 div10(uint10 r)
{
    #pragma HLS INLINE off // bölme işlemi izole olsun
     return (r / 10);
}

void extract_digits
(
    bool hex_dec,
    int10 result,
    short int &d0,
    short int &d1,
    short int &d2,
    short int &d3
)
{
    short int sign = 0;
    uint10 r = result;
    if(result < 0)
    {
        sign = 1;
        r = -result;
    }
    else
    {
        sign = 0;
        r = result;
    }

    d0 = 0;
    d1 = 0;
    d2 = 0;
    d3 = 0;

    if(hex_dec == 0)
    {
        d0 = r - 10*div10(r); // birler basamağı
        r = r / 10;

        d1 = r - 10*div10(r); // onlar basamağı
        r = r / 10;

        d2 = r - 10*div10(r); // yüzler basamağı
    }
    else
    {
        d0 = r.range(3 ,0);
        d1 = r.range(7, 4);
        d2 = r.range(9, 8);

    }

    d3 = sign;
}