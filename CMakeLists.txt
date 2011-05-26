
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.3)

# ProgrameNode Translator 
# Copyright 2010 mapleellpam@gmail.com.  All rights reserved.
# https://github.com/mapleelpam/programnode-translator

# Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

PROJECT( pnc )

SET(CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/CMake"
    "${CMAKE_CURRENT_SOURCE_DIR}/CMake/Packages"
    )

include( Dependencies )

if( ${AST_THRIFT} )
    execute_process( COMMAND ${THRIFT_COMPILER} -r -o ${CMAKE_CURRENT_SOURCE_DIR} --gen cpp ${AST_THRIFT}) 
endif()

#ADD_CUSTOM_TARGET(cpp-thrift-update ALL echo
#    DEPENDS ${AST_THRIFT}
#    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/gen-cpp/AstDumper.h
#    COMMAND ${THRIFT_COMPILER} -r -o ${CMAKE_CURRENT_SOURCE_DIR} --gen cpp ${AST_THRIFT} 
#    )

#SET( AST_THRIFT_SRC )
#FILE(GLOB AST_THRIFT_SRC  "${CMAKE_CURRENT_SOURCE_DIR}/gen-cpp/*.cpp")


SET( AST_THRIFT_SRC gen-cpp/AstDumper.cpp gen-cpp/SyntaxTree_constants.cpp gen-cpp/SyntaxTree_types.cpp )

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/gen-cpp/
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${THRIFT_INCLUDE_DIR}
    )

ADD_EXECUTABLE( pnc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/backend/cpp/interpret/interpret.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/backend/cpp/prependdata.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/service/configservice.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/service/pass/symboltableconstructor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/as/symbol/registrable.cpp
    ${AST_THRIFT_SRC} 
    )

TARGET_LINK_LIBRARIES( pnc
    ${THRIFT_LIBS}
    ${Boost_LIBRARIES}
    )


ADD_SUBDIRECTORY( test )
ADD_SUBDIRECTORY( test_framework )
ADD_SUBDIRECTORY( builtin )


