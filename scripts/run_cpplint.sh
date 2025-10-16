#!/bin/bash

echo "Running Cppcheck from $(pwd)"

# Define source roots as an array
SOURCE_DIRS=(source)

# Run cpplint on each .c and .h file
for dir in "${SOURCE_DIRS[@]}"; do
  find "$dir" -name '*.c' -o -name '*.h' | while read -r file; do
    echo "Linting $file"
    cpplint "$file"
  done
done
