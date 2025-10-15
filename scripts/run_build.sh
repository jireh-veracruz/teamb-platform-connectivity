#!/bin/bash
docker run --rm \
    -v $PWD/build-output-connectivity:/build-output \
    platform-builder \
    bash -c "
    mkdir build && cd build && 
    echo "Building both Cortex-M4 and Cortex-A7..." &&
    cmake --preset cm4 &&
    cmake --build --preset cm4 &&
    cmake --preset ca7 &&
    cmake --build --preset ca7 && 
    echo 'Copying connectivity build artifacts...' && 
    find . -name '*.elf' -o -name '*.bin' -o -name '*.hex' -o -name '*.map' | xargs -I {} cp {} /build-output/ 2>/dev/null || true
    "