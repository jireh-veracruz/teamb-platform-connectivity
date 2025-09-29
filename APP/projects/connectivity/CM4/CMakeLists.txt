# Create the executable for Cortex-M4
add_executable(connectivityBoard_CM4
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_SOURCE_DIR}/BSP/stm32/stm32mp1/CM4/startup_stm32mp15xx.s
    ${CMAKE_SOURCE_DIR}/BSP/stm32/syscalls.c
)

# Add Output Format Targets
add_custom_command(TARGET connectivityBoard_CM4 POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary connectivityBoard_CM4 connectivityBoard_CM4.bin
    COMMAND ${CMAKE_OBJCOPY} -O ihex connectivityBoard_CM4 connectivityBoard_CM4.hex
)