#!/bin/bash
set -e

# Print commands as they run
set -x  

# Move to the project root (one level up from scripts/)
cd "$(dirname "$0")/.."
echo "Running Cppcheck from $(pwd)"

cppcheck \
  --enable=all \
  --inconclusive \
  --quiet \
  --error-exitcode=1 \
  --suppress=missingIncludeSystem \
  -I workspace/vendors/platform-commons/modules/can \
  -I workspace/vendors/platform-commons/modules/common \
  -I workspace/vendors/platform-commons/modules/lib_teamb_handshake \
  -I workspace/vendors/platform-commons/modules/hal_comms \
  -I workspace/vendors/platform-commons/modules/logger \
  -I workspace/vendors/platform-commons/modules/xbee \
  -I workspace/vendors/platform-commons/modules/rs485 \
  -I workspace/vendors/platform-commons/modules/dummy_server \
  -I workspace/source/cfg \
  -I workspace/source/app/base \
  -I workspace/source/app/projects/connectivity/common \
  -I workspace/source/app/projects/connectivity/CA7/wifi \
  -I workspace/source/app/projects/connectivity/CA7/mqtt \
  -I workspace/source/app/projects/connectivity \
  -I workspace/source/custom/log_service \
  workspace/source/app/projects/$1 \
  workspace/source/bsp/stm32 \
