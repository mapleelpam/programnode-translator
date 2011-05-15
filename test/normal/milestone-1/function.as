// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

    function sum( a:int, b:int ):int
    {
        return a+b;
    }

    function main( ) : int
    {
        printf(" %d ", sum(1,2)); // CHECK: 3
    }
