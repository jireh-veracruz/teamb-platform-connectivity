# Use Ubuntu as base image
FROM ubuntu:22.04
 
# Set environment variables to avoid user interaction during package installation
ENV DEBIAN_FRONTEND=noninteractive
 
# Install required packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    git \
    wget \
    curl \
    python3 \
    python3-pip \
    gcc-arm-none-eabi \
    gcc-arm-linux-gnueabihf \
    libnewlib-arm-none-eabi \
    cppcheck \
    && rm -rf /var/lib/apt/lists/*
 
# Create workspace directory
WORKDIR /workspace
 
# Copy the entire project including scripts
COPY . /workspace

# Explicitly copy the modules folder (in case it's missed or symlinked)
COPY vendors/platform-commons/modules/ /workspace/vendors/platform-commons/modules/

# Make the script executable
RUN chmod +x scripts/run_cppcheck.sh
 
# Set default command to bash
CMD ["/bin/bash"]