#!/bin/bash

# Exit immediately if any command fails
set -e

# Navigate to workspace root
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
WORKSPACE_DIR="$(dirname "$(dirname "$SCRIPT_DIR")")"

# Resolve full test path
TEST_DIR="$WORKSPACE_DIR/tests/mqtt"
ROOT_BUILD_DIR="$WORKSPACE_DIR/build"

# Clean previous build
rm -rf "$TEST_DIR/build"

echo "🔧 Building and running MQTT tests..."
cd "$TEST_DIR"
mkdir -p build
cd build

# Enable coverage flags
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="--coverage" -DCMAKE_C_FLAGS="--coverage" ..

make

echo "=== Running Tests Normally ==="
./mqtt_tests

echo "📊 Generating Coverage Report..."
# Generate coverage data
lcov --capture --directory . --output-file coverage.info
lcov --remove coverage.info '/usr/*' --output-file coverage.info.cleaned
genhtml coverage.info.cleaned --output-directory "$ROOT_BUILD_DIR/coverage-report"

echo "✅ Coverage report generated at: $ROOT_BUILD_DIR/coverage-report/index.html"
