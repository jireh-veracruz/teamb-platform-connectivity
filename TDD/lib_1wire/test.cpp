// Default include file
#include "CppUTest/TestHarness.h"
#include <iostream>

extern "C" {
    #include "handshake.h"
    #include "hal_comms.h"
    #include "common.h"
}

TEST_GROUP(handshake_test_group)
{
    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(handshake_test_group, init_handshake)
{
    init_handshake();
}