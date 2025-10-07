# Silence makefile
# SILENCE = @
# Name of component under test
# Change the name depending on the specific folder of the files to be tested.
COMPONENT_NAME=lib_teamb_handshake
PARENT_FOLDER_NAME=UTIL_DRVR
FOLDER_NAME=lib_teamb_handshake

# Flags for CppUTest to ignore warnings and unused variables
CPPUTEST_WARNINGFLAGS += -Wall
CPPUTEST_WARNINGFLAGS += -Werror
CPPUTEST_WARNINGFLAGS += -Wno-int-to-pointer-cast
# CPPUTEST_WARNINGFLAGS += -Wfatal-errors
# CPPUTEST_WARNINGFLAGS += -Wswitch-default
CPPUTEST_WARNINGFLAGS += -Wno-format-nonliteral
CPPUTEST_WARNINGFLAGS += -Wno-sign-conversion
CPPUTEST_WARNINGFLAGS += -Wno-pedantic
CPPUTEST_WARNINGFLAGS += -Wno-shadow
CPPUTEST_WARNINGFLAGS += -Wno-missing-field-initializers
CPPUTEST_WARNINGFLAGS += -Wno-unused-parameter

# Dynamically generate absolute paths
MAKEFILE_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR = $(realpath $(MAKEFILE_DIR)../..)

# Unit test directory
UT_DIR = $(PROJECT_DIR)/TDD

# Src directories
SRC_DIRS += $(PROJECT_DIR)/$(PARENT_FOLDER_NAME)/$(FOLDER_NAME)
SRC_DIRS += $(PROJECT_DIR)/UTIL_DRVR/lib_teamb_handshake
SRC_DIRS += $(PROJECT_DIR)/UTIL_DRVR/common
SRC_DIRS += $(PROJECT_DIR)/APP/projects/connectivity/hal

# Include and source files for component under test
INCLUDE_DIRS += $(PROJECT_DIR)/$(PARENT_FOLDER_NAME)/$(FOLDER_NAME)
INCLUDE_DIRS += $(PROJECT_DIR)/UTIL_DRVR/lib_teamb_handshake
INCLUDE_DIRS += $(PROJECT_DIR)/UTIL_DRVR/common
INCLUDE_DIRS += $(PROJECT_DIR)/APP/projects/connectivity/hal

# Directories containing the unit tests
TEST_SRC_DIRS = $(UT_DIR)/$(FOLDER_NAME)
TEST_SRC_FILES += $(UT_DIR)/main.cpp

# Location of CppUTest (if not already set)
CPPUTEST_HOME ?= $(UT_DIR)/cpputest

# Includes CppUTest header files
INCLUDE_DIRS += $(CPPUTEST_HOME)/include

# Run MakefileWorker.mk with the variable set in this makefile
include $(CPPUTEST_HOME)/build/MakefileWorker.mk