
PROJECT( runtest-multiple )
#file (GLOB MULTIPLE_AS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.as")

set( MULTIPLE_AS p.as main.as )
MESSAGE( " multiple sources ${MULTIPLE_AS}")

#make_directory( ${CMAKE_CURRENT_BINARY_DIR}/toplevel/ )
#make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/ )
#make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/geom/ )


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

ADD_CUSTOM_TARGET(
    runtest-multiple
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/multiple.pn ${PNC}
    COMMAND ${PNC} ${CMAKE_CURRENT_BINARY_DIR}/multiple.pn -o ${CMAKE_CURRENT_BINARY_DIR}/multiple.cpp
    COMMAND g++ ${CMAKE_CURRENT_BINARY_DIR}/multiple.cpp -o ${EXECUTABLE_OUTPUT_PATH}/multiple_test
    )
