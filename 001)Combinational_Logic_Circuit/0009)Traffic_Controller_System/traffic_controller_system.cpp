// rule 1: //EW
bool rule_1(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor)
{
    return l_sensor && r_sensor;
}

// rule 2: //EW
bool rule_2(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor)
{
    return (l_sensor ^ r_sensor) || (u_sensor ^ d_sensor);
}

// rule 3: //NS
bool rule_3(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor)
{
    return (u_sensor && d_sensor) && !(l_sensor && r_sensor);
}

// rule 4: //NS
bool rule_4(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor)
{
    return (u_sensor ^ d_sensor) && !(l_sensor || r_sensor);
}

// rule 5: //EW
bool rule_5(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor)
{
    return !(l_sensor || r_sensor) && !(u_sensor || d_sensor);
}

void traffic_controller_system(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor, bool *EW, bool *NS)
{
#pragma HLS INTERFACE ap_none port = l_sensor
#pragma HLS INTERFACE ap_none port = r_sensor
#pragma HLS INTERFACE ap_none port = u_sensor
#pragma HLS INTERFACE ap_none port = d_sensor
#pragma HLS INTERFACE ap_none port = EW
#pragma HLS INTERFACE ap_none port = NS
#pragma HLS INTERFACE ap_ctrl_none port = return

    // ara sinyaller // rule ları tanıt
    bool ew_rule_1 = rule_1(l_sensor, u_sensor, d_sensor, r_sensor);
    bool ew_rule_2 = rule_2(l_sensor, r_sensor, u_sensor, d_sensor);
    bool ew_rule_3 = rule_5(l_sensor, r_sensor, u_sensor, d_sensor);

    bool ns_rule_1 = rule_3(l_sensor, d_sensor, u_sensor, r_sensor);
    bool ns_rule_2 = rule_4(l_sensor, u_sensor, r_sensor, d_sensor);

    *EW = ew_rule_1 || ew_rule_2 || ew_rule_3;
    *NS = ns_rule_1 || ns_rule_2;
}