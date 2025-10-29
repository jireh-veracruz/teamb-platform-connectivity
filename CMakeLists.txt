cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME teamb_platform_control_board)
project(${PROJECT_NAME} C ASM)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(BOARD_PATH "${CMAKE_SOURCE_DIR}/board")
set(VENDOR_PATH "${CMAKE_SOURCE_DIR}/vendors")

add_executable(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/project/stm32mp1xx/${TARGET_CORE}/main.c")
message(STATUS main.c:"${CMAKE_SOURCE_DIR}/project/stm32mp1xx/${TARGET_CORE}/main.c")

if(${TARGET_CORE} STREQUAL "ca7")
    # Add subdirectories
    add_subdirectory(${CMAKE_SOURCE_DIR}/source/app)
    add_subdirectory(${VENDOR_PATH}/platform-commons)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        mqtt
    )
endif()

# Set linker script
target_link_options(${PROJECT_NAME} PRIVATE
    "-T${BOARD_PATH}/linker/${TARGET_CORE}/STM32MP15.ld"
)

# Startup and system files
target_sources(${PROJECT_NAME} PRIVATE
    "${BOARD_PATH}/startup/startup_stm32mp15_${TARGET_CORE}.s"
    "${BOARD_PATH}/system/system_stm32mp1xx.c"
    "${BOARD_PATH}/system/syscalls.c"
)
