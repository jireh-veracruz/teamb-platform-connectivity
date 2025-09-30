


#include "common.h"
#include "test/teamb_handshake.h"
#include "handshake.h"


int main(void)
{
    char buff[TEST_MAX_CTR];
    int testpass = 0;
    int testctr = 0;

    for(testctr = 0; testctr < TEST_MAX_CTR; testctr++)
    {
        //teamb_handshake_receive_data()
        teamb_handshake_send_data( test_table + testctr, test_table + testctr + 1 );

        teamb_handshake_receive_data( buff, 0 );
        if(buff[0] == (test_table + testctr + 4))
        {
            testpass++;
        }
    }
    



    return 0;
}