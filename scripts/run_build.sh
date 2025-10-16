#!/bin/bash

# Ensure we're in the workspace root directory where CMakePresets.json is located
cd /workspace

# Initialize and update submodules
git submodule update --init --recursive

# Clean and recreate build directories
rm -rf build/CM4 build/CA7
mkdir -p build/CM4 build/CA7

echo "Building both Cortex-M4 and Cortex-A7..."

# Build CM4
echo "Building CM4..."
cmake --preset cm4
cmake --build --preset cm4

# Build CA7
echo "Building CA7..."
cmake --preset ca7
cmake --build --preset ca7

# Copy build artifacts
echo 'Copying connectivity build artifacts...'
mkdir -p build-output
find . -name "*.elf" -o -name "*.bin" -o -name "*.hex" -o -name "*.map" | xargs -I {} cp {} build-output/ 2>/dev/null || true