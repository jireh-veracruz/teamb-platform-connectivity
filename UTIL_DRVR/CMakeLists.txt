file(GLOB_RECURSE UTIL_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/can/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib_1wire/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib_rs485_handshake/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/rtc/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/thermoc/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/xbee/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/zigbee/*.c
)

add_library(util_drvr STATIC ${UTIL_SRCS})

target_include_directories(util_drvr PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/can
    ${CMAKE_CURRENT_SOURCE_DIR}/lib_1wire
    ${CMAKE_CURRENT_SOURCE_DIR}/lib_rs485_handshake
    ${CMAKE_CURRENT_SOURCE_DIR}/rtc
    ${CMAKE_CURRENT_SOURCE_DIR}/thermoc
    ${CMAKE_CURRENT_SOURCE_DIR}/xbee
    ${CMAKE_CURRENT_SOURCE_DIR}/zigbee
)