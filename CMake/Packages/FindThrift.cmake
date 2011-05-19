# - Find Thrift (a cross platform RPC lib/tool)
# This module defines
#  THRIFT_VERSION, version string of ant if found
#  THRIFT_INCLUDE_DIR, where to find Thrift headers
#  THRIFT_LIB, Thrift libraries
#  THRIFT_LIBS, Thrift libraries
#  THRIFT_FOUND, If false, do not try to use ant


SET(THRIFT_COMPILER "thrift" CACHE STRING "Thrift Compiler")

exec_program(thrift ARGS -version OUTPUT_VARIABLE THRIFT_VERSION
             RETURN_VALUE THRIFT_RETURN)

find_path(THRIFT_INCLUDE_DIR Thrift.h PATHS
  /usr/local/include/thrift
  /usr/include/thrift
  /opt/local/include/thrift
)

SET(THRIFT_LIB_PATHS /usr/local/lib/ /opt/local/lib/ /usr/lib/)

find_library(THRIFT_LIB NAMES thrift PATHS ${THRIFT_LIB_PATHS})

if (THRIFT_VERSION MATCHES "^Thrift version" AND THRIFT_LIB AND THRIFT_INCLUDE_DIR)
  SET(THRIFT_FOUND TRUE)
  SET(THRIFT_LIBS ${THRIFT_LIB})
else ()
  SET(THRIFT_FOUND FALSE)
endif ()

if (THRIFT_FOUND)
  if (NOT THRIFT_FIND_QUIETLY)
    message(STATUS "Found thrift: ${THRIFT_LIBS}")
    message(STATUS "    compiler: ${THRIFT_VERSION}")
  endif ()
else ()
  message(STATUS "Thrift compiler/libraries NOT found. "
          "Thrift support will be disabled (${THRIFT_RETURN}, "
          "${THRIFT_INCLUDE_DIR}, ${THRIFT_LIB}, ${THRIFT_NB_LIB})")
endif ()

mark_as_advanced(
  THRIFT_LIB
  THRIFT_NB_LIB
  THRIFT_INCLUDE_DIR
  )
