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
    libnewlib-arm-none-eabi \
    && rm -rf /var/lib/apt/lists/*
 
# Create workspace directory
WORKDIR /workspace
 
# Copy project files into the container
COPY . /workspace
 
# Set default command to bash
CMD ["/bin/bash"]