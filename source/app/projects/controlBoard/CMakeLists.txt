cmake_minimum_required(VERSION 3.10)
project(controlBoard C)
enable_language(ASM)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Add the executable
add_executable(controlBoard 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_SOURCE_DIR}/source/bsp/stm32/stm32h7/startup_stm32h743xx.S
    ${CMAKE_SOURCE_DIR}/source/bsp/stm32/syscalls.c)
# Include directories
include_directories(${CMAKE_SOURCE_DIR})

target_link_options(controlBoard PRIVATE
    "-T${CMAKE_SOURCE_DIR}/source/bsp/stm32/stm32h7/STM32H743XI_FLASH.ld"
    "-specs=nano.specs"
    "-specs=nosys.specs"
    "-Wl,--gc-sections"
)

# Add Output Format Targets
add_custom_command(TARGET controlBoard POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary controlBoard controlBoard.bin
    COMMAND ${CMAKE_OBJCOPY} -O ihex controlBoard controlBoard.hex
)