
# ProgrameNode Translator 
# Copyright 2011 mapleellpam@gmail.com.  All rights reserved.
# https://github.com/mapleelpam/programnode-translator

# Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

PROJECT( boost-prop_tree-test )

INCLUDE_DIRECTORIES(
    )

ADD_EXECUTABLE( ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/prop_tree.cpp
    )

TARGET_LINK_LIBRARIES( boost-prop_tree-test
    ${Boost_LIBRARIES}
    )

