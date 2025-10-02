// Default include file
#include "CppUTest/TestHarness.h"
#include <iostream>

extern "C" {
    #include "can.h"
}

TEST_GROUP(can_test_group)
{
    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(can_test_group, can_clear_bus)
{
    can_clear_bus();
}