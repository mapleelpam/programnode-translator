// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pn-translator %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// RUN: %t | FileCheck -input-file=- %s 


    function main( ) : int
    {
        printf(" %d\n", true );  // CHECK: 1
        printf(" %d\n", false );  // CHECK: 0
    }
