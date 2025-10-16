#!/bin/bash

echo "Running Metrix++ from $(pwd)"

# Define output directory
BUILD_DIR=build
LOG_DIR=metrix++
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

# Collect all .c and .h files under source/
files=()
while IFS= read -r -d $'\0' file; do
    files+=("$file")
done < <(find source/ -type f \( -name "*.c" -o -name "*.h" \) -print0)

DB_FILE="$OUTPUT_DIR/metrixpp.db"

# Collect metrics
metrix++ collect \
    --db-file="$DB_FILE" \
    --std.code.complexity.cyclomatic \
    --std.code.lines.code \
    --std.code.lines.comments \
    --std.code.member.methods \
    --std.code.member.classes \
    --std.code.ratio.comments \
    -- "${files[@]}"

# View results
metrix++ view \
    --db-file="$DB_FILE" \
    --format txt \
    -- "${files[@]}" > $OUTPUT_DIR/metrics.log

echo "Metrix++ analysis complete. Results saved to $OUTPUT_DIR/metrics.log."
