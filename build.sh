#!/bin/bash

if [ "$1"x = "clean"x ]
then
    if [ -d ./build ]
    then
        rm -rf ./build
    fi
    exit 0
fi

if [ ! -d ./build ]
then
    echo "mkdir -p build"
    mkdir -p build
fi

cd build && \
cmake -DCMAKE_INSTALL_PREFIX=./output .. && \
make -j && \
make install && \
cd -
