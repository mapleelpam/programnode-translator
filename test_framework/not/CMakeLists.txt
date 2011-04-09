
ADD_DEFINITIONS( ${LLVM_CPPFLAGS} )
add_executable(not
  not.cpp
  )

target_link_libraries(not LLVMSystem)

target_link_libraries(not ${LLVM_ALL_LIBS})
target_link_libraries(not pthread dl )
