
PROJECT( runtest-goniblergo)
#file (GLOB MULTIPLE_AS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.as")

set( MULTIPLE_AS 
./GoNiblerGo.as
./com/adobe/serialization/json/JSONToken.as
./com/adobe/serialization/json/JSONTokenizer.as
./com/adobe/serialization/json/JSON.as
./com/adobe/serialization/json/JSONParseError.as
./com/adobe/serialization/json/JSONDecoder.as
./com/adobe/serialization/json/JSONESequenceEncoder.as
./com/adobe/serialization/json/JSONEncoder.as
./com/adobe/serialization/json/JSONTokenType.as
./Person.as
)
MESSAGE( " multiple sources ${MULTIPLE_AS}")

#make_directory( ${CMAKE_CURRENT_BINARY_DIR}/toplevel/ )
#make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/ )
#make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/geom/ )

make_directory( ${CMAKE_CURRENT_BINARY_DIR}/com/adobe/serialization/json/ )

SET( MULTIPLE_PNs )
FOREACH( AFILE ${MULTIPLE_AS} )
    ADD_CUSTOM_COMMAND(
            OUTPUT  ${CMAKE_CURRENT_BINARY_DIR}/${AFILE}.pn
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${AFILE}
            COMMAND ${ASC} -z ${CMAKE_CURRENT_BINARY_DIR}/${AFILE}.pn -x ${CMAKE_CURRENT_SOURCE_DIR}/${AFILE} 
        )
    LIST( APPEND MULTIPLE_PNs ${CMAKE_CURRENT_BINARY_DIR}/${AFILE}.pn )
ENDFOREACH( AFILE )


MESSAGE( " multiple sources ${MULTIPLE_PNs}")
ADD_CUSTOM_COMMAND(
    OUTPUT  ${CMAKE_CURRENT_BINARY_DIR}/multiple.pn
    DEPENDS ${MULTIPLE_PNs} ${PNLD}
    COMMAND ${PNLD} ${MULTIPLE_PNs} -o ${CMAKE_CURRENT_BINARY_DIR}/multiple.pn
    ) 

set( PRE_MSG " include \"somthing\"") 
ADD_CUSTOM_TARGET(
    runtest-goniblergo
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/multiple.pn ${PNC}
    #COMMAND ${PNC} ${CMAKE_CURRENT_BINARY_DIR}/multiple.pn -o ${CMAKE_CURRENT_BINARY_DIR}/multiple.cpp ${LIBRARY_OUTPUT_PATH}/builtin.pn
    COMMAND ${PNC} ${MULTIPLE_PNs} -l ${CMAKE_CURRENT_SOURCE_DIR}/frt.ini -o ${CMAKE_CURRENT_BINARY_DIR}/multiple.cpp ${LIBRARY_OUTPUT_PATH}/builtin.pn
    COMMAND ${PNC} ${MULTIPLE_PNs} -l ${CMAKE_CURRENT_SOURCE_DIR}/frt.ini --predef -o ${CMAKE_CURRENT_BINARY_DIR}/go.all.h ${LIBRARY_OUTPUT_PATH}/builtin.pn
    COMMAND ${PNC} ${MULTIPLE_PNs} -l ${CMAKE_CURRENT_SOURCE_DIR}/frt.ini --declare -o ${CMAKE_CURRENT_BINARY_DIR}/go.only.h ${LIBRARY_OUTPUT_PATH}/builtin.pn
    COMMAND ${PNC} ${MULTIPLE_PNs} -l ${CMAKE_CURRENT_SOURCE_DIR}/frt.ini --define -o ${CMAKE_CURRENT_BINARY_DIR}/go.only.cpp ${LIBRARY_OUTPUT_PATH}/builtin.pn --declare --prepend_codes ${PRE_MSG}
    COMMAND g++ ${CMAKE_CURRENT_BINARY_DIR}/multiple.cpp -o ${EXECUTABLE_OUTPUT_PATH}/multiple_test
    )
