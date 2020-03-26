#!/bin/bash

CURRENT_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-${CURRENT_DIR}/build}
BUILD_TYPE=${BUILD_TYPE:-Debug}
INSTALL_DIR=${INSTALL_DIR:-${BUILD_DIR}/${BUILD_TYPE}_install}

if [ "$1"x = "clean"x ]
then
    if [ -d ${BUILD_DIR} ]
    then
        rm -rf ${BUILD_DIR}
    fi
    exit 0
fi

if [ ! -d ${BUILD_DIR} ]
then
    echo "mkdir -p ${BUILD_DIR}"
    mkdir -p ${BUILD_DIR}
fi

cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -H${CURRENT_DIR} -B${BUILD_DIR} && \
cmake --build ${BUILD_DIR} -- -j && \
cmake --build ${BUILD_DIR} --target install
