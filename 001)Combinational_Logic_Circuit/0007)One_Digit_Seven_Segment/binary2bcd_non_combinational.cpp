void binary2bcd_non_combinational(int binary, int *bcd)
{
    #pragma HLS INTERFACE ap_none port = binary
    #pragma HLS INTERFACE ap_none port = bcd
    #pragma HLS INTERFACE ap_ctrl_none port = return

    int i = 0;
    while (binary != 0)
    {
        bcd[i] = binary %10; //BCD'nin i. basamağı // combinational DEĞİL!!
        binary = binary / 10;
        i++; //0. basamaktan sayının kendisine doğru gidiyor
    }
}