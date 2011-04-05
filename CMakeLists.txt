
PROJECT( pn-translator )

#execute_process( COMMAND ${THRIFT_COMPILER} -r -o ${CMAKE_CURRENT_SOURCE_DIR} --gen cpp ${AST_THRIFT}) 

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

ADD_EXECUTABLE( pn-translator
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${AST_THRIFT_SRC} 
    )

TARGET_LINK_LIBRARIES( pn-translator
    ${THRIFT_LIBS}
    )
