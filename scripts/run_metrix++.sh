#!/bin/bash

echo "Running Metrix++ from $(pwd)"

# Define source roots as an array
OUTPUT_DIR=build/metrix++

mkdir -p $OUTPUT_DIR

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
    -- "${files[@]}" > $OUTPUT_DIR/metrics.txt

echo "Metrix++ analysis complete. Results saved to $OUTPUT_DIR/metrics.txt."