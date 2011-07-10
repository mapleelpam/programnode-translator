// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

    function hello( ):Void
    {
        printf(" hello ");
    }

    function main( ) : int
    {
        hello(); // CHECK: hello
    }
