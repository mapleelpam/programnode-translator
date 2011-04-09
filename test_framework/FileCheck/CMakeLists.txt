


ADD_DEFINITIONS( ${LLVM_CPPFLAGS} )

add_executable(FileCheck
  FileCheck.cpp
  )

target_link_libraries(FileCheck         ${LLVM_ALL_LIBS})
target_link_libraries(FileCheck pthread dl )
