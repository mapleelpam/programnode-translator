

THRIFT_COMPILER := thrift

CFLAGS := -I/usr/local/include/thrift/ -I./gen-cpp/
CPPFLAGS := ${CFLAGS}
LIBS   := /usr/local/lib/libthrift.a


generated-objs = gen-cpp/AstDumper.o gen-cpp/SyntaxTree_constants.o gen-cpp/SyntaxTree_types.o


all:server 

clean:
	rm -f client server *.o gen-cpp/*.o

generate-thrift:
	${THRIFT_COMPILER} -r --gen cpp SyntaxTree.thrift
