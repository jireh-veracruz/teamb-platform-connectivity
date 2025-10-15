#!/bin/bash

# Build the Docker image
echo "Building Docker image 'platform-builder'..."
docker build -t platform-builder .

# Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Docker build failed. Exiting."
    exit 1
fi

# Run the Docker container interactively
echo "Running Docker container..."
docker run --rm -it -v "$(pwd)":/workspace -w /workspace platform-builder /bin/bash