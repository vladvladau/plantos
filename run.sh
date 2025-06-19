#!/bin/bash
docker run -it --rm \
  -v "$PWD":/workspace \
  -w /workspace \
  --device=/dev/ttyUSB0 \
  espressif/idf:release-v5.4
