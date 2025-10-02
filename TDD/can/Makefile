# Silence makefile
SILENCE = @
# Name of component under test
# Change the name depending on the specific folder of the files to be tested.
COMPONENT_NAME=can
PARENT_FOLDER_NAME=UTIL_DRVR
FOLDER_NAME=can

# Dynamically generate absolute paths
MAKEFILE_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR = $(realpath $(MAKEFILE_DIR)../..)

# Unit test directory
UT_DIR = $(PROJECT_DIR)/TDD

# Src directories
SRC_DIRS += $(PROJECT_DIR)/$(PARENT_FOLDER_NAME)/$(FOLDER_NAME)

# Include and source files for component under test
INCLUDE_DIRS += $(PROJECT_DIR)/$(PARENT_FOLDER_NAME)/$(FOLDER_NAME)

# Directories containing the unit tests
TEST_SRC_DIRS = $(UT_DIR)/$(FOLDER_NAME)
TEST_SRC_FILES += $(UT_DIR)/main.cpp

# Location of CppUTest (if not already set)
CPPUTEST_HOME ?= $(UT_DIR)/cpputest

# Includes CppUTest header files
INCLUDE_DIRS += $(CPPUTEST_HOME)/include

# Run MakefileWorker.mk with the variable set in this makefile
include $(CPPUTEST_HOME)/build/MakefileWorker.mk