


add_custom_target(runtest-normal
        DEPENDS pnc not FileCheck
        COMMAND
        EXECUTABLE_OUTPUT_PATH="${EXECUTABLE_OUTPUT_PATH}"
        LIT_EXEC_ROOT=${CMAKE_CURRENT_BINARY_DIR}
        ASC_JAR="${CMAKE_SOURCE_DIR}/lib/asc.jar"
		BUILTIN_PN="${CMAKE_SOURCE_DIR}/lib/builtin.pn"
        PATH="${EXECUTABLE_OUTPUT_PATH}:$ENV{PATH}"
        ${CMAKE_SOURCE_DIR}/project/pn-translator/test_framework/lit/lit.py
        -v
        ${CMAKE_CURRENT_SOURCE_DIR}/normal
        )

    
ADD_SUBDIRECTORY( multiple_pn )
ADD_SUBDIRECTORY( GoNiblerGo )
