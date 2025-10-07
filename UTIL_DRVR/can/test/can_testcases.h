#ifndef __CAN_TESTCASES_H__
#ifndef __CAN_TESTCASES_H__
#ifndef __CAN_TESTCASES_H__




int test_table[] = {
//  input1  input2 output
    "ping", 0xFF, "pong",
    "png", 0xFF, "error",
    "ping1", 0xFF, "p0ng",
    "ping23", 0xFF, "pong",
    "ping", 0x00, "pong",
    "ping", NULL, "p1ng", 
}


int test_table[] = {
//  input1  input2 expected output
    10,   0xAA,     40
    "help", 0xAA,   "error"
}




currentmsg = get_can_data()




actual_output = plus_30(currentmsg)




sendwifi(tosendwifi);
