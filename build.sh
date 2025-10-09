#!/bin/bash

# Clean previous build
rm -rf BUILD/CM4 BUILD/CA7

# Build Cortex-M4
cmake -G Ninja -B BUILD/CM4 \
  -DCMAKE_TOOLCHAIN_FILE=BSP/stm32/toolchain_stm32_cm4.cmake \
  -DTARGET_CORE=M4 \
  -S .

cmake --build BUILD/CM4

# Build Cortex-A7
cmake -G Ninja -B BUILD/CA7 \
  -DCMAKE_TOOLCHAIN_FILE=BSP/stm32/toolchain_stm32_ca7.cmake \
  -DTARGET_CORE=A7 \
  -S .

cmake --build BUILD/CA7
