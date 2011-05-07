


    add_custom_target(runtest-normal
#        DEPENDS ${EXECUTABLE_OUTPUT_PATH}/pn-tanslator
        DEPENDS pnc not FileCheck
		COMMAND
            EXECUTABLE_OUTPUT_PATH="${EXECUTABLE_OUTPUT_PATH}"
            LIT_EXEC_ROOT=${CMAKE_CURRENT_BINARY_DIR}
            ASC_JAR="${CMAKE_SOURCE_DIR}/lib/asc.jar"
			${CMAKE_SOURCE_DIR}/project/pn-translator/test_framework/lit/lit.py
            -v
            ${CMAKE_CURRENT_SOURCE_DIR}/normal
        )

    
