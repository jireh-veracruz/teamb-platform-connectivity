#!/bin/bash

echo "Running Cppcheck from $(pwd)"

# Define output directory
BUILD_DIR=build
LOG_DIR=cpplint
OUTPUT_DIR=$BUILD_DIR/$LOG_DIR

# Check if build directory exists
if [ -d $BUILD_DIR ]; then
    echo "Found $BUILD_DIR directory."
    cd $BUILD_DIR
    mkdir -p $LOG_DIR
    echo "Created $LOG_DIR directory inside $BUILD_DIR folder."
    cd ..
else
    echo "Error: build directory does not exist."
    mkdir -p $OUTPUT_DIR
fi

# Define source directory
SOURCE_DIRS=(source)

# Run cpplint on each .c and .h file
for dir in "${SOURCE_DIRS[@]}"; do
  find "$dir" -name '*.c' -o -name '*.h' | while read -r file; do
    echo "Linting $file"
    cpplint "$file" 2>> "$OUTPUT_DIR/cpplint.log"
  done
done
