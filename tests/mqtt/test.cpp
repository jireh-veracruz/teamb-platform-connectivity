#include "CppUTest/TestHarness.h"

extern "C" {
    #include "mqtt.h"
}

// Create a test group
TEST_GROUP(mqtt_test_group) {
    void setup() {
        // Initialize before each test
    }

    void teardown() {
        // Deinitialize after each test
    }
};

// Test the mqtt function
TEST(mqtt_test_group, simple_test) {
    char msg[20] = "Hello World!";
    print_message(msg); 
    // If we get here without crashing, test passes
    CHECK(true);
}