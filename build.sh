#!/bin/bash

BUILD_FORLDER=build_tmp

rm -rf ${BUILD_FORLDER}
mkdir ${BUILD_FORLDER}
cd ${BUILD_FORLDER}

cmake ..
#make asc.jar pnc
make pnc
