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

TEST(can_test_group, can_read_from_bus)
{
    char buffer[] = "Hello";
    int result = can_read_from_bus(buffer, 1);
    CHECK_EQUAL(0, result);
}

TEST(can_test_group, can_clear_bus)
{
    can_clear_bus();
}

TEST(can_test_group, can_write_to_bus)
{
    char buffer[] = "Hello";
    int result = can_write_to_bus(buffer, 1);
    CHECK_EQUAL(0, result);
}

