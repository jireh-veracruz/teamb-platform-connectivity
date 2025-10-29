#!/bin/bash

# Load project configuration
source "$(cd "$(dirname "$0")" && pwd)/../cfg/project_script_cfg"

# Exit immediately if any command fails
set -e

# Get the filename of the current script without the path or extension
SCRIPT_NAME=$(basename "$0" .sh)

echo "Running Metrix++ from $(pwd)"

# Define output directory
LOG_DIR="${SCRIPT_NAME#run_}"
LOG_NAME="$LOG_DIR"
OUTPUT_DIR=$BUILD_DIR/$LOG_DIR

# Ensure build and log directories exist
[ -d "$BUILD_DIR" ] || { echo "Error: build directory does not exist."; mkdir -p "$BUILD_DIR"; }
mkdir -p "$OUTPUT_DIR" && echo "Created $LOG_DIR directory inside $BUILD_DIR folder."

# Find next available log file number
for ((i=1; ; i++)); do LOG_FILE="${LOG_NAME}_$i.${LOG_EXT}"; [ ! -e "$OUTPUT_DIR/$LOG_FILE" ] && break; done

# Collect all .c and .h files under $SRC_DIR/
files=()
while IFS= read -r -d $'\0' file; do
    files+=("$file")
done < <(find $SRC_DIR/ -type f \( -name "*.c" -o -name "*.h" \) -print0)

DB_FILE="$OUTPUT_DIR/metrixpp.db"

# Collect metrics
metrix++ collect \
    --db-file="$DB_FILE" \
    $METRIX_OPTIONS \
    -- "${files[@]}"

# View results
metrix++ view \
    --db-file="$DB_FILE" \
    --format txt \
    -- "${files[@]}" > $OUTPUT_DIR/$LOG_FILE

echo "Metrix++ analysis complete." 
echo "Log saved to $OUTPUT_DIR/$LOG_FILE"
