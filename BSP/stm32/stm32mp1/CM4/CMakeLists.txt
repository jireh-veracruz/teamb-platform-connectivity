# Create an object file from the startup assembly file
add_library(cm4_startup OBJECT startup_stm32mp15xx.s)

# Set linker script for Cortex-M4
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/STM32MP15_CM4.ld)

# Apply linker script to all targets
set_target_properties(cm4_startup PROPERTIES
    LINK_FLAGS "-T${LINKER_SCRIPT}")
