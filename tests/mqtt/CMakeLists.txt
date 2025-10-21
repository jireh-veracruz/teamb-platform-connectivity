cmake_minimum_required(VERSION 3.10)
project(MqttTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall")

message(STATUS CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR})
# Set CppUTest path (headers and libraries)
set(CPPUTEST_HOME ${CMAKE_SOURCE_DIR}/../../vendors/platform-commons/tests/cpputest)
message(STATUS CPPUTEST_HOME: ${CPPUTEST_HOME})

# Include CppUTest headers
include_directories(${CPPUTEST_HOME}/include)

# Include project-specific headers
include_directories(${CMAKE_SOURCE_DIR}/../../source/app/projects/connectivity/CA7/mqtt)

# Define test executable
add_executable(mqtt_tests
    test.cpp
    main.cpp
    ../../source/app/projects/connectivity/CA7/mqtt/mqtt.c)

# Link against CppUTest static libraries
target_link_libraries(mqtt_tests
    ${CPPUTEST_HOME}/lib/libCppUTest.a
    ${CPPUTEST_HOME}/lib/libCppUTestExt.a)
