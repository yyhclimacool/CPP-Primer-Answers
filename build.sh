#!/bin/bash

if [ "$1"x = "clean"x ]
then
    if [ -d ./build ]
    then
        rm -rf ./build
        rm -rf ./output
    fi
    exit 0
fi

if [ ! -d ./build ]
then
    echo "mkdir -p build"
    mkdir -p build
fi

cmake -DCMAKE_INSTALL_PREFIX=./output -H. -Bbuild && \
cmake --build build -- -j && \
cmake --build build --target install
