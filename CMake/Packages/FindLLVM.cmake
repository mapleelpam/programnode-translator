# - Find llvm
# Find the native LLVM includes and library
#
#  LLVM_INCLUDE_DIR - where to find llvm.h, etc.
#  LLVM_LIBRARIES   - List of libraries when using llvm.
#  LLVM_FOUND       - True if LLVM found.

find_program(LLVM_CONFIG_EXECUTABLE NAMES llvm-config DOC "llvm-config executable")

SET( LLVM_FOUND FALSE )

if( LLVM_CONFIG_EXECUTABLE )
	SET( LLVM_FOUND TRUE FORCE)
	MESSAGE( STATUS "Found LLVM-CONFIG: ${LLVM_CONFIG_EXECUTABLE}" )
else()
	find_program(LLVM_CONFIG_EXECUTABLE NAMES llvm-config-2.7 DOC "llvm-config executable")

	if( LLVM_CONFIG_EXECUTABLE )
		SET( LLVM_FOUND TRUE FORCE)
		MESSAGE( STATUS "Found LLVM-CONFIG: ${LLVM_CONFIG_EXECUTABLE}" )
	ENDIF( LLVM_CONFIG_EXECUTABLE )
ENDIF( LLVM_CONFIG_EXECUTABLE )

IF(WIN32)
SET(LLVM_CPPFLAGS "")
SET(LLVM_LFLAGS "")
SET(LLVM_BINDIR "")
SET(LLVM_JIT_LIBS "")

SET(LLVM_ALL_LIBS
#NAMES
#	"-lLLVMAnalysis.lib -lLLVMArchive.lib -lLLVMAsmParser.lib -lLLVMAsmPrinter.lib -lLLVMBitReader.lib -lLLVMBitWriter.lib -lLLVMCodeGen.lib -lLLVMCore.lib -lLLVMExecutionEngine.lib -lLLVMInstCombine.lib -lLLVMInstrumentation.lib -lLLVMInterpreter.lib -lLLVMipa.lib -lLLVMipo.lib -lLLVMJIT.lib -lLLVMLinker.lib -lLLVMMC.lib -lLLVMMCParser.lib -lLLVMScalarOpts.lib -lLLVMSelectionDAG.lib -lLLVMSupport.lib -lLLVMSystem.lib -lLLVMTarget.lib -lLLVMTransformUtils.lib -lLLVMX86AsmParser.lib -lLLVMX86AsmPrinter.lib -lLLVMX86CodeGen.lib -lLLVMX86Disassembler.lib -lLLVMX86Info.lib")
	"LLVMAnalysis.lib LLVMArchive.lib LLVMAsmParser.lib LLVMAsmPrinter.lib LLVMBitReader.lib LLVMBitWriter.lib LLVMCodeGen.lib LLVMCore.lib LLVMExecutionEngine.lib LLVMInstCombine.lib LLVMInstrumentation.lib LLVMInterpreter.lib LLVMipa.lib LLVMipo.lib LLVMJIT.lib LLVMLinker.lib LLVMMC.lib LLVMMCParser.lib LLVMScalarOpts.lib LLVMSelectionDAG.lib LLVMSupport.lib LLVMSystem.lib LLVMTarget.lib LLVMTransformUtils.lib LLVMX86AsmParser.lib LLVMX86AsmPrinter.lib LLVMX86CodeGen.lib LLVMX86Disassembler.lib LLVMX86Info.lib"
	CACHE STRING "LLVM Libraries")
#	PATHS /usr64/lib)
SET(LLVM_VERSION "")
ELSE(WIN32)
execute_process(
	COMMAND ${LLVM_CONFIG_EXECUTABLE} --cppflags
	OUTPUT_VARIABLE LLVM_CPPFLAGS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
	COMMAND ${LLVM_CONFIG_EXECUTABLE} --ldflags
	OUTPUT_VARIABLE LLVM_LFLAGS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
	COMMAND ${LLVM_CONFIG_EXECUTABLE} --bindir
	OUTPUT_VARIABLE LLVM_BINDIR
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
	COMMAND ${LLVM_CONFIG_EXECUTABLE} --libs core jit native linker bitreader bitwriter ipo
	OUTPUT_VARIABLE LLVM_JIT_LIBS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
	COMMAND ${LLVM_CONFIG_EXECUTABLE} --libs all
	OUTPUT_VARIABLE LLVM_ALL_LIBS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
	COMMAND ${LLVM_CONFIG_EXECUTABLE} --version
	OUTPUT_VARIABLE LLVM_VERSION
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
ENDIF(WIN32)
#if( LLVM_CONFIG_EXECUTABLE )
#	message("LLVM all libs: " ${LLVM_ALL_LIBS})
#	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CPPFLAGS}" )
#ENDIF( LLVM_CONFIG_EXECUTABLE )

IF(LLVM_FOUND)
	SET( LLVM_OPT ${LLVM_BINDIR}/opt )
	MESSAGE("LLVM Found")
ELSE()
	MESSAGE("LLVM Not Found")
ENDIF()
