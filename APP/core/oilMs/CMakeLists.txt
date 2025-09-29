cmake_minimum_required(VERSION 3.10)
project(oilMs C)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Add the executable
add_executable(oilMs_exec main.c)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})