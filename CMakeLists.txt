cmake_minimum_required(VERSION 3.13)
project(teamb_platform_control_board C ASM)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(TARGET_CORE STREQUAL "M4")
    message(STATUS "Configuring for Cortex-M4")
    add_subdirectory(APP/projects/connectivity/CM4)
    add_subdirectory(BSP/stm32/stm32mp1/CM4)
    add_subdirectory(${CMAKE_SOURCE_DIR}/VENDORS/platform-commons)
elseif(TARGET_CORE STREQUAL "A7")
    message(STATUS "Configuring for Cortex-A7")
    add_subdirectory(APP/projects/connectivity/CA7)
    add_subdirectory(BSP/stm32/stm32mp1/CA7)
    add_subdirectory(${CMAKE_SOURCE_DIR}/VENDORS/platform-commons)
else()
    message(FATAL_ERROR "Unknown TARGET_CORE: ${TARGET_CORE}")
endif()

# Add subdirectories
add_subdirectory(${CMAKE_SOURCE_DIR}/APP)
add_subdirectory(${CMAKE_SOURCE_DIR}/BSP)
add_subdirectory(${CMAKE_SOURCE_DIR}/CUSTOM)
