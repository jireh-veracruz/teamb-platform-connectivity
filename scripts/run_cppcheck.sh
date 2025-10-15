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
  -I vendors/platform-commons/modules/can \
  -I vendors/platform-commons/modules/common \
  -I vendors/platform-commons/modules/lib_teamb_handshake \
  -I vendors/platform-commons/modules/hal_comms \
  -I vendors/platform-commons/modules/logger \
  -I vendors/platform-commons/modules/xbee \
  -I vendors/platform-commons/modules/rs485 \
  -I vendors/platform-commons/modules/dummy_server \
  -I source/cfg \
  -I source/app/base \
  -I source/app/projects/connectivity/common \
  -I source/app/projects/connectivity/CA7/wifi \
  -I source/app/projects/connectivity/CA7/mqtt \
  -I source/app/projects/connectivity \
  -I source/custom/log_service \
  source/app/projects/$1 \
  source/bsp/stm32 \
