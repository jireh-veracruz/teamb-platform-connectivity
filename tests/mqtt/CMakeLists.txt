cmake_minimum_required(VERSION 3.10)
project(MqttTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall")

# Set CppUTest path (built from source in Docker)
set(CPPUTEST_HOME ${CMAKE_CURRENT_SOURCE_DIR}/../../tools/cpputest)

include_directories(${CPPUTEST_HOME}/include)
include_directories(../../source/app/projects/connectivity/CA7/mqtt)

add_executable(mqtt_tests
    test.cpp
    main.cpp
    ../../source/app/projects/connectivity/CA7/mqtt/mqtt.c)

target_link_libraries(mqtt_tests
    ${CPPUTEST_HOME}/lib/libCppUTest.a
    ${CPPUTEST_HOME}/lib/libCppUTestExt.a)