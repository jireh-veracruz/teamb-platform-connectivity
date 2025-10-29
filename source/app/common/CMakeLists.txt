file(GLOB_RECURSE COMMON_SRC CONFIGURE_DEPENDS "*.c")
file(GLOB_RECURSE COMMON_HDR CONFIGURE_DEPENDS "*.h")

add_library(app_common STATIC ${COMMON_SRC})
target_include_directories(app_common PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/vendors/platform-commons/modules/common
    ${CMAKE_SOURCE_DIR}/vendors/platform-commons/modules/lib_teamb_handshake
)
