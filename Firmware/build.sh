#!/bin/bash
echo "Building..."
date
mkdir -p .Build
cd ./.Build
rm -rf ./Application/*

cmake \
    -DCMAKE_TOOLCHAIN_FILE=../toolchain_STM32.cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    ..

cmake --build . -- -j 8

echo "Finished"
date
cd ..
