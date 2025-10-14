#!/bin/bash

echo "Select target to build:"
echo "1) Cortex-M4"
echo "2) Cortex-A7"
echo "3) Both"

read -p "Enter choice [1-3]: " choice

# Clean previous build
rm -rf build/CM4 build/CA7 build/ALL

case $choice in
  1)
    echo "Building Cortex-M4..."
    cmake --preset cm4
    cmake --build --preset cm4
    ;;
  2)
    echo "Building Cortex-A7..."
    cmake --preset ca7
    cmake --build --preset ca7
    ;;
  3)
    echo "Building both Cortex-M4 and Cortex-A7..."
    cmake --preset cm4
    cmake --build --preset cm4
    cmake --preset ca7
    cmake --build --preset ca7
    ;;
  *)
    echo "Invalid choice. Exiting."
    exit 1
    ;;
esac