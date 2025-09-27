//#define DELAY_COUNTER  500000L
#define DELAY_COUNTER 500L //simülasyon için
typedef enum{transfer, delay} states_type;

void debouncer(bool sw, bool &out)
{
    #pragma HLS INTERFACE ap_none port = sw
    #pragma HLS INTERFACE ap_none port = out
    #pragma HLS INTERFACE ap_ctrl_none port = return

    static states_type state = transfer;
    static long long int counter = DELAY_COUNTER;

    static bool previous_sw = 0;
    
    unsigned long long int next_counter;
    static states_type next_state;
    bool out_temp = 0;

    switch(state)
    {
        case transfer:
        if(previous_sw != sw)
        {
            next_state = delay;
        }
        else
        {
            next_state = transfer;
        }
        next_counter = DELAY_COUNTER;
        out_temp = sw;
        break;

        case delay:
        if(counter == 0)
        {
            next_state = transfer;
            next_counter = DELAY_COUNTER;
        }
        else
        {
            next_counter = counter - 1;
            next_state = delay;
        }
        out_temp = previous_sw;
        break;

        default:
        break;
    }

    previous_sw = out_temp;
    state = next_state;
    counter = next_counter;
    out = out_temp;

}
