# Ensure this file is always processed
file(GLOB_RECURSE MQTT_SRC CONFIGURE_DEPENDS "*.c")

add_library(mqtt STATIC ${MQTT_SRC})

target_include_directories(mqtt PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
