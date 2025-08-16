#include "state_machine.h"

typedef enum
{
    s0,
    s2,
    s23,
    s234,
    s2346
} state_type;

ap_uint<8> get_seven_segment_code(state_type number)
{
#pragma HLS INLINE
    ap_uint<8> code = seven_segment_code[0];

    switch (number)
    {
    case s0:
        code = seven_segment_code[0];
        break;

    case s2:
        code = seven_segment_code[1];
        break;

    case s23:
        code = seven_segment_code[2];
        break;

    case s234:
        code = seven_segment_code[3];
        break;

    case s2346:
        code = seven_segment_code[4];
        break;

    default:
    break;
    }
    
    return code;
}


void state_machine
(
    ap_uint<4> x,
    bool enter,
    bool &door_open,
    bool lock,
    ap_uint<8> &seven_segment_data,
    ap_uint<4> &seven_segment_enable
)
{
    #pragma HLS INTERFACE ap_none port = x
    #pragma HLS INTERFACE ap_none port = enter
    #pragma HLS INTERFACE ap_none port = door_open
    #pragma HLS INTERFACE ap_none port = lock
    #pragma HLS INTERFACE ap_none port = seven_segment_data
    #pragma HLS INTERFACE ap_none port = seven_segment_enable
    #pragma HLS INTERFACE ap_ctrl_none port = return

    
    static state_type state = s0; // başlangıç
    state_type next_state;

    bool door_open_local = 0; // geçici bir değer, döngü tamamlanınca "1" yanacak

    switch(state)
    {
        case s0:
        if(enter == 1)
        {
            if(x == 2)
            {
                next_state = s2;
            }
            else
            {
                next_state = s0;
            }
        }
        else
        {
            next_state = s0;
        }
        door_open_local = 0;
        break;

        case s2:
        if(enter == 1)
        {
            if(x == 3)
            {
                next_state = s23;
            }
            else
            {
                next_state = s0;
            }
        }
        else
        {
            next_state = s2;
        }
        door_open_local = 0;
        break;

        case s23:
        if(enter == 1)
        {
            if(x == 4)
            {
                next_state = s234;
            }
            else
            {
                next_state = s0;
            }
        }
        else
        {
            next_state = s23;
        }
        door_open_local = 0;
        break;

        case s234:
        if(enter == 1)
        {
            if(x == 6)
            {
                next_state = s2346;
            }
            else
            {
                next_state = s0;
            }
        }
        else
        {
            next_state = s234;
        }
        door_open_local = 0;
        break;

        case s2346:
        if(lock == 1)
        {
            next_state = s0;
            door_open_local = 0;
        }
        else
        {
            next_state = s2346;
            door_open_local = 1;
        }
        break;

        default:
        break;
    }


    state = next_state;
    door_open = door_open_local;

    seven_segment_data = get_seven_segment_code(state);
    seven_segment_enable = 0b1110;

}

