# Create a static library for MQTT
add_library(mqtt STATIC
    mqtt.c
)

# Make the header available to other modules
target_include_directories(mqtt PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
