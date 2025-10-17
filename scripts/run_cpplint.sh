#!/bin/bash

# Exit immediately if any command fails
set -e

# Get the filename of the current script without the path or extension
SCRIPT_NAME=$(basename "$0" .sh)

echo "Running Cppcheck from $(pwd)"

# Define output directory
BUILD_DIR="build"
LOG_DIR="${SCRIPT_NAME#run_}"
LOG_NAME="$LOG_DIR"
LOG_EXT="log"
OUTPUT_DIR="$BUILD_DIR/$LOG_DIR"

# Check if build directory exists
if [ -d "$BUILD_DIR" ]; then
    echo "Found $BUILD_DIR directory."
    cd "$BUILD_DIR"
    mkdir -p "$LOG_DIR"
    echo "Created $LOG_DIR directory inside $BUILD_DIR folder."
    cd ..
else
    echo "Error: build directory does not exist."
    mkdir -p "$OUTPUT_DIR"
fi

# Find the next available log file number
i=1
while true; do
    LOG_FILE="${LOG_NAME}_$i.${LOG_EXT}"
    if [ ! -e "$OUTPUT_DIR/$LOG_FILE" ]; then
        break
    fi
    ((i++))
done

# Define source directory
SOURCE_DIRS=("source")

# Run cpplint on each .c and .h file
for dir in "${SOURCE_DIRS[@]}"; do
  while IFS= read -r -d '' file; do
    echo "Linting $file"
    cpplint "$file" 2>> "$OUTPUT_DIR/$LOG_FILE" || echo "cpplint failed for $file"
  done < <(find "$dir" -type f \( -name '*.c' -o -name '*.h' \) -print0)
done

echo "Cpplint analysis complete."
echo "Log saved to $OUTPUT_DIR/$LOG_FILE"
