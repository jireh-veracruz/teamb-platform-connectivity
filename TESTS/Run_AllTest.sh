#!/bin/bash

# Save the current directory
current_dir=$(pwd)

# Directories of tests
can_dir=can
teamb_handshake_dir=lib_teamb_handshake

echo -e "\nRUNNING ALL TEST\n\n"

# First directory and command
cd $current_dir/$can_dir || { echo "Failed to enter CAN directory"; exit 1; }
# Execute make
make

# Second directory and command
cd $current_dir/$teamb_handshake_dir || { echo "Failed to enter TEAMB_HANDSHAKE directory"; exit 1; }
# Execute make
make

echo "All tasks completed."
