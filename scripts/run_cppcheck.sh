#!/bin/bash

# Exit immediately if any command fails
set -e

# Move to the project root (one level up from scripts/)
cd "$(dirname "$0")/.."
echo "Running Cppcheck from $(pwd)"

# Define source roots as an array
SOURCE_DIRS=("source" "vendor")

# Function to find all directories containing .h files
find_include_dirs() {
  for dir in "${SOURCE_DIRS[@]}"; do
    [ -d "$dir" ] && find "$dir" -type f -name '*.h' -exec dirname {} \;
  done | sort -u
}

# Build include arguments dynamically
INCLUDE_ARGS=()
for dir in $(find_include_dirs); do
  INCLUDE_ARGS+=("-I" "$dir")
done

# Add project root to support full-path includes
INCLUDE_ARGS+=("-I" ".")

cppcheck \
  --check-config \
  --enable=all \
  --inconclusive \
  --error-exitcode=1 \
  --suppress=missingIncludeSystem \
  "${INCLUDE_ARGS[@]}" \
  source/$1  # Checks all source files inside source directory
