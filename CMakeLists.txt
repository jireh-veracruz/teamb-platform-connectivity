cmake_minimum_required(VERSION 3.13)
project(teamb_platform_control_board)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(APP)
add_subdirectory(BSP)
add_subdirectory(CUSTOM)
add_subdirectory(UTIL_DRVR)
