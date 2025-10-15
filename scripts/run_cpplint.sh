#!/bin/bash

echo "Running Cppcheck from $(pwd)"

# List of directories to check
SRC_DIRS=(
  source/app/projects/connectivity
  source/bsp/stm32
)

# Run cpplint on each .c and .h file
for dir in "${SRC_DIRS[@]}"; do
  find "$dir" -name '*.c' -o -name '*.h' | while read -r file; do
    echo "Linting $file"
    cpplint "$file"
  done
done
