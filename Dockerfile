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
 
# Copy project files into the container
COPY . /workspace

# Add Cppcheck script to container
COPY run_cppcheck.sh /usr/local/bin/run_cppcheck.sh
RUN chmod +x /usr/local/bin/run_cppcheck.sh
 
# Set default command to bash
CMD ["/bin/bash"]