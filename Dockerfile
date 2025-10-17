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
    && rm -rf /var/lib/apt/lists/*

# Install cpplint and Metrix++ via pip
RUN pip install cpplint metrixpp
 
# Create workspace directory
WORKDIR /workspace
 
# Copy the entire project including scripts
COPY . /workspace

# Make the script executable
RUN chmod +x scripts/run_cppcheck.sh \
             scripts/run_cpplint.sh \
             scripts/run_metrix++.sh

# Download and build CppUTest tools
RUN mkdir tools/ && \
    wget https://github.com/cpputest/cpputest/releases/download/latest-passing-build/cpputest-latest.tar.gz && \
    tar xf cpputest-latest.tar.gz && \
    mv cpputest-latest/ tools/cpputest/ && \
    cd tools/cpputest/ && \
    autoreconf -i --force && \
    ./configure && \
    make
 
# Set default command to bash
CMD ["/bin/bash"]