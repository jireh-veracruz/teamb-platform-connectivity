#!/bin/bash

source "$(cd "$(dirname "$0")" && pwd)/project_script_cfg"

# Build the Docker image
echo "Building Docker image $DOCKER_IMAGE..."

# Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Docker build failed. Exiting."
    exit 1
fi

# Run the Docker container interactively
echo "Running Docker container..."
docker run --rm -it -v "$(pwd)":/workspace -w /workspace $DOCKER_IMAGE /bin/bash
