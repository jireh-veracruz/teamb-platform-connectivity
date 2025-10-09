# Add subdirectories for modules
add_subdirectory(mqtt)
add_subdirectory(wifi)

# Create the executable for Cortex-A7
add_executable(connectivityBoard_CA7
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_SOURCE_DIR}/BSP/stm32/stm32mp1/CA7/startup.s
    ${CMAKE_SOURCE_DIR}/BSP/stm32/syscalls.c
)

# Link the mqtt and wifi libraries
target_link_libraries(connectivityBoard_CA7 PRIVATE
    mqtt
    wifi
    util_drvr
)

# Include headers from mqtt and wifi
target_include_directories(connectivityBoard_CA7 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/mqtt
    ${CMAKE_CURRENT_SOURCE_DIR}/wifi
    ${CMAKE_SOURCE_DIR}/UTIL_DRVR/common/
)

# # Add Output Format Targets
# add_custom_command(TARGET connectivityBoard_CA7 POST_BUILD
#     COMMAND ${CMAKE_OBJCOPY} -O binary connectivityBoard_CA7 connectivityBoard_CA7.bin
#     COMMAND ${CMAKE_OBJCOPY} -O ihex connectivityBoard_CA7 connectivityBoard_CA7.hex
# )