#!/bin/bash

# Exit immediately if any command fails
set -e

# Navigate to workspace root
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
WORKSPACE_DIR="$(dirname "$(dirname "$SCRIPT_DIR")")"

# Resolve full test path
TEST_DIR="$WORKSPACE_DIR/tests/mqtt"

# Clean previous build
rm -rf "$TEST_DIR/build"

echo "🔧 Building and running MQTT tests..."
cd "$TEST_DIR"
mkdir -p build
cd build
cmake ..
make

echo "=== Running Tests Normally ==="
./mqtt_tests
