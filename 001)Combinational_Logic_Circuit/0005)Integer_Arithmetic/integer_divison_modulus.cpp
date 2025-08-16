const int n = 1234101;

int divbyconstant(int a)
{
    #pragma HLS INLINE off //burayı koymazsan sequential olur
    return a / n;
}

void integer_division_modulus(int a, int *r)
{
    #pragma HLS INTERFACE ap_none port = a
    #pragma HLS INTERFACE ap_none port = r
    #pragma HLS INTERFACE ap_ctrl_none port = return

    //*r = a%n;
    //*r = a - n*(a/n);

    *r = n*divbyconstant(a);
}