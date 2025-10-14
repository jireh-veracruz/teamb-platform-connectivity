# Create a static library for MQTT
add_library(wifi STATIC
    wifi.c
)

# Make the header available to other modules
target_include_directories(wifi PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
