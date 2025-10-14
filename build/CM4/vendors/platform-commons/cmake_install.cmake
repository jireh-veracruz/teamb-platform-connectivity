# Install script for directory: /home/jnedic/workspace/testProjects/teamb-platform-connectivity/vendors/platform-commons

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/arm-none-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/can/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/common/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/dummy_server/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/hal_comms/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/lib_1wire/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/lib_rs485_handshake/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/lib_teamb_handshake/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/logger/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/rs485/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/rtc/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/thermoc/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/thermoc_i2c/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/xbee/cmake_install.cmake")
  include("/home/jnedic/workspace/testProjects/teamb-platform-connectivity/build/CM4/vendors/platform-commons/modules/zigbee/cmake_install.cmake")

endif()

