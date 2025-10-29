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
    autoconf \
    automake \
    libtool \
    valgrind && \
    rm -rf /var/lib/apt/lists/*

# Install cpplint and Metrix++ via pip
RUN pip install cpplint metrixpp

# Create workspace directory
WORKDIR /workspace

# Copy the entire project including scripts
COPY . /workspace
# Make the scripts executable
RUN chmod +x scripts/build/run_build.sh \
             scripts/build/run_cppcheck.sh \
             scripts/build/run_cpplint.sh \
             scripts/build/run_metrix++.sh \
             scripts/build/run_test.sh

# Download and build CppUTest tools
RUN mkdir -p tools && \
    wget https://github.com/cpputest/cpputest/archive/refs/heads/master.tar.gz -O cpputest.tar.gz && \
    tar -xzf cpputest.tar.gz && \
    mv cpputest-master tools/cpputest && \
    rm cpputest.tar.gz && \
    cd tools/cpputest && \
    autoreconf -i --force && \
    ./configure && \
    make

# Set default command to bash
CMD ["/bin/bash"]
