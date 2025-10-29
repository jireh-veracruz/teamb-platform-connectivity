#!/bin/bash

# Load project configuration
source "$(cd "$(dirname "$0")" && pwd)/../cfg/project_script_cfg"

# Move to workspace root
cd /workspace

# Initialize submodules
git submodule update --init --recursive

# Define build directories
CORE_DIR_1="$BUILD_DIR/$TARGET_NAME_1"
CORE_DIR_2="$BUILD_DIR/$TARGET_NAME_2"

# Clean and recreate build directories
rm -rf "$CORE_DIR_1" "$CORE_DIR_2"
mkdir -p "$CORE_DIR_1" "$CORE_DIR_2"

echo "Building $TARGET_NAME_1 and $TARGET_NAME_2..."

# Build $TARGET_NAME_1
echo "Building $TARGET_NAME_1..."
cmake --preset $TARGET_NAME_1 && cmake --build --preset $TARGET_NAME_1

# Build $TARGET_NAME_2
echo "Building $TARGET_NAME_2..."
cmake --preset $TARGET_NAME_2 && cmake --build --preset $TARGET_NAME_2

# Copy build artifacts
echo "Copying build artifacts..."
mkdir -p "$BUILD_DIR/$IMAGES_DIR"
find "$CORE_DIR_1" "$CORE_DIR_2" -type f \( \
  -name "*.elf" -o -name "*.bin" -o -name "*.hex" -o -name "*.map" \
\) ! -path "*/CMakeFiles/*" ! -path "*/CompilerId*/*" -exec cp {} "$BUILD_DIR/$IMAGES_DIR/" \;
