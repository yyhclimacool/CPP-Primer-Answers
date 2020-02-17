#!/bin/bash

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
