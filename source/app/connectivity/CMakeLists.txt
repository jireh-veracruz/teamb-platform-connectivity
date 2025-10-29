file(GLOB_RECURSE CONNECTIVITY_SRC CONFIGURE_DEPENDS "*.c")
file(GLOB_RECURSE CONNECTIVITY_HDR CONFIGURE_DEPENDS "*.h")

add_library(connectivity STATIC ${CONNECTIVITY_SRC})
target_include_directories(connectivity PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/source/app/common
    ${CMAKE_SOURCE_DIR}/vendors/platform-commons/modules/common
    ${CMAKE_SOURCE_DIR}/vendors/platform-commons/modules/lib_teamb_handshake
)
