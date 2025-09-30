cmake_minimum_required(VERSION 3.10)
project(handshake_app C)

set(CMAKE_C_STANDARD 99)

# Correct base path
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR}/../../../teamb-platform-control-board)

add_compile_definitions(CAN_BUS)

# Define source and header paths
set(HANDSHAKE_SRC_DIR ${PROJECT_ROOT}/UTIL_DRVR/lib_teamb_handshake)
set(COMMON_DIR ${PROJECT_ROOT}/UTIL_DRVR/common)
set(CAN_DIR ${PROJECT_ROOT}/UTIL_DRVR/can)
set(HAL_COMMS ${PROJECT_ROOT}/APP/projects/connectivity/hal)

# Include header directories
include_directories(
    ${PROJECT_ROOT}         # for connect01_tree.h
    ${HANDSHAKE_SRC_DIR}    # for handshake.h
    ${COMMON_DIR}           # for common.h
    ${CAN_DIR}              # for can.h
    ${HAL_COMMS}            # for hal_comms.h
)

# Add source files
add_executable(handshake_app
    ${CMAKE_SOURCE_DIR}/main.c
    ${CMAKE_SOURCE_DIR}/handshake_prints.c
    ${HANDSHAKE_SRC_DIR}/handshake.c
    ${HAL_COMMS}/hal_comms.c
)

# Add compiler warnings
target_compile_options(handshake_app PRIVATE -Wall -Wextra)