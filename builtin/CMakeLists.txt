
PROJECT( buildtin )
file (GLOB_RECURSE BUILTIN_AS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.as")
MESSAGE( " builtin sources ${BUILTIN_AS}")

make_directory( ${CMAKE_CURRENT_BINARY_DIR}/toplevel/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/geom/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/display/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/filters/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/utils/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/events/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/text/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/net/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/system/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/ui/ )

#SET( BUILTIN_AS )
#LIST( APPEND BUILTIN_AS 
#        "toplevel/String.as" 
#        "toplevel/Boolean.as" 
#        "toplevel/Number.as" 
#        "flash/geom/Matrix.as"
#        "flash/geom/Point.as"
#        "flash/geom/Rectangle.as"
#)


SET( BUILTIN_PNs )
FOREACH( AFILE ${BUILTIN_AS} )
    ADD_CUSTOM_COMMAND(
            OUTPUT  ${CMAKE_CURRENT_BINARY_DIR}/${AFILE}.pn
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${AFILE}
            COMMAND ${ASC} -z ${CMAKE_CURRENT_BINARY_DIR}/${AFILE}.pn -x ${CMAKE_CURRENT_SOURCE_DIR}/${AFILE} 
        )
    LIST( APPEND BUILTIN_PNs ${CMAKE_CURRENT_BINARY_DIR}/${AFILE}.pn )
ENDFOREACH( AFILE )


ADD_CUSTOM_COMMAND(
    OUTPUT  ${LIBRARY_OUTPUT_PATH}/builtin.pn
    DEPENDS ${BUILTIN_PNs} ${PNLD} ${PNC}
    COMMAND ${PNLD} ${BUILTIN_PNs} -o ${CMAKE_SOURCE_DIR}/lib/builtin.pn
    ) 

ADD_CUSTOM_TARGET(
    builtin
    DEPENDS ${LIBRARY_OUTPUT_PATH}/builtin.pn
    )
