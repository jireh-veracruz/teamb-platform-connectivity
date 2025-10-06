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
    std::cout << "Test case: Read from CAN bus" << std::endl;
    char buffer[] = "Hello";
    int result = can_read_from_bus(buffer, 1);
    CHECK_EQUAL(-1, result);
}

TEST(can_test_group, can_clear_bus)
{
    std::cout << "Test case: Clear CAN bus" << std::endl;
    can_clear_bus();
}

TEST(can_test_group, can_write_to_bus)
{
    std::cout << "Test case: Write to CAN bus" << std::endl;
    char buffer[] = "Hello";
    int result = can_write_to_bus(buffer, 1);
    CHECK_EQUAL(0, result);
}

