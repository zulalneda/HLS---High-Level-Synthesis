int mult_lut(int a, int b)
{
    #pragma HLS INLINE off
    int t = a*b; // a * b çarpmasını LUT ile yapılan bir çarpma olarak zorla. Ve bu çarpmayı ayrı bir fonksiyonda tanımlayarak tekrar tekrar kullanabilir hale getir.
    #pragma HLS RESOURCE variable = t core = Mul_LUT

    return t;
}

void resource_constraint(int a, int b, int c, int d, int *f)
{
    #pragma HLS INTERFACE ap_none port = a
    #pragma HLS INTERFACE ap_none port = b
    #pragma HLS INTERFACE ap_none port = c
    #pragma HLS INTERFACE ap_none port = d
    #pragma HLS INTERFACE ap_none port = f
    #pragma HLS INTERFACE ap_ctrl_none port = return
/*
    *f = a*b + a*c + a*d + a*b*c*d; 
    böyle yazınca sadece LUTs ile çalışmıyor, DSPs de kullanıyor.(9 tane)
    DSP kullanmamak için tüm matematik işlemlerini ayrı olarak tanımlamak gerekir
*/

    int temp1 = a*b;
    int temp2 = a*c;
    int temp3 = a*d;
    int temp4 = c*d;

    int temp5 = temp1*temp4; // a*b*c*d
    
    int temp6 = temp1 + temp2; // a*b + a*c
    int temp7 = temp5 + temp3; // a*b*c*d + a*d

    #pragma HLS RESOURCE variable = temp1 core = Mul_LUT
    #pragma HLS RESOURCE variable = temp2 core = Mul_LUT
    #pragma HLS RESOURCE variable = temp3 core = Mul_LUT
    #pragma HLS RESOURCE variable = temp4 core = Mul_LUT
    #pragma HLS RESOURCE variable = temp5 core = Mul_LUT

    *f = temp7 + temp6; // a*b + a*c + a*d + a*b*c*d
    
}