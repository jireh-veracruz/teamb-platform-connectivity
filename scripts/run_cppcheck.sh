#!/bin/bash

# Load project configuration
source "$(cd "$(dirname "$0")" && pwd)/project_script_cfg"

# Exit immediately if any command fails
set -e

# Get the filename of the current script without the path or extension
SCRIPT_NAME=$(basename "$0" .sh)

# Move to the project root (one level up from scripts/)
cd "$(dirname "$0")/.."
echo "Running Cppcheck from $(pwd)"

# Define output directory
LOG_DIR="${SCRIPT_NAME#run_}"
LOG_NAME="$LOG_DIR"
OUTPUT_DIR="$BUILD_DIR/$LOG_DIR"

# Ensure build and log directories exist
[ -d "$BUILD_DIR" ] || { echo "Error: build directory does not exist."; mkdir -p "$BUILD_DIR"; }
mkdir -p "$OUTPUT_DIR" && echo "Created $LOG_DIR directory inside $BUILD_DIR folder."

# Find next available log file number
for ((i=1; ; i++)); do LOG_FILE="${LOG_NAME}_$i.${LOG_EXT}"; [ ! -e "$OUTPUT_DIR/$LOG_FILE" ] && break; done

# Function to find all directories containing .h files
find_include_dirs() {
  for dir in "${INC_DIR[@]}"; do
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
  $CPPCHECK_OPTIONS \
  "${INCLUDE_ARGS[@]}" \
  $SRC_DIR/$1 2> "$OUTPUT_DIR/$LOG_FILE"

echo "Cppcheck analysis complete." 
echo "Log saved to $OUTPUT_DIR/$LOG_FILE"
