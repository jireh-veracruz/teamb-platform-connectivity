add_library(common_comm STATIC
    comms_handler.c
    rpmsg_comm.c
)

target_include_directories(common_comm PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/VENDORS/platform-commons/modules/common
    ${CMAKE_SOURCE_DIR}/VENDORS/platform-commons/modules/lib_teamb_handshake
)