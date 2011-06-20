
PROJECT( buildtin )
file (GLOB_RECURSE BT_AS "*.as")
#MESSAGE( " sources ${BT_AS}")

make_directory( ${CMAKE_CURRENT_BINARY_DIR}/toplevel/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/ )
make_directory( ${CMAKE_CURRENT_BINARY_DIR}/flash/geom/ )

SET( BUILTIN_AS )
LIST( APPEND BUILTIN_AS 
        "toplevel/String.as" 
#"flash/geom/Matrix.as"
#"flash/geom/Point.as"
#"flash/geom/Rectangle.as"
#"flash/geom/Transform.as" 
)


SET( BUILTIN_PNs )
FOREACH( AFILE ${BUILTIN_AS} )
    ADD_CUSTOM_COMMAND(
            OUTPUT  ${CMAKE_CURRENT_BINARY_DIR}/${AFILE}.pn
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${AFILE}
            COMMAND ${ASC} -z ${CMAKE_CURRENT_BINARY_DIR}/${AFILE}.pn -x ${CMAKE_CURRENT_SOURCE_DIR}/${AFILE} 
        )
    LIST( APPEND BUILTIN_PNs ${CMAKE_CURRENT_BINARY_DIR}/${AFILE}.pn )
ENDFOREACH( AFILE )


ADD_CUSTOM_TARGET(
    builtin.pn
    DEPENDS ${BUILTIN_PNs} ${PNLD}
    COMMAND ${PNLD} ${BUILTIN_PNs} -o ${CMAKE_SOURCE_DIR}/lib/builtin.pn
    ) 
