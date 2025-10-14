# Create the executable for Cortex-M4
add_executable(connectivityBoard_CM4
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_SOURCE_DIR}/source/bsp/stm32/stm32mp1/CM4/startup_stm32mp15xx.s
    ${CMAKE_SOURCE_DIR}/source/bsp/stm32/stm32mp1/system_stm32mp1xx.c
    ${CMAKE_SOURCE_DIR}/source/bsp/stm32/syscalls.c
)

# Link the mqtt and wifi libraries
target_link_libraries(connectivityBoard_CM4 PRIVATE
    commons
)

# Set linker script
set_target_properties(connectivityBoard_CM4 PROPERTIES 
    LINK_FLAGS "-T${CMAKE_SOURCE_DIR}/source/bsp/stm32/stm32mp1/CM4/STM32MP15_CM4.ld"
)

# Include directories
target_include_directories(connectivityBoard_CM4 PRIVATE
    ${CMAKE_SOURCE_DIR}/source/bsp/stm32/stm32mp1
    ${CMAKE_SOURCE_DIR}/vendors/platform-commons/common
)

# Add Output Format Targets
add_custom_command(TARGET connectivityBoard_CM4 POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary connectivityBoard_CM4 connectivityBoard_CM4.bin
    COMMAND ${CMAKE_OBJCOPY} -O ihex connectivityBoard_CM4 connectivityBoard_CM4.hex
)