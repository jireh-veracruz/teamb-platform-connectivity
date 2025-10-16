#!/bin/bash

# Exit immediately if any command fails
set -e

# Move to the project root (one level up from scripts/)
cd "$(dirname "$0")/.."
echo "Running Cppcheck from $(pwd)"

# Define output directory
BUILD_DIR=build
LOG_DIR=cppcheck
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
  source/$1 2> "$OUTPUT_DIR/cppcheck.log"

echo "Cppcheck analysis complete. Log saved to $OUTPUT_DIR/cppcheck.log"
