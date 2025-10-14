# Create an object file from the startup assembly file
add_library(ca7_startup OBJECT startup.s)

# Set linker script for Cortex-M4
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/linkscript.ld)

# Apply linker script to all targets
set_target_properties(ca7_startup PROPERTIES
    LINK_FLAGS "-T${LINKER_SCRIPT}")
